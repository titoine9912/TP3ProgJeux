#pragma once
#include <SFML/Graphics.hpp>

class scrolling_background
{
public:
		scrolling_background(const int largeur, const int hauteur);

		static bool load_textures(const char texture_path[]);
		void set_texture();
		void draw(sf::RenderWindow main_win);
private:
	const int SCREEN_WIDTH;
	const int SCREEN_HEIGHT;

	sf::Sprite layer1;
	sf::Texture layer1;

	sf::Sprite layer2;
	sf::Texture layer2;

	sf::Sprite layer3;
	sf::Texture layer3;

	sf::Sprite layer4;
	sf::Texture layer4;

	sf::Vector2f position[8];

	int speed_layer1;
	int speed_layer2;
	int speed_layer3;
	int speed_layer4;



};
