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
private:

	bool init();
	void getInputs();
	void update();
	void draw();
	bool load_map();

	//Game variables
	bool character_outofbounds_left_;
	bool character_outofbounds_right_;
	Vector2f current_respawn_point_;
	Vector2f default_respawn_point_;
	map map_;
	int current_map_;
	std::string maps_[3];

	//Entity vectors
	std::vector<tile> tiles_;
	std::vector<base_turret> base_turrets_;
	std::vector<upgraded_turret> upgraded_turrets_ ;
	std::vector<base_enemy> base_enemies_;
	std::vector<boss> bosses_;
	std::vector<kamikaze> kamikazes_;
	std::vector<player_character> player_characters_;


	RenderWindow mainWin;
	View view;
	Event event;
};