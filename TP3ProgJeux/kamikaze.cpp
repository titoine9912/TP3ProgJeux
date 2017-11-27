#include  "kamikaze.h"


kamikaze::kamikaze(Vector2f position, int player_id) : enemy(position,0)
{
	//Aniation Variables
	current_anim_ = 0;
	current_frame_ = 0;
}

void kamikaze::update()
{
}

void kamikaze::set_texture()
{
	kamikaze_sprite_.setTexture(texture_kamikaze_);
	kamikaze_sprite_.setTextureRect(int_rects_movable_[0][0]);
}
