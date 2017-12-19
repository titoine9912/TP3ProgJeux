#pragma once
#include "movable.h"
class projectile : public movable
{
public:
	projectile();

	int get_damage();

protected :
	float fire_rate_;
	Vector2f direction_;
	bool hero_projectile_;
	int damage_;
};