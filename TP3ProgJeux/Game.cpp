#include "Game.h"
#include "tile.h"
#include "text.h"
#include "input_manager.h"

Game::game_state Game::current_game_state_;

Game::Game() : scrolling_background_(LARGEUR, HAUTEUR), player_character_(Vector2f(128,352) ,1)
{

	//On place dans le contructeur ce qui permet à la game elle-même de fonctionner

	mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Sidescroller Shooter");  // , Style::Titlebar); / , Style::FullScreen);
	view_game_ = mainWin.getDefaultView();
	view_menu_ = mainWin.getDefaultView();

	current_map_ = 0;
	maps_[0] = "Levels\\scene_default_layout_template_23.txt";
	maps_[1] = "Levels\\scene_2.txt";
	maps_[2] = "Levels\\scene_3.txt";

	//Synchonisation coordonnée à l'écran!  Normalement 60 frames par secondes. À faire absolument
	mainWin.setVerticalSyncEnabled(true);
	//mainWin.setFramerateLimit(60);  //Équivalent... normalement, mais pas toujours. À utiliser si la synchonisation de l'écran fonctionne mal.
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
	//On passe l'événement en référence et celui-ci est chargé du dernier événement reçu!
	while (mainWin.pollEvent(event))
	{
		input_manager::get_input_manager()->update(mainWin, event);
		//x sur la fenêtre
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
		player_character_.set_base_speed_applied(true);
	}
	scrolling_background_.update(view_game_);
	scrolling_background_.move(0);
	player_character_.update();

	for (size_t i = 0; i < tiles_.size(); i++)
	{
		float x = tiles_[i].getPosition().x - player_character_.getPosition().x;
		float y = tiles_[i].getPosition().y - player_character_.getPosition().y;
		float distance = sqrt((x*x)+(y*y));

		if(distance <= 32)
		{
			if(player_character_.entity_pixel_perfect_collision_detection(tiles_[i]) ==true)
			{
				int i = 0;
				
			}

		}

	}
}

void Game::draw()
{
	//Toujours important d'effacer l'écran précédent
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