#pragma once
#include "movable.h"

class bomb_launcher_bonus : public movable
{
public :
	bomb_launcher_bonus();
	void update(sf::View view);
	void visual_adjustments();
	void set_texture();
	static Texture texture_bomb_launcher_bonus;
	void draw(sf::RenderWindow& main_win);
	void spawn_bonus(Vector2f position);

};