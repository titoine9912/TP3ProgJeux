#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "map.h"
#include "player_character.h"
#include "base_enemy.h"
#include "base_turret.h"
#include "upgraded_turret.h"
#include "kamikaze.h"
#include "boss.h"
#include "scrolling_background.h"
#include "explosion.h"
#include "liste.hpp"
#include "file.hpp"
#include "projectile.h"
#include "base_projectile.h"
#include "bomb_launcher_projectile.h"
#include "laser_projectile.h"
#include "automatic_projectile.h"
#include "bonus_manager.h"

//test

using namespace sf;

class Game
{
public:
	enum game_state
	{
		victory_screen,
		defeat_screen,
		exiting,
		paused,
		main_menu,
		singleplayer,
	};

	Game();
	int run();
	int testTest();

	static const int grid_size = 32;
	static const int LARGEUR = 1280;
	static const int HAUTEUR = 720;
	static game_state get_current_game_state();
	static int get_current_points();
private:
	bool has_shot_bomb_projectile_ = false;
	bool has_shot_laser_projectile_ = false;
	bool has_shot_automatic_projectile_up_ = false;
	bool has_shot_automatic_projectile_down_ = false;
	bool init();
	void getInputs();
	void update();
	void draw();
	bool load_map();
	void movable_and_tile_collision_detection(movable*  movable) const;
	void Release();
	void player_character_actions();
	void enemy_actions();
	void projectile_and_movable_collision(movable*  movable);

	//Game variables
	bool character_outofbounds_left_;
	bool character_outofbounds_right_;
	bool game_has_started_;
	bool load_new_level_;
	Vector2f current_respawn_point_;
	Vector2f default_respawn_point_;
	map map_;
	int current_map_;
	std::string maps_[3];
	static int points_;

	//Entity vectors and elements
	std::vector<tile> tiles_;
	std::vector<base_turret> base_turrets_;
	std::vector<upgraded_turret> upgraded_turrets_ ;
	std::vector<base_enemy> base_enemies_;
	std::vector<boss> bosses_;
	std::vector<kamikaze> kamikazes_;
	explosion explosion_[15];
	Liste<base_projectile> liste_projectiles_base_;
	Liste<bomb_launcher_projectile> liste_bomb_launcher_projectile_;
	Liste<laser_projectile> liste_laser_projectile_;
	Liste<automatic_projectile> liste_automatic_projectile_up_;
	Liste<automatic_projectile> liste_automatic_projectile_down_;
	File<enemy> liste_ennemy_;

	player_character player_character_;
	scrolling_background scrolling_background_;
	
	static game_state current_game_state_;
	View view_game_;
	View view_menu_;
	Vector2f view_current_center_;

	RenderWindow mainWin;
	Event event;
};