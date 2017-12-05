#pragma once
#include <SFML/System/Vector2.hpp>
#include "movable.h"

class explosion : public movable
{
public:
	explosion();
	void update();
	void visual_adjustments();
	void set_texture();
	static Texture texture_explosion;
	void draw(sf::RenderWindow& main_win);
	void activate_explosion(Vector2f position);

private :
	int size_sprite_;
	int anim_delay;
	int anim_delay_counter;




};
