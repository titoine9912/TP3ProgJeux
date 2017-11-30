#include "scrolling_background.h"

sf::Texture scrolling_background::layer1_texture_;
sf::Texture scrolling_background::layer2_texture_;
sf::Texture scrolling_background::layer3_texture_;
sf::Texture scrolling_background::layer4_texture_;

scrolling_background::scrolling_background(const int largeur, const int hauteur) : SCREEN_WIDTH_(largeur), SCREEN_HEIGHT_(hauteur)
{
	
	speed_layer1_ = 0.02f;
	speed_layer2_ = 0.04f;
	speed_layer3_ = 0.5f;
	speed_layer4_ = 10.0f;
	

	/*
	speed_layer1_ = 10;
	speed_layer2_ = 10;
	speed_layer3_ = 10;
	speed_layer4_ = 10;
	*/

}

void scrolling_background::set_texture()
{
	layer1_sprite_.setTexture(layer1_texture_);
	layer2_sprite_.setTexture(layer2_texture_);
	layer3_sprite_.setTexture(layer3_texture_);
	layer4_sprite_.setTexture(layer4_texture_);

	layer1_sprite_.setPosition(0, 0);
	layer2_sprite_.setPosition(0, 0);
	layer3_sprite_.setPosition(0, 0);
	layer4_sprite_.setPosition(0, 0);

	positions_layer1_[0].x = 0.0f;
	positions_layer1_[0].y = 0.0f;
	positions_layer2_[0].x = 0.0f;
	positions_layer2_[0].y = 0.0f;
	positions_layer3_[0].x = 0.0f;
	positions_layer3_[0].y = 0.0f;
	positions_layer4_[0].x = 0.0f;
	positions_layer4_[0].y = 0.0f;

	positions_layer1_[1].x = layer1_texture_.getSize().x;
	positions_layer1_[1].y = 0.0f;
	positions_layer2_[1].x = layer2_texture_.getSize().x;
	positions_layer2_[1].y = 0.0f;
	positions_layer3_[1].x = layer3_texture_.getSize().x;
	positions_layer3_[1].y = 0.0f;
	positions_layer4_[1].x = layer4_texture_.getSize().x;
	positions_layer4_[1].y = 0.0f;	
}

void scrolling_background::move(int player_speed)
{
	for (int i = 0; i < 2; i++)
	{
		//Layer 1
		positions_layer1_[i].x -= speed_layer1_ + player_speed;

		float temp = layer1_texture_.getSize().x * -1.0f;

		//SI PLUS PETIT QUE LA TAILLE DE LA TEXTURE DE FOND, ON L'AVANCE DE DEUX FOIS CETTE TAILLE
		if (positions_layer1_[i].x <= temp)
		{
			positions_layer1_[i].x += layer1_texture_.getSize().x * 2;
		}

		//Layer 2
		positions_layer2_[i].x -= speed_layer2_ + player_speed;

		temp = layer2_texture_.getSize().x * -1.0f;

		if (positions_layer2_[i].x <= temp)
		{
			positions_layer2_[i].x += layer2_texture_.getSize().x * 2;
		}

		//Layer 3
		positions_layer3_[i].x -= speed_layer3_ + player_speed;

		temp = layer3_texture_.getSize().x * -1.0f;

		if (positions_layer3_[i].x <= temp)
		{
			positions_layer3_[i].x += layer3_texture_.getSize().x * 2;
		}

		//Layer 4
		positions_layer4_[i].x -= speed_layer4_ + player_speed;

		temp = layer4_texture_.getSize().x * -1.0f;

		if (positions_layer4_[i].x <= temp)
		{
			positions_layer4_[i].x += layer4_texture_.getSize().x * 2;
		}
	}
}

void scrolling_background::draw(sf::RenderWindow& main_win)
{

		layer1_sprite_.setPosition(positions_layer1_[0]);
		main_win.draw(layer1_sprite_);

		layer1_sprite_.setPosition(positions_layer1_[1]);
		main_win.draw(layer1_sprite_);

		layer2_sprite_.setPosition(positions_layer2_[0]);
		main_win.draw(layer2_sprite_);

		layer2_sprite_.setPosition(positions_layer2_[1]);
		main_win.draw(layer2_sprite_);

		layer3_sprite_.setPosition(positions_layer3_[0]);
		main_win.draw(layer3_sprite_);

		layer3_sprite_.setPosition(positions_layer3_[1]);
		main_win.draw(layer3_sprite_);

		layer4_sprite_.setPosition(positions_layer4_[0]);
		main_win.draw(layer4_sprite_);

		layer4_sprite_.setPosition(positions_layer4_[1]);
		main_win.draw(layer4_sprite_);

}

bool scrolling_background::load_textures(const char texture_path_1[], const char texture_path_2[], const char texture_path_3[], const char texture_path_4[])
{
	if (!layer1_texture_.loadFromFile(texture_path_1))
	{
		return false;
	}

	if (!layer2_texture_.loadFromFile(texture_path_2))
	{
		return false;
	}

	if (!layer3_texture_.loadFromFile(texture_path_3))
	{
		return false;
	}

	if (!layer4_texture_.loadFromFile(texture_path_4))
	{
		return false;
	}
	return true;
}