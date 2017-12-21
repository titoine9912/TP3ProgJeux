#include "enemy.h"

enemy::enemy(Vector2f position, float speed) : character(position, speed)
{

}

int enemy::get_fire_rate()
{
	return fire_rate_;
}

int enemy::get_fire_rate_counter()
{
	return fire_rate_counter;
}

void enemy::set_counter(float counter)
{
	fire_rate_counter = counter;
}