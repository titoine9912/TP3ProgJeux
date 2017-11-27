#include "boss.h"

boss::boss(Vector2f position, int player_id) :enemy(position,0)
{
	//Aniation Variables
	current_anim_ = 0;
	current_frame_ = 0;
}

void boss::update()
{
}

void boss::set_texture()
{
	boss_sprite_.setTexture(texture_boss_);
	boss_sprite_.setTextureRect(int_rects_movable_[0][0]);
}
