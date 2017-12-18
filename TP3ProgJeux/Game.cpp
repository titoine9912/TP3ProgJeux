#include "Game.h"
#include "tile.h"
#include "text.h"
#include "input_manager.h"
#include "menu_controller.h"

Game::game_state Game::current_game_state_;

Game::Game() : scrolling_background_(LARGEUR, HAUTEUR), player_character_(Vector2f(128,352) ,1) , game_has_started_(false), load_new_level_(false), default_respawn_point_(Vector2f(128, 352)) , points_(0)
{

	//On place dans le contructeur ce qui permet à la game elle-même de fonctionner

	mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Sidescroller Shooter");  // , Style::Titlebar); / , Style::FullScreen);
	view_game_ = mainWin.getDefaultView();
	view_menu_ = mainWin.getDefaultView();

	current_map_ = 0;
	current_game_state_ = main_menu;
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
	if (!boss::load_textures("Sprites\\.png", boss::texture_boss_))
	{

	}
	*/
	if (!text::init()) // Initialize font loading for interface tools.
	{
		return false;
	}

	if (!bonus_manager::get_bonus_manager()->load_textures("Sprites\\bomb_bonus_.png","Sprites\\health_bonus_.png","Sprites\\pipe.png","Sprites\\points_bonus_.png","Sprites\\laser_bonus_.png" ))
	{
		return false;
	}
	if(!explosion::load_textures("Sprites\\explosion.png", explosion::texture_explosion))
	{
		return false;
	}

	if(!tile::load_textures("Sprites\\x_tile.png"))
	{
		return false;
	}

	if (!player_character::load_textures("Sprites\\Lightning.png", player_character::texture_player_character_))
	{
		return false;
	}

	if (!scrolling_background::load_textures("Sprites\\space_background\\back_sharp.jpg", "Sprites\\space_background\\plnette.png", "Sprites\\space_background\\double_planet.png", "Sprites\\space_background\\asteroids.png" ))
	{
		return false;
	}

	if (!base_turret::load_textures_("Sprites\\base_turret_.png","Sprites\\turret_tile.png"))
	{
		return false;
	}
	if (!upgraded_turret::load_textures_("Sprites\\upgraded_turret.png","Sprites\\turret_tile.png" ))
	{
		return false;
	}
	if (!kamikaze::load_textures("Sprites\\Dove.png", kamikaze::texture_kamikaze_))
	{
		return false;
	}
	if (!base_projectile::load_textures("Sprites\\base_projectile_.png", base_projectile::texture_base_projectile_))
	{
		return false;
	}
	if (!bomb_launcher_projectile::load_textures("Sprites\\missile.png", bomb_launcher_projectile::texture_bomb_launcher_projectile_))
	{
		return false;
	}
	if (!laser_projectile::load_textures("Sprites\\laser_green_.png", laser_projectile::texture_laser_projectile_))
	{
		return false;
	}
	if (!automatic_projectile::load_textures("Sprites\\laser_red_.png", automatic_projectile::texture_automatic_projectile_))
	{
		return false;
	}


	
	for (int i = 0; i < 100; ++i)
	{
		liste_projectiles_base_.push_front(base_projectile::base_projectile());
		liste_projectiles_base_.front().visual_adjustments();
		liste_projectiles_base_.front().setTexture(base_projectile::texture_base_projectile_);
	}

	//la boucle ci-dessous sera a enlever plus tard, ce n'est que pour tester si les projectiles speciaux fonctionnent


	for (int i = 0; i < 100; ++i)
	{
		liste_automatic_projectile_up_.push_front(automatic_projectile::automatic_projectile());
		liste_automatic_projectile_up_.front().visual_adjustments();
		liste_automatic_projectile_up_.front().setTexture(automatic_projectile::texture_automatic_projectile_);
	}

	for (int i = 0; i < 100; ++i)
	{
		liste_automatic_projectile_down_.push_front(automatic_projectile::automatic_projectile());
		liste_automatic_projectile_down_.front().visual_adjustments();
		liste_automatic_projectile_down_.front().setTexture(automatic_projectile::texture_automatic_projectile_);
	}
	


	view_current_center_ = Vector2f(LARGEUR/2, HAUTEUR/2);
	view_game_.setCenter(view_current_center_);
	view_menu_.setCenter(Vector2f(LARGEUR / 2, HAUTEUR / 2));
	mainWin.setView(view_game_);

	player_character_.visual_adjustments();
	player_character_.set_texture();
	scrolling_background_.set_texture();
	for(int i =0; i<15;++i)
	{
		explosion_[i].visual_adjustments();
		explosion_[i].set_texture();
	}



	map_.load_map(maps_[current_map_].c_str(), tiles_, base_turrets_, upgraded_turrets_, kamikazes_);
	bonus_manager::get_bonus_manager()->init();

	return true;
}

void Game::getInputs()
{
	//On passe l'événement en référence et celui-ci est chargé du dernier événement reçu!
	while (mainWin.pollEvent(event))
	{
		input_manager::get_input_manager()->update(mainWin, event);
		//x sur la fenêtre
		if (event.type == Event::Closed || current_game_state_ == exiting)
		{
			menu_controller::get_menu_controller()->release();
			current_game_state_ = exiting;
			Release();
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
	//Update Singleplayer
	if (current_game_state_ == singleplayer)
	{
		game_has_started_ = true;

		//Supprime l'instance de menu si il y en a une
		menu_controller::get_menu_controller()->release();

		//Update les bonus
		bonus_manager::get_bonus_manager()->update(view_game_);

		mainWin.setView(view_game_);
		player_character_.move(view_game_);


		if (view_game_.getCenter().x + view_game_.getSize().x / 2 < map_.get_map_size().x * 32)
		{
			view_game_.move(1, 0);
		}
		else
		{
			player_character_.end_of_level(true);
		}


		
		for (auto i = liste_projectiles_base_.begin(); i != liste_projectiles_base_.end(); ++i)
		{
			if (i == liste_projectiles_base_.begin())
			{
				(*i).counter();
			}
			if (i->get_is_active())
			{
				(*i).update(view_game_);
			}
			else if (input_manager::get_input_manager()->get_space_key_is_pressed() == true)
			{
				(*i).shoot(player_character_.getPosition(), Vector2f(0, 0));
			}
		}

		if (liste_bomb_launcher_projectile_.size() > 0)
		{
			for (auto i = liste_bomb_launcher_projectile_.begin(); i != liste_bomb_launcher_projectile_.end(); ++i)
			{
				if (i == liste_bomb_launcher_projectile_.begin())
				{
					(*i).counter();
				}
				if (i->get_is_active() == true)
				{
					(*i).update(view_game_);
				}
				else if (input_manager::get_input_manager()->get_f_key_is_pressed() == true)
				{
					(*i).shoot(player_character_.getPosition(), Vector2f(0, 0));
					has_shot_bomb_projectile_ = true;
				}
			}
		}
		//On retire un projectile de bomb lorsquil y a un tir
		if (has_shot_bomb_projectile_ == true)
		{
			if (liste_bomb_launcher_projectile_.begin()->get_is_active() == false)
			{
				liste_bomb_launcher_projectile_.pop_back();
				has_shot_bomb_projectile_ = false;
			}

		}

		if (liste_laser_projectile_.size() > 0)
		{
			for (auto i = liste_laser_projectile_.begin(); i != liste_laser_projectile_.end(); ++i)
			{
				if (i == liste_laser_projectile_.begin())
				{
					(*i).counter();
				}
				if (i->get_is_active() == true)
				{
					(*i).update(view_game_);
				}
				else if (input_manager::get_input_manager()->get_g_key_is_pressed() == true)
				{
					(*i).shoot(player_character_.getPosition(), Vector2f(0, 0));
					has_shot_laser_projectile_ = true;
				}
			}
		}
		//On retire un projectile laser lorsquil y a un tir 
		if (has_shot_laser_projectile_ == true)
		{
			if (liste_laser_projectile_.begin()->get_is_active() == false)
			{
				liste_laser_projectile_.pop_back();
				has_shot_laser_projectile_ = false;
			}
		}

		if (liste_automatic_projectile_up_.size() > 0)
		{
			for (auto i = liste_automatic_projectile_up_.begin(); i != liste_automatic_projectile_up_.end(); ++i)
			{
				if (i == liste_automatic_projectile_up_.begin())
				{
					(*i).counter();
				}
				if (i->get_is_active() == true)
				{
					(*i).update(view_game_);
				}
				else if (input_manager::get_input_manager()->get_h_key_is_pressed() == true)
				{
					(*i).shoot(player_character_.getPosition(), Vector2f(0, 0));
					has_shot_automatic_projectile_up_ = true;
				}
			}			
		}
		//On retire un projectile laser lorsquil y a un tir 
		if (has_shot_automatic_projectile_up_ == true)
		{
			if (liste_automatic_projectile_up_.begin()->get_is_active() == false)
			{
				liste_automatic_projectile_up_.pop_back();
				has_shot_automatic_projectile_up_ = false;
			}
		}

		if (liste_automatic_projectile_down_.size() > 0)
		{
			for (auto i = liste_automatic_projectile_down_.begin(); i != liste_automatic_projectile_down_.end(); ++i)
			{
				if (i == liste_automatic_projectile_down_.begin())
				{
					(*i).counter();
				}
				if (i->get_is_active() == true)
				{
					(*i).update(view_game_);
				}
				else if (input_manager::get_input_manager()->get_j_key_is_pressed() == true)
				{
					(*i).shoot(Vector2f(player_character_.getPosition().x, player_character_.getPosition().y + 20), Vector2f(0, 0));
					has_shot_automatic_projectile_down_ = true;
				}
			}
		}

		if (has_shot_automatic_projectile_down_ == true)
		{
			if (liste_automatic_projectile_down_.begin()->get_is_active() == false)
			{
				liste_automatic_projectile_down_.pop_back();
				has_shot_automatic_projectile_down_ = false;
			}
		}

		/*
		if (liste_automatic_projectile_down_.size() > 0 && liste_automatic_projectile_up_.size()>0)
		{
			for (auto i = liste_automatic_projectile_down_.begin(); i != liste_automatic_projectile_down_.end(); ++i)
			{
				for (auto j = liste_automatic_projectile_up_.begin(); j != liste_automatic_projectile_up_.end(); ++j)
				{

					if (i == liste_automatic_projectile_down_.begin() && j==liste_automatic_projectile_up_.begin())
					{
						(*i).counter();
						(*j).counter();
					}
					if (i->get_is_active() == true && j->get_is_active()==true)
					{
						(*i).update(view_game_);
						(*j).update(view_game_);
					}
					else if (input_manager::get_input_manager()->get_j_and_h_are_pressed() == true)
					{
						(*i).shoot(Vector2f(player_character_.getPosition().x, player_character_.getPosition().y + 32), Vector2f(0, 0));
						(*j).shoot(player_character_.getPosition(), Vector2f(0, 0));
						has_shot_automatic_projectile_down_ = true;
						has_shot_automatic_projectile_up_ = true;
					}
				}
			}
		}
		*/

		for (size_t i = 0; i < base_turrets_.size(); i++)
		{
			base_turrets_[i].update(player_character_.getPosition());
		}
		for (size_t i = 0; i < upgraded_turrets_.size(); i++)
		{
			upgraded_turrets_[i].update(player_character_.getPosition());
		}
		for (size_t i = 0; i < kamikazes_.size(); i++)
		{
			kamikazes_[i].update(player_character_.getPosition());
			movable_and_tile_collision_detection(&kamikazes_[i]);
			if (kamikazes_[i].get_is_active() == false)
			{
				if (kamikazes_[i].get_has_exploded() == false)
				{
					bonus_manager::get_bonus_manager()->spawn_bonus_(kamikazes_[i].getPosition());
					for (int j = 0; j < 15; ++j)
					{
						if (explosion_[j].get_is_active() == false)
						{
							explosion_[j].activate_explosion(kamikazes_[i].getPosition());
							kamikazes_[i].set_has_exploded(true);
							break;
						}
					}
				}
			}
		}

		for (int i = 0; i < 15; ++i)
		{
			explosion_[i].update();
		}


		scrolling_background_.update(view_game_);
		scrolling_background_.move(0);
		player_character_.update();
		movable_and_tile_collision_detection(&player_character_);

		if (bonus_manager::get_bonus_manager()->collision(&player_character_) == true)
		{
			//Le joueur obtient un bonus de type vie
			if (bonus_manager::get_bonus_manager()->last_bonus == 0)
			{
				player_character_.set_health(player_character_.get_health() + 5);
			}
			//Le joueur obtient un bonus de type points
			else if (bonus_manager::get_bonus_manager()->last_bonus == 1)
			{
				points_ + 100;
			}
			//Le joueur obtient un bonus de type laser
			else if (bonus_manager::get_bonus_manager()->last_bonus == 2)
			{
				for (int i = 0; i < 3; ++i)
				{
					liste_laser_projectile_.push_front(laser_projectile::laser_projectile());
					liste_laser_projectile_.front().visual_adjustments();
					liste_laser_projectile_.front().setTexture(laser_projectile::texture_laser_projectile_);
				}	
			}
			//Le joueur obtient un bonus de type bombe_launcher
			else if (bonus_manager::get_bonus_manager()->last_bonus == 3)
			{
				for (int i = 0; i < 3; ++i)
				{
					liste_bomb_launcher_projectile_.push_front(bomb_launcher_projectile::bomb_launcher_projectile());
					liste_bomb_launcher_projectile_.front().visual_adjustments();
					liste_bomb_launcher_projectile_.front().setTexture(bomb_launcher_projectile::texture_bomb_launcher_projectile_);
				}
			}
			//Le joueur obtient un bonus de type nuke
			else if (bonus_manager::get_bonus_manager()->last_bonus == 4)
			{

			}
		}
		points_++;
	}
	else if (current_game_state_ != exiting)
	{
		if (current_game_state_ == main_menu && game_has_started_)
		{
			load_new_level_ = true;
		}
		current_game_state_ = menu_controller::get_menu_controller()->update();
	}

	if (load_new_level_ == true)
	{
		Release();
		tiles_.clear();
		base_turrets_.clear();
		upgraded_turrets_.clear();
		kamikazes_.clear();
		menu_controller::get_menu_controller()->release();
		player_character_.setPosition(default_respawn_point_);
		map_.load_map(maps_[current_map_].c_str(), tiles_, base_turrets_, upgraded_turrets_, kamikazes_);
		view_game_.setCenter(view_current_center_);
		load_new_level_ = false;
	}

}

void Game::draw()
{
	//Toujours important d'effacer l'écran précédent
	if (current_game_state_ != exiting)
	{

		mainWin.clear();
		if (current_game_state_ == singleplayer)
		{
			mainWin.setView(view_game_);

			scrolling_background_.draw(mainWin);
			bonus_manager::get_bonus_manager()->draw(mainWin);
			player_character_.draw(mainWin);
			for (size_t i = 0; i < tiles_.size(); i++)
			{
				mainWin.draw(tiles_[i]);
			}
			for (size_t i = 0; i < base_turrets_.size(); i++)
			{
				base_turrets_[i].draw(mainWin);
			}

			for (size_t i = 0; i < upgraded_turrets_.size(); i++)
			{
				upgraded_turrets_[i].draw(mainWin);
			}

			for (size_t i = 0; i < kamikazes_.size(); i++)
			{
				kamikazes_[i].draw(mainWin);
			}

			for (int i = 0; i < 15; ++i)
			{
				explosion_[i].draw(mainWin);
			}

			
			for (auto i = liste_projectiles_base_.begin(); i != liste_projectiles_base_.end(); ++i)
			{
				if (i->get_is_active())
				{
					(*i).draw(mainWin);
				}
			}


			for (auto i = liste_bomb_launcher_projectile_.begin(); i != liste_bomb_launcher_projectile_.end(); ++i)
			{
				if (i->get_is_active())
				{
					(*i).draw(mainWin);
				}
			}

			for (auto i = liste_laser_projectile_.begin(); i != liste_laser_projectile_.end(); ++i)
			{
				if (i->get_is_active())
				{
					(*i).draw(mainWin);
				}
			}

			for (auto i = liste_automatic_projectile_up_.begin(); i != liste_automatic_projectile_up_.end(); ++i)
			{
				if (i->get_is_active())
				{
					(*i).draw(mainWin);
				}
			}

			for (auto i = liste_automatic_projectile_down_.begin(); i != liste_automatic_projectile_down_.end(); ++i)
			{
				if (i->get_is_active())
				{
					(*i).draw(mainWin);
				}
			}
			
		}
		else
		{
			mainWin.setView(view_menu_);
			menu_controller::get_menu_controller()->draw(mainWin);
		}

		mainWin.display();
	}

}

Game::game_state Game::get_current_game_state()
{
	return current_game_state_;
}

void Game::movable_and_tile_collision_detection(movable* movable ) const
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

					if((movable->get_is_going_up() ==true || movable->get_is_going_down() == true) && movable->get_base_speed() >0)
					{
						movable_adjustment.x = movable_adjustment.x - (movable->get_speed_x()+1);
					}
					else
					{
						movable_adjustment.x = movable_adjustment.x - (movable->get_speed_x());
					}
					movable->set_is_colliding_wall_right(true);
				}
			}
		}
	}
	movable->adjust_movable_position(movable_adjustment);
}


void Game::Release()
{
	for (size_t i = 0; i < base_turrets_.size(); i++)
	{
		base_turrets_[i].Release();
	}

	for (size_t i = 0; i < upgraded_turrets_.size(); i++)
	{
		upgraded_turrets_[i].Release();
	}

	for (size_t i = 0; i < kamikazes_.size(); i++)
	{
		kamikazes_[i].Release();
	}

	for (size_t i = 0; i < tiles_.size(); i++)
	{
		tiles_[i].Release();
	}

	if (current_game_state_ == exiting)
	{
		player_character_.Release();
		for (int i = 0; i<15; ++i)
		{
			explosion_[i].Release();
			//bonus_manager::get_bonus_manager()->Release();
		}

		for (auto i = liste_laser_projectile_.begin(); i != liste_laser_projectile_.end(); ++i)
		{
			(*i).Release();
		}

		for (auto i = liste_bomb_launcher_projectile_.begin(); i != liste_bomb_launcher_projectile_.end(); ++i)
		{
			(*i).Release();
		}

		for (auto i = liste_projectiles_base_.begin(); i != liste_projectiles_base_.end(); ++i)
		{
			(*i).Release();
		}

		for (auto i = liste_automatic_projectile_up_.begin(); i != liste_automatic_projectile_up_.end(); ++i)
		{
			(*i).Release();
		}

		for (auto i = liste_automatic_projectile_down_.begin(); i != liste_automatic_projectile_down_.end(); ++i)
		{
			(*i).Release();
		}
	}
}
