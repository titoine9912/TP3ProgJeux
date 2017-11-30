#include "player_character.h"
Texture player_character::texture_player_character_;

player_character::player_character(Vector2f position, int player_id) :character(position,0), respawn_counter_(120)
{
	player_character_sprite_.setPosition(position);

	//Aniation Variables
	current_anim_ = 0;
	current_frame_ = 0;
	anim_delay = 5;
	anim_delay_counter = 0;

	//Character state variables
	is_respawning_ = false;
	respawn_delay_ = 120;
}


void player_character::update()
{
	anim_delay_counter++;
	if (anim_delay_counter >= anim_delay)
	{
		if (current_anim_ < 3)
		{
			current_anim_++;
		}
		else
		{
			current_anim_ = 0;
		}
		player_character_sprite_.setTextureRect(int_rects_movable_[0][current_anim_]);
		anim_delay_counter = 0;
	}
}

void player_character::set_texture()
{
	player_character_sprite_.setTexture(texture_player_character_);
	player_character_sprite_.setTextureRect(int_rects_movable_[0][0]);
	player_character_sprite_.setOrigin(player_character_sprite_.getGlobalBounds().width / 2 - 16, 0);
	player_character_sprite_.rotate(90);
}

void player_character::move()
{

}

void player_character::visual_adjustments()
{
	const auto nb_character_frames = 4;
	const auto nb_character_anims = 1;

	int width = texture_player_character_.getSize().x / nb_character_frames;
	const int height = texture_player_character_.getSize().y / nb_character_anims;

	int_rects_movable_ = new IntRect*[nb_character_anims];
	for (size_t i = 0; i < nb_character_anims; i++)
	{
		int_rects_movable_[i] = new IntRect[nb_character_frames];
		for (size_t j = 0; j < nb_character_frames; j++)
		{
			int_rects_movable_[i][j].left = width * j;
			int_rects_movable_[i][j].top = height * i;
			int_rects_movable_[i][j].width = width;
			int_rects_movable_[i][j].height = height;
		}
	}
}

void player_character::draw(sf::RenderWindow& main_win)
{
	main_win.draw(player_character_sprite_);
}