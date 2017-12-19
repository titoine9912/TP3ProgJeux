#include "vie_bonus.h"
Texture vie_bonus::texture_vie_bonus;

vie_bonus::vie_bonus() : movable(Vector2f(0, 0), 0)
{
	is_active_ = false;
}

void vie_bonus::update(sf::View view)
{
	if (is_active_ == true)
	{
		spawn_cooldown_--;
		if ((getPosition().x + size_sprite_) < (view.getCenter().x - view.getSize().x / 2))
		{
			is_active_ = false;
		}
	}
}


void vie_bonus::visual_adjustments()
{
	nb_movable_frames = 1;
	nb_movable_anims = 1;

	int width = texture_vie_bonus.getSize().x / nb_movable_frames;
	int height = texture_vie_bonus.getSize().y / nb_movable_anims;
	setOrigin(width / 2, width / 2);
}

void vie_bonus::set_texture()
{
	setTexture(texture_vie_bonus);
	size_sprite_ = texture_vie_bonus.getSize().x / nb_movable_frames;
}

void vie_bonus::draw(sf::RenderWindow& main_win)
{
	if (is_active_ == true)
	{
		main_win.draw(*this);
	}
}

void vie_bonus::spawn_bonus(Vector2f position)
{
	spawn_cooldown_ = 60;
	setPosition(position);
	is_active_ = true;
}