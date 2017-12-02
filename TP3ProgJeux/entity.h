#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include  <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "bitmask_manager.h"
using namespace sf;

class entity : public sf::Sprite
{
public:
	// Overload Constructor
	explicit entity(Vector2f position);

	// Accessors
   
	// Mutators
	void update(RenderWindow& main_win);
	static bool load_textures(const char entity_texture_path[] , Texture& texture_);
	bool entity_pixel_perfect_collision_detection(entity& autre_entity);
protected:
	BitmaskManager bitmasks;

	


};
