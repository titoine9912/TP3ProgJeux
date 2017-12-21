#include "missile_enemy.h"
Texture missile_enemy::texture_missile_enemy_;


missile_enemy::missile_enemy()
{
	//Animation Variables
	current_anim_ = 0;
	current_frame_ = 0;
	anim_delay_counter = 0;
	anim_delay = 30;
	speed_ = 2;
	damage_ = 2;
	//State Variable
	is_active_ = false;
	has_exploded_ = false;
}

void missile_enemy::update(sf::View view, Vector2f direction,movable* movable )
{
	if ((getPosition().x > view.getCenter().x + (view.getSize().x) / 2) || (getPosition().x < 0) || (getPosition().y < 0) || (getPosition().y > view.getCenter().y + (view.getSize().y) / 2))
	{
		is_active_ = false;
	}
	if (is_active_ == true)
	{
		if (collision(movable) == true)
		{
			is_active_ = false;
		}
		rotate_towards_target(direction);
		move();
	}
}

void missile_enemy::move()
{
	is_moving_down = false;
	is_moving_up = false;
	is_moving_right = false;
	is_moving_left = false;
	float deltaX = direction_.x +16 - getPosition().x;
	float deltaY = direction_.y+16 - getPosition().y;

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
	else if (current_speed_x > 0)
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

void missile_enemy::visual_adjustments()
{
	nb_movable_frames = 1;
	nb_movable_anims = 1;

	int width = texture_missile_enemy_.getSize().x / nb_movable_frames;
	int height = texture_missile_enemy_.getSize().y / nb_movable_anims;

	top_left_point_ = Vector2f(-4, -9);
	top_right_point_ = Vector2f(4, -9);
	bottom_right_point_ = Vector2f(4, 9);
	bottom_left_point_ = Vector2f(-4 , 9);
}

void missile_enemy::set_texture()
{
	setTexture(texture_missile_enemy_);
	setOrigin(texture_missile_enemy_.getSize().x / 2, texture_missile_enemy_.getSize().y / 2);

	size_sprite_ = texture_missile_enemy_.getSize().x / 2;
}

void missile_enemy::draw(sf::RenderWindow& main_win)
{
	if (is_active_ == true)
	{
		main_win.draw(*this);
	}
}



void missile_enemy::shoot(Vector2f position)
{
	{
		is_active_ = true;
		setPosition(position);
	}
}

void missile_enemy::rotate_towards_target(Vector2f direction)
{
	direction_ = direction;
	if (is_active_ == true)
	{
		Vector2f position_movable_ = direction_;
		Vector2f position_turret_ = getPosition();

		float diff_x_ = position_turret_.x - position_movable_.x +16;
		float diff_y_ = position_turret_.y - position_movable_.y+16;


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