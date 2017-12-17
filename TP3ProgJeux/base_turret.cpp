#include  "base_turret.h"
Texture base_turret::texture_base_turret;
Texture base_turret::texture_turret_tile;


base_turret::base_turret(Vector2f position) : enemy(position,0)
{
	//Aniation Variables
	current_anim_ = 0;
	current_frame_ = 0;
	anim_delay = 15;
	anim_delay_counter = 0;
	
	//State variables
	triggered_ = false;
	trigger_range_ = 350;
	is_active_ = true;

	position_ = Vector2f(position.x / 32, position.y / 32);
	setPosition(Vector2f(position.x +16, position.y+16));
	sprite_turret_tile_.setPosition(Vector2f(position));
}


bool base_turret::load_textures_(const char texture_path_1[], const char texture_path_2[])
{
	if (!texture_base_turret.loadFromFile(texture_path_1))
	{
		return false;
	}

	if (!texture_turret_tile.loadFromFile(texture_path_2))
	{
		return false;
	}
	return true;
}

void base_turret::update(Vector2f position)
{
	if(is_active_ == true)
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
}

void base_turret::set_texture()
{
	setTexture(texture_base_turret);
	setTextureRect(int_rects_movable_[0][0]);
	setOrigin(16, 16);


	sprite_turret_tile_.setTexture(texture_turret_tile);
	sprite_turret_tile_.setOrigin(sprite_turret_tile_.getGlobalBounds().width / 2 - 16, 0);

	size_sprite_ = texture_turret_tile.getSize().x;

}


void base_turret::visual_adjustments()
{
	nb_movable_frames = 4;
	nb_movable_anims = 1;

	int width = texture_base_turret.getSize().x / nb_movable_frames;
	int height = texture_base_turret.getSize().y / nb_movable_anims;

	int_rects_movable_ = new IntRect*[nb_movable_anims];


	for (size_t i = 0; i < nb_movable_anims; i++)
	{
		int_rects_movable_[i] = new IntRect[nb_movable_frames];
		for (size_t j = 0; j < nb_movable_frames; j++)
		{
			int_rects_movable_[i][j].left = width * j;
			int_rects_movable_[i][j].top = height * i;
			int_rects_movable_[i][j].width = width;
			int_rects_movable_[i][j].height = height;
		}
	}
}

void base_turret::draw(sf::RenderWindow& main_win)
{
	if(is_active_ == true)
	{
		main_win.draw(sprite_turret_tile_);
		main_win.draw(*this);
	}
}

void base_turret::turret_range_check(Vector2f position_entity)
{
	Vector2f position_movable_ = position_entity;
	Vector2f position_turret_ = getPosition();

	float diff_x_ = (position_movable_.x - position_turret_.x) * (position_movable_.x - position_turret_.x);
	float diff_y_ = (position_movable_.y - position_turret_.y) * (position_movable_.y - position_turret_.y);

	float distance = sqrt(diff_x_ + diff_y_);
	
	if(distance <trigger_range_)
	{
		triggered_ = true;
	}
	else
	{
		triggered_ = false;
	}
}

void base_turret::rotate_towards_target(Vector2f position_entity)
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
