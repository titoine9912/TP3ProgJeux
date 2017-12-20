#include "base_projectile_enemy.h"
Texture base_projectile_enemy::texture_base_projectile_enemy_;
float base_projectile_enemy::fire_rate_counter_enemy_;

base_projectile_enemy::base_projectile_enemy()
{
	//Animation Variables
	current_anim_ = 0;
	current_frame_ = 0;
	anim_delay_counter = 0;
	anim_delay = 5;
	speed_ = 15;
	//State Variable
	is_active_ = false;
	fire_rate_ = 10;
	fire_rate_counter_enemy_ = fire_rate_;
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
		anim_delay_counter++;
		if (anim_delay_counter >= anim_delay)
		{
			if (current_anim_ <1)
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

void base_projectile_enemy::move()
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
	
	float moveX = (float)cos(angle_deg) * speed_;
	float moveY = (float)sin(angle_deg) * speed_;
	float x = getPosition().x;
	float y = getPosition().y;
	setPosition(x + moveX, y + moveY);
}

void base_projectile_enemy::visual_adjustments()
{
	nb_movable_frames = 2;
	nb_movable_anims = 1;

	int width = texture_base_projectile_enemy_.getSize().x / nb_movable_frames;
	int height = texture_base_projectile_enemy_.getSize().y / nb_movable_anims;

	int_rects_movable_ = new IntRect*[nb_movable_anims];


	for (size_t i = 0; i < nb_movable_anims; i++)
	{
		int_rects_movable_[i] = new IntRect[nb_movable_frames];
		for (size_t j = 0; j < nb_movable_frames; j++)
		{
			int_rects_movable_[i][j].left = width * j;
			int_rects_movable_[i][j].top = height * i;
			int_rects_movable_[i][j].width = width;
			int_rects_movable_[i][j].height = height;
		}
	}
}

void base_projectile_enemy::set_texture()
{
	setTexture(texture_base_projectile_enemy_);
	setTextureRect(int_rects_movable_[0][0]);
	setOrigin(texture_base_projectile_enemy_.getSize().x / 4, texture_base_projectile_enemy_.getSize().y / 2);

	size_sprite_ = texture_base_projectile_enemy_.getSize().x / 2;
}

void base_projectile_enemy::draw(sf::RenderWindow& main_win)
{
	if (is_active_ == true)
	{
		main_win.draw(*this);
	}
}

void base_projectile_enemy::counter()
{
	fire_rate_counter_enemy_++;
}

void base_projectile_enemy::shoot(Vector2f position, Vector2f direction)
{
	if (fire_rate_counter_enemy_ >= fire_rate_)
	{
		Vector2f position_movable_ = direction;
		Vector2f position_turret_ = position;

		float diff_x_ = position_turret_.x - position_movable_.x;
		float diff_y_ = position_turret_.y - position_movable_.y;


		float angle_ = atan2(diff_x_, diff_y_);
		if (angle_ < 0)
		{
			angle_ += (2 * 3.1416);
		}

		float angle_deg = angle_ *(180.0000 / 3.1416);

		angle_deg = -angle_deg;


		setRotation(angle_deg);
		is_active_ = true;
		direction_ = direction;
		setPosition(position);
		fire_rate_counter_enemy_ = 0;
	}
}
