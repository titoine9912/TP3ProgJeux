#include "projectile.h"

projectile::projectile() : movable(Vector2f(0,0),0)
{
	
}

void projectile::shoot(Vector2f position, Vector2f direction)
{
	is_active_ = true;
	direction_ = direction;
	setPosition(position);
}
