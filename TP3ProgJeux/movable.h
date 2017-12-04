#pragma once
#include <SFML/System/Vector2.hpp>
#include "entity.h"

class movable : public entity
{
public:
	//Overload Constructor
	movable(Vector2f position, float speed);

	// Mutators
	/// <summary>
	/// Moves this instance.
	/// </summary>
	void move();
	
	/// <summary>
	/// Kills the movable.
	/// </summary>
	void kill_movable();

	/// <summary>
	/// Sets is colliding wall left.
	/// </summary>
	/// <param name="is_colliding">if set to <c>true</c> [is colliding].</param>
	void set_is_colliding_wall_left(bool is_colliding);

	/// <summary>
	/// Sets is colliding wall right.
	/// </summary>
	/// <param name="is_colliding">if set to <c>true</c> [is colliding].</param>
	void set_is_colliding_wall_right(bool is_colliding);

	/// <summary>
	/// Sets is colliding platform under.
	/// </summary>
	/// <param name="is_colliding">if set to <c>true</c> [is colliding].</param>
	void set_is_colliding_platform_under(bool is_colliding);

	/// <summary>
	/// Sets is colliding platform over.
	/// </summary>
	/// <param name="is_colliding">if set to <c>true</c> [is colliding].</param>
	void set_is_colliding_platform_over(bool is_colliding);

	/// <summary>
	/// Gets the top left point.
	/// </summary>
	/// <returns></returns>
	Vector2f get_top_left_point() const;

	/// <summary>
	/// Gets the top right point.
	/// </summary>
	/// <returns></returns>
	Vector2f get_top_right_point() const;

	/// <summary>
	/// Gets the right upper point.
	/// </summary>
	/// <returns></returns>
	Vector2f get_right_upper_point() const;

	/// <summary>
	/// Gets the right lower point.
	/// </summary>
	/// <returns></returns>
	Vector2f get_right_lower_point() const;

	/// <summary>
	/// Gets the bottom left point.
	/// </summary>
	/// <returns></returns>
	Vector2f get_bottom_left_point() const;

	/// <summary>
	/// Gets the bottom right point.
	/// </summary>
	/// <returns></returns>
	Vector2f get_bottom_right_point() const;

	/// <summary>
	/// Gets the left upper point.
	/// </summary>
	/// <returns></returns>
	Vector2f get_left_upper_point() const;

	/// <summary>
	/// Gets the left lower point.
	/// </summary>
	/// <returns></returns>
	Vector2f get_left_lower_point() const;

	void adjust_movable_position(Vector2f adjustment_vector);

	float get_speed_x();
	float get_speed_y();

	// Accessors
	bool get_is_active();
	bool get_is_going_up();
	bool get_is_going_down();
	bool get_is_going_right();
	bool get_is_going_left();

	bool get_is_colliding_platform_under_();
	bool get_is_colliding_platform_over_();
	bool get_is_colliding_wall_left_();
	bool get_is_colliding_wall_right_();



protected:

	bool is_colliding_platform_under_;
	bool is_colliding_platform_over_;
	bool is_colliding_wall_left_;
	bool is_colliding_wall_right_;

	bool is_moving_left;
	bool is_moving_right;
	bool is_moving_up;
	bool is_moving_down;

	float base_speed_;
	float speed_;
	float current_speed_x;
	float current_speed_y;
	bool is_active_;
	IntRect** int_rects_movable_;






};
