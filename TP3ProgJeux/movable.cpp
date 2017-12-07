#include "movable.h"
movable::movable(Vector2f position, float speed) : entity(position), is_active_(true)
{
	speed_ = speed;
	setPosition(position);
	
}


void movable::move()
{
}

bool movable::get_is_active()
{
	return is_active_;
}

void movable::set_is_colliding_platform_under(bool is_colliding)
{
	is_colliding_platform_under_ = is_colliding;
}

void movable::set_is_colliding_platform_over(bool is_colliding)
{
	is_colliding_platform_over_ = is_colliding;
}

void movable::set_is_colliding_wall_left(bool is_colliding)
{
	is_colliding_wall_left_ = is_colliding;
}

void movable::set_is_colliding_wall_right(bool is_colliding)
{
	is_colliding_wall_right_ = is_colliding;
}

void movable::kill_movable()
{
	is_active_ = false;
	speed_ = 0;
}

bool movable::get_is_going_down()
{
	return is_moving_down;
}

bool movable::get_is_going_up()
{
	return is_moving_up;
}

bool movable::get_is_going_left()
{
	return is_moving_left;
}

bool movable::get_is_going_right()
{
	return is_moving_right;
}

Vector2f movable::get_top_left_point() const
{
	Vector2f tbnk = getPosition();
	return getPosition() + top_left_point_;
}

Vector2f movable::get_top_right_point() const
{
	return getPosition() + top_right_point_;
}

Vector2f movable::get_right_upper_point() const
{
	return getPosition() + right_upper_point_;
}

Vector2f movable::get_right_lower_point() const
{
	return getPosition() + right_lower_point_;
}

Vector2f movable::get_bottom_left_point() const
{
	return getPosition() + bottom_left_point_;
}

Vector2f movable::get_bottom_right_point() const
{
	return getPosition() + bottom_right_point_;
}

Vector2f movable::get_left_upper_point() const
{
	return getPosition() + left_upper_point_;
}

Vector2f movable::get_left_lower_point() const
{
	return getPosition() + left_lower_point_;
}

float movable::get_speed_x()
{
	return current_speed_x;
}

float movable::get_speed_y()
{
	return current_speed_y;
}

void movable::adjust_movable_position(Vector2f adjustment_vector)
{
	Sprite::move(adjustment_vector);
}

bool movable::get_is_colliding_platform_over_()
{
	return is_colliding_platform_over_;
}

bool movable::get_is_colliding_platform_under_()
{
	return is_colliding_platform_under_;
}

bool movable::get_is_colliding_wall_left_()
{
	return is_colliding_wall_left_;
}

bool movable::get_is_colliding_wall_right_()
{
	return is_colliding_wall_right_;
}


float movable::get_base_speed()
{
	return base_speed_;
}
