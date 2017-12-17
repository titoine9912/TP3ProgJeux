#include  "defeat_screen.h"
#include "Game.h"


defeat_screen::~defeat_screen()
{
}

defeat_screen::defeat_screen()
{
	
	title_ = text("Defeat!", sf::Vector2f(0, 0), text::title);
	title_.set_position(sf::Vector2f(Game::LARGEUR / 2 - title_.get_text_size() / 2, Game::HAUTEUR / 2 - 60));

	back_ = button("Back", sf::Vector2f(30, 70), text::normal);
	back_.set_position(sf::Vector2f(Game::LARGEUR / 2 - back_.get_text_size() / 2, Game::HAUTEUR / 2 + 60));
	
}

void defeat_screen::draw(sf::RenderWindow& main_win)
{
	title_.draw(main_win);
	back_.draw(main_win);
}

menu_factory::menu_factory::type_menu defeat_screen::update()
{
	if (back_.update())
	{
		return menu_factory::menu_factory::main_menu_e;
	}

	return menu_factory::menu_factory::defeat_screen_e;
}
