#include "Game.h"
#include "tile.h"
#include "text.h"
#include "input_manager.h"

Game::game_state Game::current_game_state_;

Game::Game() : scrolling_background_(LARGEUR, HAUTEUR), player_character_(Vector2f(128,352) ,1)
{

	//On place dans le contructeur ce qui permet � la game elle-m�me de fonctionner

	mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Sidescroller Shooter");  // , Style::Titlebar); / , Style::FullScreen);
	view_game_ = mainWin.getDefaultView();
	view_menu_ = mainWin.getDefaultView();

	current_map_ = 0;
	maps_[0] = "Levels\\scene_default_layout_template_23.txt";
	maps_[1] = "Levels\\scene_2.txt";
	maps_[2] = "Levels\\scene_3.txt";

	//Synchonisation coordonn�e � l'�cran!  Normalement 60 frames par secondes. � faire absolument
	mainWin.setVerticalSyncEnabled(true);
	//mainWin.setFramerateLimit(60);  //�quivalent... normalement, mais pas toujours. � utiliser si la synchonisation de l'�cran fonctionne mal.
	//https://www.sfml-dev.org/tutorials/2.0/window-window.php#controlling-the-framerate
}

int Game::testTest()
{
	return 0;
}

int Game::run()
{
	if (!init())
	{
		return EXIT_FAILURE;
	}

	while (mainWin.isOpen())
	{
		getInputs();
		update();
		draw();
	}

	return EXIT_SUCCESS;
}

bool Game::init()
{
	/*
	if(!tile::load_textures("Sprites\\.png"))
	{
		
	}
	if(!base_enemy::load_textures("Sprites\\Paranoid.png",base_enemy::texture_base_enemy_))
	{
		
	}
	if (!base_turret::load_textures("Sprites\\.png", base_turret::texture_base_turret_))
	{

	}
	if (!upgraded_turret::load_textures("Sprites\\.png", upgraded_turret::texture_upgraded_turret))
	{

	}
	if (!boss::load_textures("Sprites\\.png", boss::texture_boss_))
	{

	}
	if (!kamikaze::load_textures("Sprites\\Dove.png", kamikaze::texture_kamikaze_))
	{

	}
	*/
	if(!tile::load_textures("Sprites\\x_tile.png"))
	{
		return false;
	}

	if (!player_character::load_textures("Sprites\\Lightning.png", player_character::texture_player_character_))
	{
		return false;
	}

	if (!scrolling_background::load_textures("Sprites\\space_background\\back_sharp.jpg", "Sprites\\space_background\\plnette.png", "Sprites\\space_background\\double_planet.png", "Sprites\\space_background\\asteroids.png"))
	{
		return false;
	}
	view_current_center_ = Vector2f(LARGEUR/2, HAUTEUR/2);
	view_game_.setCenter(view_current_center_);
	view_x_pos_last_frame_ = view_current_center_.x;
	view_menu_.setCenter(Vector2f(LARGEUR / 2, HAUTEUR / 2));
	mainWin.setView(view_game_);

	player_character_.visual_adjustments();
	player_character_.set_texture();
	scrolling_background_.set_texture();

	map_.load_map(maps_[current_map_].c_str(), tiles_);
	return true;
}

void Game::getInputs()
{
	//On passe l'�v�nement en r�f�rence et celui-ci est charg� du dernier �v�nement re�u!
	while (mainWin.pollEvent(event))
	{
		input_manager::get_input_manager()->update(mainWin, event);
		//x sur la fen�tre
		if (event.type == Event::Closed)
		{
			mainWin.close();
		}
	}
}

void Game::update()
{
	//Pauses the game
	if (current_game_state_ == singleplayer && input_manager::get_input_manager()->get_esc_key())
	{
		current_game_state_ = paused;
	}
	player_character_.move(view_game_);
	if(view_game_.getCenter().x + view_game_.getSize().x/2 < map_.get_map_size().x*32)
	{
		view_game_.move(1, 0);
	}
	else
	{
		player_character_.end_of_level(true);
	}
	scrolling_background_.update(view_game_);
	scrolling_background_.move(0);
	player_character_.update();
	movable_and_tile_collision_detection(&player_character_);
}

void Game::draw()
{
	//Toujours important d'effacer l'�cran pr�c�dent
	mainWin.clear();
	mainWin.setView(view_game_);

	scrolling_background_.draw(mainWin);
	player_character_.draw(mainWin);
	for (size_t i = 0; i < tiles_.size(); i++)
	{
		mainWin.draw(tiles_[i]);
	}

	mainWin.display();

}

Game::game_state Game::get_current_game_state()
{
	return current_game_state_;
}

void Game::movable_and_tile_collision_detection(movable* movable) const
{
	movable->set_is_colliding_wall_left(false);
	movable->set_is_colliding_wall_right(false);
	movable->set_is_colliding_platform_over(false);
	movable->set_is_colliding_platform_under(false);

	auto movable_adjustment = Vector2f(0, 0);
	for (size_t j = 0; j < tiles_.size(); j++)
	{
		if (abs(movable->getPosition().x - tiles_[j].getPosition().x)  <=
			tiles_[j].getGlobalBounds().width + movable->getGlobalBounds().width
			&&
			abs(movable->getPosition().y - tiles_[j].getPosition().y) <=
			tiles_[j].getGlobalBounds().height + movable->getGlobalBounds().height)
		{
			if (movable->get_is_going_up() == true)
			{
				
				if (tiles_[j].contains(movable->get_top_left_point()) ||
					tiles_[j].contains(movable->get_top_right_point()))
				{
					if (movable->get_speed_y() < 0 && movable->get_is_colliding_platform_over_() == false)
					{
						movable_adjustment.y = movable_adjustment.y + fabs(movable->get_speed_y());
					}
					movable->set_is_colliding_platform_over(true);
				}
			}
			if (movable->get_is_going_down() == true )
			{
				if (tiles_[j].contains(movable->get_bottom_left_point()) ||
					tiles_[j].contains(movable->get_bottom_right_point()))
				{
					if (movable_adjustment.y >= 0)
					{
						movable_adjustment.y = movable_adjustment.y - movable->get_speed_y();
					}
				}
				movable->set_is_colliding_platform_under(true);
			}
			if (movable->get_is_going_left() == true && movable->get_is_colliding_wall_left_() == false)
			{
				if (tiles_[j].contains(movable->get_left_lower_point()) ||
					tiles_[j].contains(movable->get_left_upper_point()))
				{
				 if (movable_adjustment.x <= 0)
					{
						movable_adjustment.x = movable_adjustment.x + fabs(movable->get_speed_x());
					}
				}

			}
			if (movable->get_is_going_right() == true && movable->get_is_colliding_wall_right_() == false)
			{

				if (tiles_[j].contains(movable->get_right_upper_point()) ||
					tiles_[j].contains(movable->get_right_lower_point()))
				{
					movable_adjustment.x = movable_adjustment.x -(movable->get_speed_x());
					movable->set_is_colliding_wall_right(true);
				}
			}
		}
	}
	movable->adjust_movable_position(movable_adjustment);
}