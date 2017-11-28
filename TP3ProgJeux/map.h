#pragma once
#include "tile.h"
#include "base_turret.h"
#include "boss.h"
#include "upgraded_turret.h"
#include "kamikaze.h"
#include "base_enemy.h"

class map
{
public:
	map();
	bool load_map(const char scene_path[], std::vector<boss>& bosses, std::vector<base_enemy> base_enemies,
		std::vector<upgraded_turret> upgraded_turrets, std::vector<base_turret> base_turrets, std::vector<kamikaze> kamikazes);

	static const int scene_width = 180;
	static const int scene_height = 33;

private:
	int map_[scene_height][scene_width];
};