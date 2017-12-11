#pragma once
#include "enemy.h"
class kamikaze : public enemy
{
public:
	// Overload Constructor
	kamikaze(Vector2f position);
	void update(Vector2f position);
	void set_texture();
	void visual_adjustments();
	static Texture texture_kamikaze_;
	void draw(sf::RenderWindow& main_win);
	void kamikaze_range_check(Vector2f position_entity);
	void rotate_towards_target();
	bool get_has_exploded();
	void set_has_exploded(bool has_exploded);
	void move();

private:

	Vector2f direction_;
	int size_sprite_;
	int anim_delay;
	int anim_delay_counter;
	bool triggered_;
	bool has_exploded_;
	float trigger_range_;
	float explosion_range_;
	float angle_;
	Vector2f base_position_;

};