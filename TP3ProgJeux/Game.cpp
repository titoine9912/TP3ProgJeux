#include "Game.h"
#include "tile.h"
#include "text.h"




Game::Game() : scrolling_background_(LARGEUR, HAUTEUR), player_character_(Vector2f(32,32) ,1)
{

	//On place dans le contructeur ce qui permet � la game elle-m�me de fonctionner

	mainWin.create(VideoMode(LARGEUR, HAUTEUR, 32), "Sidescroller Shooter");  // , Style::Titlebar); / , Style::FullScreen);
	view = mainWin.getDefaultView();

	//Synchonisation coordonn�e � l'�cran!  Normalement 60 frames par secondes. � faire absolument
	mainWin.setVerticalSyncEnabled(true);
	//mainWin.setFramerateLimit(60);  //�quivalent... normalement, mais pas toujours. � utiliser si la synchonisation de l'�cran fonctionne mal.
	//https://www.sfml-dev.org/tutorials/2.0/window-window.php#controlling-the-framerate
}

int Game::testTest()
{
	return 0;
}

int Game::run()
{
	if (!init())
	{
		return EXIT_FAILURE;
	}

	while (mainWin.isOpen())
	{
		getInputs();
		update();
		draw();
	}

	return EXIT_SUCCESS;
}

bool Game::init()
{
	/*
	if(!tile::load_textures("Sprites\\.png"))
	{
		
	}
	if(!base_enemy::load_textures("Sprites\\Paranoid.png",base_enemy::texture_base_enemy_))
	{
		
	}
	if (!base_turret::load_textures("Sprites\\.png", base_turret::texture_base_turret_))
	{

	}
	if (!upgraded_turret::load_textures("Sprites\\.png", upgraded_turret::texture_upgraded_turret))
	{

	}
	if (!boss::load_textures("Sprites\\.png", boss::texture_boss_))
	{

	}
	if (!kamikaze::load_textures("Sprites\\Dove.png", kamikaze::texture_kamikaze_))
	{

	}
	*/

	if (!player_character::load_textures("Sprites\\Lightning.png", player_character::texture_player_character_))
	{
		return false;
	}

	if (!scrolling_background::load_textures("Sprites\\space_background\\back_sharp.jpg", "Sprites\\space_background\\plnette.png", "Sprites\\space_background\\double_planet.png", "Sprites\\space_background\\asteroids.png"))
	{
		return false;
	}

	player_character_.visual_adjustments();
	player_character_.set_texture();
	scrolling_background_.set_texture();
	return true;
}

void Game::getInputs()
{
	//On passe l'�v�nement en r�f�rence et celui-ci est charg� du dernier �v�nement re�u!
	while (mainWin.pollEvent(event))
	{
		//x sur la fen�tre
		if (event.type == Event::Closed)
		{
			mainWin.close();
		}
	}
}

void Game::update()
{
	scrolling_background_.move(0);
	player_character_.update();
}

void Game::draw()
{
	//Toujours important d'effacer l'�cran pr�c�dent
	mainWin.clear();


	scrolling_background_.draw(mainWin);
	player_character_.draw(mainWin);

	mainWin.display();

}