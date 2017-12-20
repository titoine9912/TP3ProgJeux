#pragma once
#include "projectile.h"
//#include "enemy.h"
class base_projectile_enemy : public projectile
{
public:
	base_projectile_enemy();
	void update(sf::View view);
	void move();
	void visual_adjustments();
	void set_texture();
	void draw(sf::RenderWindow& main_win);
	static Texture texture_base_projectile_enemy_;
	void counter();
	void shoot(Vector2f position, Vector2f direction);

private:
	static float fire_rate_counter_enemy_;
	float angle_;
};