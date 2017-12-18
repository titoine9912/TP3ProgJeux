#include "menu_factory.h"
#include "main_menu.h"
#include "pause_menu.h"
#include "defeat_screen.h"
#include "victory_screen.h"

menu* menu_factory::menu_factory::create_menu(type_menu type)
{
	switch (type)
	{
	case main_menu_e: return new main_menu();
	case pause_menu_e: return new pause_menu();
	case defeat_screen_e: return new defeat_screen();
	case victory_screen_e: return new victory_screen();
	default: ;
	}
	return nullptr;
}
