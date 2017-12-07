#include "base_projectile.h"
Texture base_projectile::texture_base_projectile_;

base_projectile::base_projectile()
{
	//Animation Variables
	current_anim_ = 0;
	current_frame_ = 0;
	anim_delay_counter = 0;
	anim_delay = 5;

	//State Variable
	is_active_ = false;
}

void base_projectile::update()
{
	if(is_active_ == true)
	{
		move();
		anim_delay_counter++;
		if (anim_delay_counter >= anim_delay)
		{
			if(current_anim_ <1)
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

void base_projectile::move()
{
	setPosition(getPosition().x + speed_, getPosition().y);
}

void base_projectile::visual_adjustments()
{
	const int nb_projectile_frames = 2;
	const auto nb_projectile_anims = 1;

	int width = texture_base_projectile_.getSize().x / nb_projectile_frames;
	int height = texture_base_projectile_.getSize().y / nb_projectile_anims;

	int_rects_movable_ = new IntRect*[nb_projectile_anims];


	for (size_t i = 0; i < nb_projectile_anims; i++)
	{
		int_rects_movable_[i] = new IntRect[nb_projectile_frames];
		for (size_t j = 0; j < nb_projectile_frames; j++)
		{
			int_rects_movable_[i][j].left = width * j;
			int_rects_movable_[i][j].top = height * i;
			int_rects_movable_[i][j].width = width;
			int_rects_movable_[i][j].height = height;
		}
	}
}

void base_projectile::set_texture()
{
	setTexture(texture_base_projectile_);
	setTextureRect(int_rects_movable_[0][0]);
	setOrigin(texture_base_projectile_.getSize().x/4, texture_base_projectile_.getSize().y / 2);
	
	size_sprite_ = texture_base_projectile_.getSize().x / 2;
}

void base_projectile::draw(sf::RenderWindow& main_win)
{
	if (is_active_ == true)
	{
		main_win.draw(*this);
	}
}

