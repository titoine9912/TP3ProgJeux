#pragma once
#include "movable.h"

class nuke_bonus : public movable
{
public:
	nuke_bonus();
	void update(sf::View view);
	void visual_adjustments();
	void set_texture();
	static Texture texture_nuke_bonus;
	void draw(sf::RenderWindow& main_win);
	void spawn_bonus(Vector2f position);
};