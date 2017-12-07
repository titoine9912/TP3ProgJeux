#pragma once
#include "movable.h"
class projectile : public movable
{
public:
	projectile();
	void shoot(Vector2f position, Vector2f direction);


private :
	Vector2f direction_;
};