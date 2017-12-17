#pragma once
#include"projectile.h"

class bomb_launcher_projectile : public projectile
{
public:
	bomb_launcher_projectile();
	void update(sf::View view);
	void move();
	void visual_adjustments();
	void set_texture();
	void draw(sf::RenderWindow& main_win);
	static Texture texture_bomb_launcher_projectile_;

private:
	static const int fire_rate_;
};