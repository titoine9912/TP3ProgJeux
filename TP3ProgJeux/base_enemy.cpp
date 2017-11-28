#include "base_enemy.h"
Texture base_enemy::texture_base_enemy_;
base_enemy::base_enemy(Vector2f position, int player_id) : enemy(position,0)
{
	//Aniation Variables
	current_anim_ = 0;
	current_frame_ = 0;
}

void base_enemy::update()
{
}

void base_enemy::set_texture()
{
	base_enemy_sprite_.setTexture(texture_base_enemy_);
	base_enemy_sprite_.setTextureRect(int_rects_movable_[0][0]);
}
