#include "bomb_launcher_bonus.h"
Texture bomb_launcher_bonus::texture_bomb_launcher_bonus;

bomb_launcher_bonus::bomb_launcher_bonus() : movable(Vector2f(0, 0), 0)
{
	is_active_ = false;
}

void bomb_launcher_bonus::update(sf::View view)
{
	if (is_active_ == true)
	{
		if ((getPosition().x + size_sprite_) < (view.getCenter().x - view.getSize().x / 2))
		{
			is_active_ = false;
		}
		setRotation(getRotation()+1);
	}
}


void bomb_launcher_bonus::visual_adjustments()
{
	nb_movable_frames = 1;
	nb_movable_anims = 1;

	int width = texture_bomb_launcher_bonus.getSize().x / nb_movable_frames;
	int height = texture_bomb_launcher_bonus.getSize().y / nb_movable_anims;
	setOrigin(width / 2, width / 2);
}

void bomb_launcher_bonus::set_texture()
{
	setTexture(texture_bomb_launcher_bonus);
	size_sprite_ = texture_bomb_launcher_bonus.getSize().x / nb_movable_frames;
}

void bomb_launcher_bonus::draw(sf::RenderWindow& main_win)
{
	if (is_active_ == true)
	{
		main_win.draw(*this);
	}
}

void bomb_launcher_bonus::spawn_bonus(Vector2f position)
{
	setPosition(position);
	is_active_ = true;
}