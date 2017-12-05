#include "upgraded_turret.h"
Texture upgraded_turret::texture_upgraded_turret;
Texture upgraded_turret::texture_upgraded_turret_tile;

upgraded_turret::upgraded_turret(Vector2f position) : enemy(position,0), anim_delay(15), anim_delay_counter(0)
{
	//Aniation Variables
	current_anim_ = 0;
	current_frame_ = 0;

	//State variables
	triggered_ = false;
	trigger_range_ = 350;
	is_active_ = true;

	position_ = Vector2f(position.x / 32, position.y / 32);
	setPosition(Vector2f(position.x + 16, position.y + 16));
	sprite_upgraded_turret_tile_.setPosition(Vector2f(position));
}

void upgraded_turret::update(Vector2f position)
{
	anim_delay_counter++;
	turret_range_check(position);

	if (anim_delay_counter >= anim_delay && triggered_ == false)
	{
		if (current_anim_ < 3)
		{
			current_anim_++;
		}
		else
		{
			current_anim_ = 0;
		}
		setTextureRect(int_rects_movable_[0][current_anim_]);
		anim_delay_counter = 0;
	}
	if (triggered_ == true)
	{
		setTextureRect(int_rects_movable_[0][2]);
		rotate_towards_target(position);
	}
}

void upgraded_turret::set_texture()
{
	setTexture(texture_upgraded_turret);
	setTextureRect(int_rects_movable_[0][0]);
	setOrigin(16, 16);


	sprite_upgraded_turret_tile_.setTexture(texture_upgraded_turret_tile);
	sprite_upgraded_turret_tile_.setOrigin(sprite_upgraded_turret_tile_.getGlobalBounds().width / 2 - 16, 0);

	size_sprite_ = texture_upgraded_turret_tile.getSize().x;
}


bool upgraded_turret::load_textures_(const char texture_path_1[], const char texture_path_2[])
{
	if (!texture_upgraded_turret.loadFromFile(texture_path_1))
	{
		return false;
	}

	if (!texture_upgraded_turret_tile.loadFromFile(texture_path_2))
	{
		return false;
	}
	return true;
}

void upgraded_turret::visual_adjustments()
{
	const int nb_character_frames = 4;
	const auto nb_character_anims = 1;

	int width = texture_upgraded_turret.getSize().x / nb_character_frames;
	int height = texture_upgraded_turret.getSize().y / nb_character_anims;

	int_rects_movable_ = new IntRect*[nb_character_anims];


	for (size_t i = 0; i < nb_character_anims; i++)
	{
		int_rects_movable_[i] = new IntRect[nb_character_frames];
		for (size_t j = 0; j < nb_character_frames; j++)
		{
			int_rects_movable_[i][j].left = width * j;
			int_rects_movable_[i][j].top = height * i;
			int_rects_movable_[i][j].width = width;
			int_rects_movable_[i][j].height = height;
		}
	}
}

void upgraded_turret::draw(sf::RenderWindow& main_win)
{
	main_win.draw(sprite_upgraded_turret_tile_);
	main_win.draw(*this);
}

void upgraded_turret::turret_range_check(Vector2f position_entity)
{
	Vector2f position_movable_ = position_entity;
	Vector2f position_turret_ = getPosition();

	float diff_x_ = (position_movable_.x - position_turret_.x) * (position_movable_.x - position_turret_.x);
	float diff_y_ = (position_movable_.y - position_turret_.y) * (position_movable_.y - position_turret_.y);

	float distance = sqrt(diff_x_ + diff_y_);

	if (distance <trigger_range_)
	{
		triggered_ = true;
	}
	else
	{
		triggered_ = false;
	}
}

void upgraded_turret::rotate_towards_target(Vector2f position_entity)
{
	Vector2f position_movable_ = position_entity;
	Vector2f position_turret_ = getPosition();

	float diff_x_ = position_turret_.x - position_movable_.x;
	float diff_y_ = position_turret_.y - position_movable_.y;


	float angle_ = atan2(diff_x_, diff_y_);
	if (angle_ < 0)
	{
		angle_ += (2 * 3.1416);
	}

	float angle_deg = angle_ *(180.0000 / 3.1416);

	angle_deg = -angle_deg;


	setRotation(angle_deg);
}

