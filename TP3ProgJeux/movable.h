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
	/// Sets acceleration
	/// </summary>
	/// <param name="acceleration">The acceleration.</param>
	void accelerate(sf::Vector2f acceleration);

	/// <summary>
	/// Moves this instance.
	/// </summary>
	void move();
	
	/// <summary>
	/// Kills the movable.
	/// </summary>
	void kill_movable();

	// Accessors
	bool get_is_active();


protected:
	float speed_;
	bool is_active_;
	IntRect** int_rects_movable_;

	//Animation Variables
	int current_frame_;
	int current_anim_;



};
