#pragma once
#include "enemy.h"

class base_turret : public enemy
{
public:
	// Overload Constructor
	base_turret(Vector2f position, int player_id);
	void update();
	void set_texture();
	static Texture texture_base_turret_;

private:
	Sprite base_turret_sprite_;
};