#pragma once
#include "projectile.h"
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
	void shoot(Vector2f position, Vector2f direction);

private:
	float angle_;
	float moveX_;
	float moveY_;
};