#include "shield.h"
Texture shield::texture_base_shield_;
shield::shield() :movable(Vector2f(0, 0), 0)
{

}

void shield::draw(sf::RenderWindow& main_win)
{
	if (is_active_ == true)
	{
		main_win.draw(*this);
	}
}