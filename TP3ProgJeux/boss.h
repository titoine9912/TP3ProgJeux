#pragma once
#pragma once
#include "enemy.h"
class boss : public enemy
{
public:
	// Overload Constructor
	boss(Vector2f position, int player_id);
	void update();
	void set_texture();
	static Texture texture_boss_;

private:
	Sprite boss_sprite_;

};