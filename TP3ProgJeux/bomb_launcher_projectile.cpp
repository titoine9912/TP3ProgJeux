#include "bomb_launcher_projectile.h"
Texture bomb_launcher_projectile::texture_bomb_launcher_projectile_;
float bomb_launcher_projectile::fire_rate_counter_bomb_;
bomb_launcher_projectile::bomb_launcher_projectile()
{
	current_anim_ = 0;
	current_frame_ = 0;
	anim_delay_counter = 0;
	anim_delay = 5;
	speed_ = 15;
	//State Variable
	is_active_ = false;
	fire_rate_ = 10;
	fire_rate_counter_bomb_ = fire_rate_;
}


void bomb_launcher_projectile::update(sf::View view)
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

void bomb_launcher_projectile::move()
{
	setPosition(getPosition().x + speed_, getPosition().y);
}

void bomb_launcher_projectile::visual_adjustments()
{
	nb_movable_frames = 2;
	nb_movable_anims = 1;

	int width = texture_bomb_launcher_projectile_.getSize().x / nb_movable_frames;
	int height = texture_bomb_launcher_projectile_.getSize().y / nb_movable_anims;

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

void bomb_launcher_projectile::set_texture()
{
	setTexture(texture_bomb_launcher_projectile_);
	setTextureRect(int_rects_movable_[0][0]);
	setOrigin(texture_bomb_launcher_projectile_.getSize().x / 4, texture_bomb_launcher_projectile_.getSize().y / 2);

	size_sprite_ = texture_bomb_launcher_projectile_.getSize().x / 2;
}


void bomb_launcher_projectile::draw(sf::RenderWindow& main_win)
{
	if (is_active_ == true)
	{
		main_win.draw(*this);
	}
}


void bomb_launcher_projectile::counter()
{
	fire_rate_counter_bomb_++;
}
void bomb_launcher_projectile::shoot(Vector2f position, Vector2f direction)
{
	if (fire_rate_counter_bomb_ >= fire_rate_)
	{
		is_active_ = true;
		direction_ = direction;
		setPosition(position);
		fire_rate_counter_bomb_ = 0;
	}
}