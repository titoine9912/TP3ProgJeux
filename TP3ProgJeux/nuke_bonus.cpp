#include "nuke_bonus.h"
Texture nuke_bonus::texture_nuke_bonus;

nuke_bonus::nuke_bonus() : movable(Vector2f(0, 0), 0)
{
	is_active_ = false;
}

void nuke_bonus::update(sf::View view)
{
	if (is_active_ == true)
	{
		if ((getPosition().x + size_sprite_) < (view.getCenter().x - view.getSize().x / 2))
		{
			is_active_ = false;
		}
		setRotation(getRotation() + 1);
	}
}

void nuke_bonus::visual_adjustments()
{
	nb_movable_frames = 1;
	nb_movable_anims = 1;

	int width = texture_nuke_bonus.getSize().x / nb_movable_frames;
	int height = texture_nuke_bonus.getSize().y / nb_movable_anims;
	setOrigin(width / 2, width / 2);
}

void nuke_bonus::set_texture()
{
	setTexture(texture_nuke_bonus);
	size_sprite_ = texture_nuke_bonus.getSize().x / nb_movable_frames;
}

void nuke_bonus::draw(sf::RenderWindow& main_win)
{
	if (is_active_ == true)
	{
		main_win.draw(*this);
	}
}

void nuke_bonus::spawn_bonus(Vector2f position)
{
	setPosition(position);
	is_active_ = true;
}