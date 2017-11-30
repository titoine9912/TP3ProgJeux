#pragma once
#include "character.h"
class player_character : public character
{
public:
	// Overload Constructor
	 player_character(Vector2f position, int player_id);
	 void update();
	 void move();
	 void visual_adjustments();
	 void set_texture();
	 static Texture texture_player_character_;
	 void draw(sf::RenderWindow& main_win);

private:
	int anim_delay;
	int anim_delay_counter;
	bool is_respawning_;
	int respawn_delay_;
	int respawn_counter_;
	Sprite player_character_sprite_;
};