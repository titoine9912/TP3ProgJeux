#pragma once
#include "enemy.h"
#include "observer.h"
class kamikaze : public observer
{
public:
	// Overload Constructor
	kamikaze(Vector2f position);
	void update(Vector2f position);
	void set_texture();
	void visual_adjustments();
	static Texture texture_kamikaze_;
	static int points_kamikaze;
	void draw(sf::RenderWindow& main_win);
	void kamikaze_range_check(Vector2f position_entity);
	void rotate_towards_target();
	void move();
	void notify();

private:
	
	Vector2f direction_;
	int size_sprite_;
	int anim_delay;
	int anim_delay_counter;
	bool triggered_;
	float trigger_range_;
	float explosion_range_;
	float angle_;
	Vector2f base_position_;

};