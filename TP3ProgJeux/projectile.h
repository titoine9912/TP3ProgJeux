#pragma once
#include "movable.h"
class projectile : public movable
{
public:
	projectile();

	

protected :
	float fire_rate_;
	Vector2f direction_;
	bool hero_projectile_;
};