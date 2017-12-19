#include "projectile.h"

projectile::projectile() : movable(Vector2f(0,0),0), damage_(1)
{
	
}

int projectile::get_damage()
{
	return damage_;
}

