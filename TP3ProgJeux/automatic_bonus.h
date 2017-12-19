#pragma once
#pragma once
#include "movable.h"

class automatic_bonus : public movable
{
public:
	automatic_bonus();
	void update(sf::View view);
	void visual_adjustments();
	void set_texture();
	static Texture texture_automatic_bonus;
	void draw(sf::RenderWindow& main_win);
	void spawn_bonus(Vector2f position);
};