#include "automatic_projectile.h"
Texture automatic_projectile::texture_automatic_projectile_;
float automatic_projectile::fire_rate_counter_automatic;

automatic_projectile::automatic_projectile()
{
	//Animation Variables
	current_anim_ = 0;
	current_frame_ = 0;
	anim_delay_counter = 0;
	anim_delay = 5;
	speed_ = 30;
	//State Variable
	is_active_ = false;
	fire_rate_ = 10;
	fire_rate_counter_automatic = fire_rate_;
	up_projectile_ = true;
}

void automatic_projectile::update(sf::View view)
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

void automatic_projectile::move()
{
	setPosition(getPosition().x + speed_, getPosition().y);
}

void automatic_projectile::visual_adjustments()
{
	nb_movable_frames = 2;
	nb_movable_anims = 1;

	int width = texture_automatic_projectile_.getSize().x / nb_movable_frames;
	int height = texture_automatic_projectile_.getSize().y / nb_movable_anims;

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

void automatic_projectile::set_texture()
{
	setTexture(texture_automatic_projectile_);
	setTextureRect(int_rects_movable_[0][0]);
	setOrigin(texture_automatic_projectile_.getSize().x / 4, texture_automatic_projectile_.getSize().y / 2);

	size_sprite_ = texture_automatic_projectile_.getSize().x / 2;
}


void automatic_projectile::draw(sf::RenderWindow& main_win)
{
	if (is_active_ == true)
	{
		main_win.draw(*this);
	}
}


void automatic_projectile::counter()
{
	fire_rate_counter_automatic++;
}
void automatic_projectile::shoot(Vector2f position, Vector2f direction)
{
	if (fire_rate_counter_automatic >= fire_rate_)
	{
		is_active_ = true;
		direction_ = direction;
		setPosition(position);
		fire_rate_counter_automatic = 0;
	}
}

