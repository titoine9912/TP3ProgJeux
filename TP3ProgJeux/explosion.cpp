#include  "explosion.h"
Texture explosion::texture_explosion;

explosion::explosion() : movable(Vector2f(0,0),0)
{
	//Aniation Variables
	current_anim_ = 0;
	current_frame_ = 0;
	anim_delay = 5;
	anim_delay_counter = 5;
	is_active_ = false;
	
}

void explosion::update()
{
	if(is_active_ == true)
	{
		anim_delay_counter++;
		if (anim_delay_counter >= anim_delay)
		{
			if (current_anim_ < 8)
			{
				current_anim_++;
			}
			else if(current_anim_ >=8)
			{
				is_active_ = false;
				current_anim_ = 0;
			}
			setTextureRect(int_rects_movable_[0][current_anim_]);
			anim_delay_counter = 0;
		}
	}
}

void explosion::visual_adjustments()
{
	const auto nb_character_frames = 9;
	const auto nb_character_anims = 1;

	int width = texture_explosion.getSize().x / nb_character_frames;
	int height = texture_explosion.getSize().y / nb_character_anims;

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
	width = 32;
	setOrigin(width / 2, width / 2);
}

void explosion::set_texture()
{
	setTexture(texture_explosion);
	setTextureRect(int_rects_movable_[0][0]);
	size_sprite_ = texture_explosion.getSize().x / 9;
}

void explosion::draw(sf::RenderWindow& main_win)
{
	if (is_active_ == true)
	{
		main_win.draw(*this);
	}
}


void explosion::activate_explosion(Vector2f position)
{
	is_active_ = true;
	setPosition(position);
}
