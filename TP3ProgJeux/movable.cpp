#include "movable.h"
movable::movable(Vector2f position, float speed) : entity(position), is_active_(true)
{
	speed_ = speed;
	setPosition(position);
	
}

void movable::accelerate(sf::Vector2f acceleration)
{
}

void movable::move()
{
}

bool movable::get_is_active()
{
	return is_active_;
}


void movable::kill_movable()
{
	is_active_ = false;
	speed_ = 0;
}
