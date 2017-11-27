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

private:
	Sprite boss_sprite_;
	static Texture texture_boss_;

};