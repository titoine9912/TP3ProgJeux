#pragma once
#include "enemy.h"
class upgraded_turret : public enemy
{
public:
	// Overload Constructor
	upgraded_turret(Vector2f position, int player_id);
	void update();
	void set_texture();

private:
	Sprite upgraded_turret_sprite_;
	static Texture texture_upgraded_turret;

};

