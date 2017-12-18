#include"bonus_manager.h"

bonus_manager * bonus_manager::bonus_manager_ = nullptr;

bonus_manager::bonus_manager() :chance_(9), last_bonus(-1)
{
	
}

void bonus_manager::update(sf::View view)
{
	if (bomb_launcher_bonus_.get_is_active() == true)
	{
		bomb_launcher_bonus_.update(view);
	}

	if (vie_bonus_.get_is_active() == true)
	{
		vie_bonus_.update(view);
	}

	if (nuke_bonus_.get_is_active() == true)
	{
		nuke_bonus_.update(view);
	}

	if (laser_bonus_.get_is_active() == true)
	{
		laser_bonus_.update(view);
	}

	if (point_bonus_.get_is_active() == true)
	{
		point_bonus_.update(view);
	}
}

void bonus_manager::draw(sf::RenderWindow& main_win)
{
	if (bomb_launcher_bonus_.get_is_active() == true)
	{
		bomb_launcher_bonus_.draw(main_win);
	}

	if (vie_bonus_.get_is_active() == true)
	{
		vie_bonus_.draw(main_win);
	}

	if (nuke_bonus_.get_is_active() == true)
	{
		nuke_bonus_.draw(main_win);
	}

	if (laser_bonus_.get_is_active() == true)
	{
		laser_bonus_.draw(main_win);
	}

	if (point_bonus_.get_is_active() == true)
	{
		point_bonus_.draw(main_win);
	}
}

void bonus_manager::Release()
{
	delete bonus_manager_;
	bonus_manager_ = nullptr;
	point_bonus_.Release();
}

bool bonus_manager::load_textures(
	const char bomb_launcher_bonus_path[],
	const char vie_bonus_path[],
	const char nuke_bonus_path[],
	const char point_bonus_path[],
	const char laser_bonus_path[],
	const char automatic_bonus_path[])
{
	if (!bomb_launcher_bonus_.load_textures(bomb_launcher_bonus_path, bomb_launcher_bonus::texture_bomb_launcher_bonus))
	{
		return false;
	}
	if (!vie_bonus_.load_textures(vie_bonus_path, vie_bonus::texture_vie_bonus))
	{
		return false;
	}
	if (!nuke_bonus_.load_textures(nuke_bonus_path, nuke_bonus::texture_nuke_bonus))
	{
		return false;
	}
	if (!point_bonus_.load_textures(point_bonus_path, point_bonus::texture_point_bonus))
	{
		return false;
	}
	if (!laser_bonus_.load_textures(laser_bonus_path, laser_bonus::texture_laser_bonus))
	{
		return false;
	}
	if (!automatic_bonus_.load_textures(automatic_bonus_path, automatic_bonus::texture_automatic_bonus))
	{
		return false;
	}

	return true;
}

void bonus_manager::init()
{
	bomb_launcher_bonus_.visual_adjustments();
	bomb_launcher_bonus_.set_texture();

	vie_bonus_.visual_adjustments();
	vie_bonus_.set_texture();

	point_bonus_.visual_adjustments();
	point_bonus_.set_texture();

	nuke_bonus_.visual_adjustments();
	nuke_bonus_.set_texture();

	laser_bonus_.visual_adjustments();
	laser_bonus_.set_texture();

	automatic_bonus_.visual_adjustments();
	automatic_bonus_.set_texture();
}

bonus_manager* bonus_manager::get_bonus_manager()
{
	if (!bonus_manager_)
		bonus_manager_ = new bonus_manager;
	return bonus_manager_;
}

bool bonus_manager::collision(movable* movable1)
{
	if (bomb_launcher_bonus_.get_is_active() == true)
	{
		if (bomb_launcher_bonus_.collision(movable1) == true)
		{
			last_bonus = 3;
			bomb_launcher_bonus_.set_is_active(false);
			return true;
		}
	}
	else if (nuke_bonus_.get_is_active() == true)
	{
		if (nuke_bonus_.collision(movable1))
		{
			last_bonus = 4;
			nuke_bonus_.set_is_active(false);
			return true;
		}
	}
	else if (point_bonus_.get_is_active() == true)
	{
		if (point_bonus_.collision(movable1) == true)
		{
			last_bonus = 1;
			point_bonus_.set_is_active(false);
			return true;
		}
	}
	else if (vie_bonus_.get_is_active() == true)
	{
		if (vie_bonus_.collision(movable1) == true)
		{
			last_bonus = 0;
			vie_bonus_.set_is_active(false);
			return true;
		}
	}
	else if (laser_bonus_.get_is_active() == true)
	{
		if (laser_bonus_.collision(movable1) == true)
		{
			last_bonus = 2;
			laser_bonus_.set_is_active(false);
			return true;
		}
	}
	else if (automatic_bonus_.get_is_active() == true)
	{
		if (automatic_bonus_.collision(movable1) == true)
		{
			last_bonus = 5;
			automatic_bonus_.set_is_active(false);
			return true;
		}
	}
	return false;
}

void bonus_manager::spawn_bonus_(Vector2f position)
{
	int random_number = rand() % 10;

	if (chance_ == random_number)
	{
		random_number = rand() % 5;
		switch (random_number)
		{
		case 0:bomb_launcher_bonus_.spawn_bonus(position);
			break;
		case 1:vie_bonus_.spawn_bonus(position);
			break;
		case 2:point_bonus_.spawn_bonus(position);
			break;
		case 3:nuke_bonus_.spawn_bonus(position);
			break;
		case 4:laser_bonus_.spawn_bonus(position);
			break;
		case 5:automatic_bonus_.spawn_bonus(position);
			break;
		default:;
		}
	}
}
