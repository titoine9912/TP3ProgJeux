#include  "kamikaze.h"
#include <iostream>
#include <type_traits>
Texture kamikaze::texture_kamikaze_;

kamikaze::kamikaze(Vector2f position) : enemy(position,0), anim_delay(5), anim_delay_counter(3)
{
	//Aniation Variables
	current_anim_ = 0;
	current_frame_ = 0;
	base_speed_ = 0;
	speed_ = 4;
	current_speed_x = 0;
	current_speed_y = 0;


	//State variables
	triggered_ = false;
	trigger_range_ = 450;
	explosion_range_ = 30;
	is_active_ = true;
	has_exploded_ = false;

	base_position_ = Vector2f(position.x / 32, position.y / 32);
	setPosition(Vector2f(position.x + 16, position.y + 16));
}

void kamikaze::update(Vector2f position)
{
	if(is_active_ == true)
	{
		kamikaze_range_check(position);
		if(triggered_ == true)
		{
			rotate_towards_target();
			move();
		}

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
			setTextureRect(int_rects_movable_[0][current_anim_]);
			anim_delay_counter = 0;
		}
	}
}

void kamikaze::set_texture()
{
	setTexture(texture_kamikaze_);
	setTextureRect(int_rects_movable_[0][0]);
	
}

void kamikaze::visual_adjustments()
{
	const auto nb_character_frames = 4;
	const auto nb_character_anims = 1;

	int width = texture_kamikaze_.getSize().x / nb_character_frames;
	int height = texture_kamikaze_.getSize().y / nb_character_anims;

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
	width = 32;
	height = 32;
	// Adjust character collision points.
	top_left_point_ = Vector2f(4, 0);
	top_right_point_ = Vector2f(width - 4, 0);
	left_upper_point_ = Vector2f(-8, 8);
	left_lower_point_ = Vector2f(-8, 26);
	bottom_left_point_ = Vector2f(12, height);
	bottom_right_point_ = Vector2f(width - 12, height);
	right_upper_point_ = Vector2f(width-10, height*0.25f);
	right_lower_point_ = Vector2f(width-10, height*0.75f);

	setOrigin(width / 2, width / 2);
	

}

void kamikaze::draw(sf::RenderWindow& main_win)
{
	if(is_active_ == true)
	{
		main_win.draw(*this);
	}
}

void kamikaze::kamikaze_range_check(Vector2f position_entity)
{
	if (is_active_ == true)
	{
		direction_ = position_entity;
		Vector2f position_turret_ = getPosition();

		float diff_x_ = (direction_.x - position_turret_.x) * (direction_.x - position_turret_.x);
		float diff_y_ = (direction_.y - position_turret_.y) * (direction_.y - position_turret_.y);

		float distance = sqrt(diff_x_ + diff_y_);

		if (distance <trigger_range_ && distance > explosion_range_)
		{
			triggered_ = true;
		}
		else if (distance <= explosion_range_)
		{
			is_active_ = false;
		}
		else
		{
			triggered_ = false;
		}
	}
}

void kamikaze::rotate_towards_target()
{
	if (is_active_ == true)
	{
		Vector2f position_movable_ = direction_;
		Vector2f position_turret_ = getPosition();

		float diff_x_ = position_turret_.x - position_movable_.x;
		float diff_y_ = position_turret_.y - position_movable_.y;


		angle_ = atan2(diff_x_, diff_y_);
		if (angle_ < 0)
		{
			angle_ += (2 * 3.1416);
		}

		float angle_deg = angle_ *(180.0000 / 3.1416);

		angle_deg = -angle_deg;
		setRotation(angle_deg);		
	}
}

bool kamikaze::get_has_exploded()
{
	return  has_exploded_;
}

void kamikaze::set_has_exploded(bool has_exploded)
{
	has_exploded_ = has_exploded;
}

void kamikaze::move()
{
	is_moving_down = false;
	is_moving_up = false;
	is_moving_right = false;
	is_moving_left = false;
	float deltaX = direction_.x - getPosition().x;
	float deltaY = direction_.y - getPosition().y;

	float angle = (atan2(deltaY, deltaX));
	if (angle < 0)
	{
		angle += (2 * 3.1416);
	}

	float moveX = (float)cos(angle) * speed_;
	float moveY = (float)sin(angle) * speed_;
	float x = getPosition().x;
	float y = getPosition().y;

	setPosition(x + moveX, y + moveY);
	current_speed_x = moveX;
	current_speed_y = moveY;
	if (current_speed_x < 0)
	{
		is_moving_left = true;
	}
	else if(current_speed_x > 0)
	{
		is_moving_right = true;
	}
	if (current_speed_y < 0)
	{
		is_moving_up = true;
	}
	else if (current_speed_y > 0)
	{
		is_moving_down = true;
	}
}
