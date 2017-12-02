#include  "tile.h"
Texture tile::texture_;


tile::tile(Vector2f position, tile_type tile): entity(position)
{
	position_ = Vector2f(position.x / 32, position.y / 32);
	tile_type_ = tile;
	setPosition(Vector2f(position));
}

bool tile::load_textures(const char texture_path[])
{
	if (!texture_.loadFromFile(texture_path)) {
		return false;
	}
	return true;
}

void tile::visual_adjustments()
{
	//Même logique, variables a changer

	/*
	const auto nb_of_rock_frames = 16;

	const int width = texture_.getSize().x / nb_of_rock_frames;
	const int height = texture_.getSize().y;
	int_rects_tiles_ = new IntRect[nb_of_rock_frames];
	for (size_t i = 0; i < nb_of_rock_frames; i++)
	{
		int_rects_tiles_[i].left = width * i;
		int_rects_tiles_[i].top = 0;
		int_rects_tiles_[i].width = width;
		int_rects_tiles_[i].height = height;
	}
	*/
}

void tile::set_texture(int* map, int scene_width, int scene_height)
{
	setTexture(texture_);
}


tile_type tile::get_tile_type() const
{
	return tile_type_;
}

