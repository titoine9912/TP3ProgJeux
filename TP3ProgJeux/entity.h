#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include  <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "bitmask_manager.h"
using namespace sf;

class entity : public sf::Sprite
{
public:
	// Overload Constructor
	explicit entity(Vector2f position);

	// Accessors
   
	// Mutators
	void update(RenderWindow& main_win);
	static bool load_textures(const char entity_texture_path[] , Texture& texture_);
	bool entity_pixel_perfect_collision_detection(entity& autre_entity);
	bool contains(Vector2f point) const;
	void set_health(int health);
	int get_health();
	void health_check();
protected:

	BitmaskManager bitmasks;
	int size_sprite_;
	int anim_delay;
	int anim_delay_counter;
	int health_;
	bool is_active_;

	Vector2f top_left_point_;
	Vector2f top_right_point_;
	Vector2f right_upper_point_;
	Vector2f right_lower_point_;
	Vector2f bottom_left_point_;
	Vector2f bottom_right_point_;
	Vector2f left_upper_point_;
	Vector2f left_lower_point_;

	//Animation Variables
	int current_frame_;
	int current_anim_;
	


};
