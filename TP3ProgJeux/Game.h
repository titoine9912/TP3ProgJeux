#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;

class Game
{
public:
	Game();
	int run();
	int testTest();

private:
	const int LARGEUR = 1280;
	const int HAUTEUR = 720;

	bool init();
	void getInputs();
	void update();
	void draw();

	RenderWindow mainWin;
	View view;
	Event event;
};