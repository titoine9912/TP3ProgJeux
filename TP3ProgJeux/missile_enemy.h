#pragma once
#pragma once
#include "projectile.h"
class missile_enemy : public projectile
{
public:
	missile_enemy();
	void update(sf::View view, Vector2f direction, movable* movable);
	void move();
	void visual_adjustments();
	void set_texture();
	void draw(sf::RenderWindow& main_win);
	static Texture texture_missile_enemy_;
	void shoot(Vector2f position);
	void rotate_towards_target(Vector2f direction);

private:
	float angle_;
	float moveX_;
	float moveY_;
};