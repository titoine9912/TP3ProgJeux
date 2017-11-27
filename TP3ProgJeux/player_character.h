#pragma once
#include "character.h"
class player_character : public character
{
public:
	// Overload Constructor
	 player_character(Vector2f position, int player_id);
	 void update();
	 void set_texture();

private:
	bool is_respawning_;
	int respawn_delay_;
	int respawn_counter_;
	Sprite player_character_sprite_;
	static Texture texture_player_character_;

};