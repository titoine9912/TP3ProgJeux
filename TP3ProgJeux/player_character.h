#pragma once
#include "character.h"
class player_character : public character
{
public:
	// Overload Constructor
	 player_character(Vector2f position, int player_id);
	 void update();
	 void move(View view);
	 void visual_adjustments();
	 void set_texture();
	 static Texture texture_player_character_;
	 void draw(sf::RenderWindow& main_win);
	 float get_speed();
	 float get_base_speed();
	 void end_of_level(bool end_of_level);


private:
	bool end_of_level_;
	bool base_speed_applied_;
	int size_sprite_;
	int anim_delay;
	int anim_delay_counter;
	bool is_respawning_;
	int respawn_delay_;
	int respawn_counter_;
	
};