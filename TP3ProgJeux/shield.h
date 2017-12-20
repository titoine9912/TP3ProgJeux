#pragma once
#include "movable.h"

class shield:public movable
{
public:
	shield();
	void draw(sf::RenderWindow& main_win);
	static Texture texture_base_shield_;
};