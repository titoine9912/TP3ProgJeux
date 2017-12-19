#include "laser_bonus.h"
Texture laser_bonus::texture_laser_bonus;

laser_bonus::laser_bonus() : movable(Vector2f(0, 0), 0)
{
	is_active_ = false;
	setRotation(90);
}

void laser_bonus::update(sf::View view)
{
	if (is_active_ == true)
	{
		spawn_cooldown_--;
		if ((getPosition().x + size_sprite_) < (view.getCenter().x - view.getSize().x / 2))
		{
			is_active_ = false;
		}
		setRotation(getRotation() + 1);
	}
}


void laser_bonus::visual_adjustments()
{
	nb_movable_frames = 1;
	nb_movable_anims = 1;

	int width = texture_laser_bonus.getSize().x / nb_movable_frames;
	int height = texture_laser_bonus.getSize().y / nb_movable_anims;
	setOrigin(width / 2, height / 2);
}

void laser_bonus::set_texture()
{
	setTexture(texture_laser_bonus);
	size_sprite_ = texture_laser_bonus.getSize().x / nb_movable_frames;
}

void laser_bonus::draw(sf::RenderWindow& main_win)
{
	if (is_active_ == true)
	{
		main_win.draw(*this);
	}
}

void laser_bonus::spawn_bonus(Vector2f position)
{
	spawn_cooldown_ = 60;
	setPosition(position);
	is_active_ = true;
}