#include "entity.h"


entity::entity(Vector2f position)
{
}


void entity::update(RenderWindow& main_win)
{
}

bool entity::load_textures(const char entity_texture_path[], Texture& texture_)
{
	if(!texture_.loadFromFile(entity_texture_path))
	{
		return false;
	}
	return true;
}
