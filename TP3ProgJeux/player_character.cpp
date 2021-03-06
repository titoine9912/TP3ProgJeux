#include "player_character.h"
#include "input_manager.h"
#include <iostream>
Texture player_character::texture_player_character_;

player_character::player_character(Vector2f position, int player_id) :character(position,0)
{
	setPosition(position);

	base_speed_ = 1;
	speed_ = 5;
	current_speed_x = 0;
	current_speed_y = 0;
	health_ = 1000;

	//Aniation Variables
	current_anim_ = 0;
	current_frame_ = 0;
	anim_delay = 5;
	anim_delay_counter = 0;

	//Character state variables
	base_speed_applied_ = false;
	end_of_level_ = false;
	is_active_ = true;
	//Character movement state
	is_moving_down = false;
	is_moving_up = false;
	is_moving_right = false;
	is_moving_left = false;
}



void player_character::update()
{
	if(is_active_ ==true)
	{
		health_check();
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

void player_character::set_texture()
{
	setTexture(texture_player_character_);
	setTextureRect(int_rects_movable_[0][0]);
	setOrigin(getGlobalBounds().width / 2 - 16, 0);
	size_sprite_ = texture_player_character_.getSize().x/4;
}

void player_character::move(View view)
{
	is_moving_down = false;
	is_moving_up = false;
	is_moving_right = false;
	is_moving_left = false;
	current_speed_x = 0;
	current_speed_y = 0;

	//Si le joueur est a la fin du niveau, la base_speed ne sera plus affect�.
	if (end_of_level_ == false)
	{
		base_speed_applied_ = false;
	}
	
	//Si le joueur appuie sur l'une des touches directionelles
	if(input_manager::get_input_manager()->get_d() ==true || input_manager::get_input_manager()->get_a()==true || input_manager::get_input_manager()->get_s()==true || input_manager::get_input_manager()->get_w()==true)
	{
		//Si le joueur appuie sur d
		if (input_manager::get_input_manager()->get_d())
		{
			//Projection du joueur si on le fait avanc� vers la droite
			if(getPosition().x + speed_ + 32 < view.getCenter().x + view.getSize().x/2 )
			{
				//Le joueur avance vers la droite � sa vitesse
				setPosition(Vector2f(getPosition().x + speed_, getPosition().y));
				is_moving_right = true;
				if (current_speed_x == 0)
				{
					current_speed_x = speed_;
				}
			}
			//Sinon on regarde si la base speed peut �tre affect�
			else if(base_speed_applied_ == false && getPosition().x + base_speed_ < view.getCenter().x + view.getSize().x / 2)
			{
				setPosition(Vector2f(getPosition().x + base_speed_, getPosition().y));
				base_speed_applied_ = true;
				is_moving_right = true;
				if (current_speed_x == 0)
				{
					current_speed_x = base_speed_;
				}
			}
		}
		//Si le joueur appuie sur W
		 if (input_manager::get_input_manager()->get_w())
		{
			 //Projection du joueur vers le haut
			 if (getPosition().y - speed_ >0)
			 {
				 //Le joueur avance vers le haut
				 setPosition(Vector2f(getPosition().x, getPosition().y - speed_));
				 is_moving_up = true;
				 current_speed_y = 0 - speed_;
				 //On regarde si la base speed peut �tre affect�
				 if(base_speed_applied_ == false)
				 {
					 //La base speed est affect� pour suivre la window.
					 setPosition(Vector2f(getPosition().x + base_speed_, getPosition().y));
					 is_moving_right = true;
					 base_speed_applied_ = true; 
					 if (current_speed_x == 0)
					 {
						 current_speed_x = base_speed_;
					 }
				 }
			 }
			 //Si on ne peut pas bouger vers le haut, la base speed est tout de m�me affect� pour suivre la window
			 else if (base_speed_applied_ == false)
			 {
				 setPosition(Vector2f(getPosition().x + base_speed_, getPosition().y));
				 is_moving_right = true;
				 base_speed_applied_ = true;
				 if (current_speed_x == 0)
				 {
					 current_speed_x = base_speed_;
				 }
			 }
		}
		 //Si le joueur appuie sur la touche a
		 if (input_manager::get_input_manager()->get_a())
		{ 
			 //Projection du joueur vers la gauche
			 if(getPosition().x -speed_  >view.getCenter().x-view.getSize().x/2 )
			 {
				 //Le joueur bouge vers la gauche
				 setPosition(Vector2f(getPosition().x - speed_, getPosition().y));
				 is_moving_left = true;
				 if (current_speed_x == 0 || base_speed_ == 1)
				 {
					 current_speed_x += 0-speed_;
				 }
			 }
			 //Sinon on bouge avec la window
			 else if (base_speed_applied_ == false)
			 {
				 setPosition(Vector2f(getPosition().x + base_speed_, getPosition().y));
				 is_moving_right = true;
				 base_speed_applied_ = true;
				 if (current_speed_x == 0)
				 {
					 current_speed_x = base_speed_;
				 }
			 }
		}
		 //Si le joueur appuie sur s
		 if (input_manager::get_input_manager()->get_s())
		{
			 //Projection du joueur vers le bas
			 if (getPosition().y + speed_ + size_sprite_ < view.getCenter().y + view.getSize().y / 2)
			 {
				 //Le joueur bouge vers le bas
				 setPosition(Vector2f(getPosition().x, getPosition().y + speed_));
				 current_speed_y += speed_;
				 is_moving_down = true;
				 if(base_speed_applied_ == false)
				 {
					 setPosition(Vector2f(getPosition().x + base_speed_, getPosition().y));
					 is_moving_right = true;
					 base_speed_applied_ = true;
					 if (current_speed_x == 0)
					 {
						 current_speed_x = base_speed_;
					 }
				 }
			 }
			 else if (base_speed_applied_ == false)
			 {
				 setPosition(Vector2f(getPosition().x + base_speed_, getPosition().y));	
				 is_moving_right = true;
				 base_speed_applied_ = true;
				 if (current_speed_x == 0)
				 {
					 current_speed_x = base_speed_;
				 }
			 }
		}
	}
	else if (input_manager::get_input_manager()->get_d() == false && base_speed_applied_ == false)
	{
		setPosition(Vector2f(getPosition().x + base_speed_,getPosition().y));
		is_moving_right = true;
		base_speed_applied_ = true;
		if (current_speed_x == 0)
		{
			current_speed_x = base_speed_;
		}
	}
}

void player_character::visual_adjustments()
{
	 nb_movable_frames = 4;
	 nb_movable_anims = 1;

	int width = texture_player_character_.getSize().x / nb_movable_frames;
	int height = texture_player_character_.getSize().y / nb_movable_anims;

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
	width = 32;
	height = 32;
	// Adjust character collision points.
	top_left_point_ = Vector2f(4,0);
	top_right_point_ = Vector2f(width-4,0);
	left_upper_point_ = Vector2f(0, 8);
	left_lower_point_ = Vector2f(0, 26);
	bottom_left_point_ = Vector2f(12, height);
	bottom_right_point_ = Vector2f(width-12, height);
	right_upper_point_ = Vector2f(width, height*0.25f);
	right_lower_point_ = Vector2f(width, height*0.75f);

}

void player_character::draw(sf::RenderWindow& main_win)
{
	if (is_active_ == true)
	{
		main_win.draw(*this);
	}
}

float player_character::get_speed()
{
	if (input_manager::get_input_manager()->get_d() == true || input_manager::get_input_manager()->get_a() == true )
	{
		if(input_manager::get_input_manager()->get_a() == true)
		{
			return speed_ - (2 * speed_);
		}
		return speed_;
	}
	return base_speed_;
}

void player_character::set_health(int h)
{
	health_ = h;
}

void player_character::set_is_active(bool active)
{
	is_active_ = active;
}
