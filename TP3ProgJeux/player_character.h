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
	 void set_health(int h);
	 bool end_of_level_;
	 void set_is_active(bool active);


private:
	bool base_speed_applied_;
	int anim_delay;
	int anim_delay_counter;

};