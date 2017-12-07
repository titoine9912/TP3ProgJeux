#pragma once
#include "projectile.h"
class base_projectile : public projectile
{
public:
	base_projectile();
	void update();
	void move();
	void visual_adjustments();
	void set_texture();
	void draw(sf::RenderWindow& main_win);
	static Texture texture_base_projectile_;

private:
	static const int fire_rate_;

};