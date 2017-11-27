#pragma once
#include <SFML/Graphics/Sprite.hpp>

using namespace sf;

class entity : public sf::Sprite
{
public:
	// Overload Constructor
	explicit entity(Vector2f position);

	// Accessors
	bool get_is_alive() const;

	// Mutators
};
