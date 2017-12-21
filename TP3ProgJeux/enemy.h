#pragma once
#include "character.h"

class enemy : public character
{
public:
	enemy(Vector2f position, float speed);
	int get_fire_rate_counter();
	int get_fire_rate();
	void set_counter(float coutner);
protected:
	int fire_rate_;
	int fire_rate_counter;
};