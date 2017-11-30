#pragma once
#include <SFML/Graphics.hpp>

class scrolling_background
{
public:
		scrolling_background(const int largeur, const int hauteur);

		static bool load_textures(const char texture_path_1[], const char texture_path_2[] , const char texture_path_3[] , const char texture_path_4[]);
		void set_texture();
		void move( int player_speed);
		void draw(sf::RenderWindow& main_win);
private:
	const int SCREEN_WIDTH_;
	const int SCREEN_HEIGHT_;

	sf::Sprite layer1_sprite_;
	static sf::Texture layer1_texture_;

	sf::Sprite layer2_sprite_;
	static sf::Texture layer2_texture_;

	sf::Sprite layer3_sprite_;
	static sf::Texture layer3_texture_;

	sf::Sprite layer4_sprite_;
	static sf::Texture layer4_texture_;

	sf::Vector2f positions_layer1_[2];
	sf::Vector2f positions_layer2_[2];
	sf::Vector2f positions_layer3_[2];
	sf::Vector2f positions_layer4_[2];

	float speed_layer1_;
	float speed_layer2_;
	float speed_layer3_;
	float speed_layer4_;



};
