#include "automatic_bonus.h"
Texture automatic_bonus::texture_automatic_bonus;

automatic_bonus::automatic_bonus() : movable(Vector2f(0, 0), 0)
{
	is_active_ = false;

	current_anim_ = 0;
	anim_delay = 5;
	anim_delay_counter = 0;
}

void automatic_bonus::update(sf::View view)
{
	if (is_active_ == true)
	{
		if ((getPosition().x + size_sprite_) < (view.getCenter().x - view.getSize().x / 2))
		{
			is_active_ = false;
		}
	}
}


void automatic_bonus::visual_adjustments()
{
	nb_movable_frames = 6;
	nb_movable_anims = 1;

	int width = texture_automatic_bonus.getSize().x / nb_movable_frames;
	int height = texture_automatic_bonus.getSize().y / nb_movable_anims;
	setOrigin(width / 2, width / 2);
}

void automatic_bonus::set_texture()
{
	setTexture(texture_automatic_bonus);
	setTextureRect(int_rects_movable_[0][0]);
	size_sprite_ = texture_automatic_bonus.getSize().x / nb_movable_frames;
}

void automatic_bonus::draw(sf::RenderWindow& main_win)
{
	if (is_active_ == true)
	{
		main_win.draw(*this);
	}
}

void automatic_bonus::spawn_bonus(Vector2f position)
{
	setPosition(position);
	is_active_ = true;
}