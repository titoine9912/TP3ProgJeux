#pragma once
#include "projectile.h"
class automatic_projectile :public projectile
{
public:
	automatic_projectile();
	void update(sf::View view);
	void move();
	void visual_adjustments();
	void set_texture();
	void draw(sf::RenderWindow& main_win);
	static Texture texture_automatic_projectile_;
	void counter();
	void shoot(Vector2f position, Vector2f direction);

private:
	static float fire_rate_counter_automatic;
};