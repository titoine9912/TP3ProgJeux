#include  "base_turret.h"

base_turret::base_turret(Vector2f position, int player_id) : enemy(position,0)
{
	//Aniation Variables
	current_anim_ = 0;
	current_frame_ = 0;
}

void base_turret::update()
{
}

void base_turret::set_texture()
{
	base_turret_sprite_.setTexture(texture_base_turret_);
	base_turret_sprite_.setTextureRect(int_rects_movable_[0][0]);
}
