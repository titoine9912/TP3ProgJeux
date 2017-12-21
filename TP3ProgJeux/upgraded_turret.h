#pragma once
#include "enemy.h"
class upgraded_turret : public enemy
{
public:
	// Overload Constructor
	upgraded_turret(Vector2f position);
	static bool load_textures_(const char texture_path_1[], const char texture_path_2[]);
	void update(Vector2f position);
	void set_texture();
	void visual_adjustments();
	static Texture texture_upgraded_turret;
	static Texture texture_upgraded_turret_tile;
	void draw(sf::RenderWindow& main_win);
	void turret_range_check(Vector2f position_entity);
	void rotate_towards_target(Vector2f position_entity);
	bool get_triggered();

private:
	Sprite sprite_upgraded_turret_tile_;
	int size_sprite_;
	int anim_delay;
	int anim_delay_counter;
	bool triggered_;
	float trigger_range_;
	Vector2f position_;
};

