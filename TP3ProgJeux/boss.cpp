#include "boss.h"
#include "kamikaze.h"
Texture boss::texture_boss_;
boss::boss(Vector2f position) :enemy(position,0), is_moving_up(true), is_moving_down(false), last_position_(2), spawn_rate_(60),spawn_rate_counter(60), fire_rate_(60), fire_rate_counter_(0)
{
	//Aniation Variables
	current_anim_ = 0;
	current_frame_ = 0;
	speed_ = 3;
	health_=20;

	fire_rate_ = 60;
	fire_rate_counter = 60;

	is_active_ = true;
	has_exploded_ = false;
	triggered_ = false;


	base_position_ = Vector2f(position.x / 32, position.y / 32);
	setPosition(position);
	
}

void boss::update(std::vector<kamikaze>& kamikazes)
{
	if (is_active_ == true)
	{
		fire_rate_counter++;
		spawn_rate_counter++;
		health_check();
		if (spawn_rate_counter >= spawn_rate_ && triggered_ == true)
		{
			kamikazes.push_back(spawn_kamikaze());
			kamikazes.back().visual_adjustments();
			kamikazes.back().set_texture();
			spawn_rate_counter = 0;
		}
		

		anim_delay_counter++;
		if (anim_delay_counter >= anim_delay)
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

	}
}

void boss::set_texture()
{
	setTexture(texture_boss_);
	setTextureRect(int_rects_movable_[0][0]);
	size_sprite_ = texture_boss_.getSize().x / 4;
	setRotation(270);
}

void boss::move(View view)
{
	if (is_moving_up == true)
	{
		if (getPosition().y - speed_ > 0)
		{
			setPosition(Vector2f(getPosition().x, (getPosition().y - speed_)));
		}
		else
		{
			is_moving_down = true;
		}
	}
	if (is_moving_down == true)
	{
		if (getPosition().y + speed_ < (view.getCenter().y + (view.getSize().y/2)))
		{
			setPosition(Vector2f(getPosition().x, (getPosition().y + speed_)));
		}
		else
		{
			is_moving_up = true;
		}
	}
}

void boss::visual_adjustments()
{
	nb_movable_frames = 4;
	nb_movable_anims = 1;

	int width = texture_boss_.getSize().x / nb_movable_frames;
	int height = texture_boss_.getSize().y / nb_movable_anims;

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
	setOrigin(width / 2, width / 2);
}

void boss::draw(sf::RenderWindow& main_win)
{
	if (is_active_ == true)
	{
		Vector2f allo = getPosition();
		main_win.draw(*this);
	}
}

kamikaze boss::spawn_kamikaze()
{
	position_1_ = Vector2f(getPosition().x - 50, getPosition().y);
	return kamikaze_factory_.create_kamikaze(position_1_);
}

bool boss::get_is_triggered()
{
	return triggered_;
}

void boss::set_is_triggered(bool triggered)
{
	triggered_ = triggered;
}

int boss::get_fire_rate()
{
	return fire_rate_;
}

int boss::get_fire_rate_counter()
{
	return fire_rate_counter;
}

void boss::set_counter(int counter)
{
	fire_rate_counter = counter;
}
