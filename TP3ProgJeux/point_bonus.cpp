#include "point_bonus.h"
Texture point_bonus::texture_point_bonus;

point_bonus::point_bonus() : movable(Vector2f(0, 0), 0)
{
	is_active_ = false;

	current_anim_ = 0;
	anim_delay = 5;
	anim_delay_counter = 0;
}

void point_bonus::update(sf::View view)
{
	if (is_active_ == true)
	{
		if ((getPosition().x +size_sprite_ ) < (view.getCenter().x - view.getSize().x/2))
		{
				is_active_ = false;
		}
		anim_delay_counter++;
		if (anim_delay_counter >= anim_delay)
		{
			if (current_anim_ < 5)
			{
				current_anim_++;
			}
			else if (current_anim_ >= 5)
			{
				current_anim_ = 0;
			}
			setTextureRect(int_rects_movable_[0][current_anim_]);
			anim_delay_counter = 0;
		}
	}
}


void point_bonus::visual_adjustments()
{
	nb_movable_frames = 6;
	nb_movable_anims = 1;

	int width = texture_point_bonus.getSize().x / nb_movable_frames;
	int height = texture_point_bonus.getSize().y / nb_movable_anims;
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
	setOrigin(width / 2, width / 2);
}

void point_bonus::set_texture()
{
	setTexture(texture_point_bonus);
	setTextureRect(int_rects_movable_[0][0]);
	size_sprite_ = texture_point_bonus.getSize().x / nb_movable_frames;
}

void point_bonus::draw(sf::RenderWindow& main_win)
{
	if (is_active_ == true)
	{
		main_win.draw(*this);
	}
}

void point_bonus::spawn_bonus(Vector2f position)
{
	setPosition(position);
	is_active_ = true;
}