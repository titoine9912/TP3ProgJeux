#include "main_menu.h"
#include "Game.h"

main_menu::main_menu()
{
	
	title_ = text("Main Menu", sf::Vector2f(0, 0), text::title);
	title_.set_position(sf::Vector2f(Game::LARGEUR / 2 - title_.get_text_size() / 2, Game::HAUTEUR / 2 - 60));

	play_ = button("Play", sf::Vector2f(0, 0), text::normal);
	play_.set_position(sf::Vector2f(Game::LARGEUR / 2 - play_.get_text_size() / 2, Game::HAUTEUR / 2));

	exit_ = button("Exit", sf::Vector2f(0, 0), text::normal);
	exit_.set_position(sf::Vector2f(Game::LARGEUR / 2 - exit_.get_text_size() / 2, Game::HAUTEUR / 2 + 50));
	
}

void main_menu::draw(sf::RenderWindow& main_win)
{
	title_.draw(main_win);
	play_.draw(main_win);
	exit_.draw(main_win);
}

menu_factory::menu_factory::type_menu main_menu::update()
{
	if(play_.update())
	{
		return menu_factory::menu_factory::play_singleplayer_e;
	}
	if(exit_.update())
	{
		return menu_factory::menu_factory::exit_e;
	}
	return menu_factory::menu_factory::main_menu_e;
}

main_menu::~main_menu()
{
}
