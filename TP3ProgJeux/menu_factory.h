#ifndef MENU_FACTORY_H
#define MENU_FACTORY_H

class menu;

namespace menu_factory
{
	class menu_factory
	{
	public:
		enum type_menu
		{
			exit_e, // Not a menu (causes the game to close).
			play_singleplayer_e, // Not a menu (its the current game)
			main_menu_e,
			pause_menu_e,
			victory_screen_e,
			defeat_screen_e,
		};

		static menu* create_menu(type_menu type);
	};
}
#endif