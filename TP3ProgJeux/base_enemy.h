#pragma once
#include "enemy.h"
class base_enemy : public enemy
{
public:
	// Overload Constructor
	base_enemy(Vector2f position, int player_id);
	void update();
	void set_texture();

private:
	Sprite base_enemy_sprite_;
	static Texture texture_base_enemy_;

};
