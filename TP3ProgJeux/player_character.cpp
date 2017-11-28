#include "player_character.h"
Texture player_character::texture_player_character_;

player_character::player_character(Vector2f position, int player_id) :character(position,0), respawn_counter_(120)
{
	//Aniation Variables
	current_anim_ = 0;
	current_frame_ = 0;

	//Character state variables
	is_respawning_ = false;
	respawn_delay_ = 120;
}


void player_character::update()
{

}


void player_character::set_texture()
{
	player_character_sprite_.setTexture(texture_player_character_);
	player_character_sprite_.setTextureRect(int_rects_movable_[0][0]);
}
