#include "base_projectile_enemy.h"
Texture base_projectile_enemy::texture_base_projectile_enemy_;


base_projectile_enemy::base_projectile_enemy()
{
	//Animation Variables
	current_anim_ = 0;
	current_frame_ = 0;
	anim_delay_counter = 0;
	anim_delay = 30;
	speed_ = 5;
	//State Variable
	is_active_ = false;
	damage_ = 1;
}

void base_projectile_enemy::update(sf::View view)
{
	if ((getPosition().x > view.getCenter().x + (view.getSize().x) / 2) || (getPosition().x < 0) || (getPosition().y < 0) || (getPosition().y > view.getCenter().y + (view.getSize().y) / 2))
	{
		is_active_ = false;
	}
	if (is_active_ == true)
	{
		move();
	}
}

void base_projectile_enemy::move()
{
	
	setPosition(getPosition().x + moveX_, getPosition().y + moveY_);
}

void base_projectile_enemy::visual_adjustments()
{
	nb_movable_frames = 1;
	nb_movable_anims = 1;

	int width = texture_base_projectile_enemy_.getSize().x / nb_movable_frames;
	int height = texture_base_projectile_enemy_.getSize().y / nb_movable_anims;

	top_left_point_ = Vector2f(-4, -3);
	top_right_point_ = Vector2f( 4, -3);
	bottom_left_point_ = Vector2f(- 4, 3);
	bottom_right_point_ = Vector2f( 4, 3);
}

void base_projectile_enemy::set_texture()
{
	setTexture(texture_base_projectile_enemy_);
	setOrigin(texture_base_projectile_enemy_.getSize().x /2, texture_base_projectile_enemy_.getSize().y / 2);

	size_sprite_ = texture_base_projectile_enemy_.getSize().x / 2;
}

void base_projectile_enemy::draw(sf::RenderWindow& main_win)
{
	if (is_active_ == true)
	{
		main_win.draw(*this);
	}
}



void base_projectile_enemy::shoot(Vector2f position, Vector2f direction)
{
	{
		direction_ = direction;
		setPosition(position);

		float deltaX = direction_.x +16 - getPosition().x;
		float deltaY = direction_.y +16 - getPosition().y;

		float angle_ = (atan2(deltaY, deltaX));
		if (angle_ < 0)
		{
			angle_ += (2 * 3.1416);
		}

		float angle_deg = angle_ *(180.0000 / 3.1416);

		angle_deg = -angle_deg;


		 moveX_ = (float)cos(angle_) * speed_;
		 moveY_ = (float)sin(angle_) * speed_;

		setRotation(angle_deg);
		is_active_ = true;

	}
}
