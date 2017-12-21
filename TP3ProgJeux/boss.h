#pragma once
#pragma once
#include "enemy.h"
#include "kamikaze_factory.h"
class kamikaze;

class boss : public enemy
{
public:
	// Overload Constructor
	boss(Vector2f position);
	void update(std::vector<kamikaze>& kamikazes);
	void set_texture();
	void move(View view);
	void visual_adjustments();
	static Texture texture_boss_;
	void draw(sf::RenderWindow& main_win);
	bool check_range();
	kamikaze spawn_kamikaze();
	bool get_range();
	bool get_is_triggered();
	void set_is_triggered(bool triggered);
	void set_counter(int counter);
	int get_fire_rate();
	int get_fire_rate_counter();


private:
	int spawn_rate_;
	int spawn_rate_counter;
	int fire_rate_;
	int fire_rate_counter_;

	kamikaze_factory kamikaze_factory_;
	Vector2f position_1_;
	Vector2f position_2_;
	Vector2f position_3_;
	Vector2f base_position_;
	bool triggered_;
	bool range_;
	int anim_delay;
	int anim_delay_counter;
	int last_position_;
	bool is_moving_down;
	bool is_moving_up;

};