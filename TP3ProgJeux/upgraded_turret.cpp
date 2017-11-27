#include "upgraded_turret.h"

upgraded_turret::upgraded_turret(Vector2f position, int player_id) : enemy(position,0)
{
	//Aniation Variables
	current_anim_ = 0;
	current_frame_ = 0;
}

void upgraded_turret::update()
{
}

void upgraded_turret::set_texture()
{
	upgraded_turret_sprite_.setTexture(texture_upgraded_turret);
	upgraded_turret_sprite_.setTextureRect(int_rects_movable_[0][0]);
}
