#include  "map.h"
#include <string>
#include <fstream>	
#include "game.h"
#include <vector>

map::map()
{
}


bool map::load_map(const char scene_path[], std::vector<tile>& tiles, std::vector<base_turret>& base_turrets)
{
	//Load map
	std::ifstream ifs(scene_path);
	if(ifs.is_open())
	{
		for (size_t y = 0; y < scene_height; ++y)
		{
			std::string line;
			if (getline(ifs, line))
			{
				for (size_t x = 0; x < scene_width; ++x)
				{
					map_[y][x] = line[x] - '0';
				}
			}
		}
	}
	else
	{
		return false;
	}

	//Load scene objects
	for (size_t x = 0; x < scene_width; x++)
	{
		for (size_t y = 0; y < scene_height; y++)
		{
			if (map_[y][x] == 1 || map_[y][x] == 2)
			{
				tiles.push_back(tile(Vector2f(x * Game::grid_size, y * Game::grid_size), empty));
				tiles.back().visual_adjustments();
				tiles.back().set_texture(*map_, scene_width, scene_height);
			}
			if (map_[y][x] == 2)
			{
				base_turrets.push_back(base_turret(Vector2f(x * Game::grid_size, y * Game::grid_size)));
				base_turrets.back().visual_adjustments();
				base_turrets.back().set_texture();
			}
		}
	}
}

Vector2f map::get_map_size()
{
	return Vector2f(scene_width, scene_height);
}
