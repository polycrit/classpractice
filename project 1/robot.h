#pragma once

#include <string>

struct point {
	int x;
	int y;
};

enum direction {
	NORTH, EAST, SOUTH, WEST
};

point coords_to_point(int, int);
void current_direction_output(direction);

class Robot
{
private:
	unsigned int m_battery_level;
	point m_position;
	std::string m_label;
	direction m_dir;
	
public:
	Robot(std::string label = "none", int posx = 0, int posy = 0);
	void turn_right();
	void turn_left();
	void move_forward(unsigned int dist);
	void move_backwards(unsigned int dist);
	void recharge();
	void get_info();
};

