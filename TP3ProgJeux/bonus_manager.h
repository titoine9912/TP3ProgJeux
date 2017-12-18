#pragma once
#include "bomb_launcher_bonus.h"
#include "point_bonus.h"
#include "vie_bonus.h"
#include "nuke_bonus.h"
#include "laser_bonus.h"

class bonus_manager
{

public:
	enum type_bonus
	{
		health_e,
		points_e,
		laser_e,
		bomb_e,
		nuke_e,
		automatic_e,
	};

	static bonus_manager *get_bonus_manager();
	void Release();
	void draw(sf::RenderWindow& main_win);
	void init();
	bool load_textures(
		const char bomb_launcher_bonus_path[],
		const char vie_bonus_path[],
		const char nuke_bonus_path[],
		const char point_bonus_path[],
		const char laser_bonus_path[]);
	void update(sf::View view);
	void spawn_bonus_(Vector2f position);
	bool collision(movable* movable1);
	int last_bonus;
private:
	bonus_manager();
	static bonus_manager *bonus_manager_;

	int random_bonus;
	int random_number;
	int chance_;
	
	bomb_launcher_bonus bomb_launcher_bonus_;
	point_bonus point_bonus_;
	vie_bonus vie_bonus_;
	nuke_bonus nuke_bonus_;
	laser_bonus laser_bonus_;



};
