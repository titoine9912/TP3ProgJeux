#pragma once
#include "enemy.h"
class kamikaze : public enemy
{
public:
	// Overload Constructor
	kamikaze(Vector2f position, int player_id);
	void update();
	void set_texture();

private:
	Sprite kamikaze_sprite_;
	static Texture texture_kamikaze_;

};