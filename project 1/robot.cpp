#include "robot.h"
#include <iostream>

point coords_to_point(int x, int y)
{
	point res;
	res.x = x;
	res.y = y;
	return res;
}

void current_direction_output(direction dir)
{
	switch (dir) {
	case NORTH:
		std::cout << "North";
		break;
	case EAST:
		std::cout << "East";
		break;
	case SOUTH:
		std::cout << "South";
		break;
	case WEST:
		std::cout << "West";
		break;
	}
}

Robot::Robot(std::string label, int posx, int posy) : m_label(label), m_position(coords_to_point(posx, posy)), m_battery_level(100), m_dir(NORTH) {}

void Robot::turn_left()
{
	switch (m_dir) {
	case NORTH:
		m_dir = WEST;
		break;
	case WEST:
		m_dir = SOUTH;
		break;
	case SOUTH:
		m_dir = EAST;
		break;
	case EAST:
		m_dir = NORTH;
		break;
	}

	std::cout << "The robot has turned left and is now facing ";
	current_direction_output(m_dir);
	std::cout << std::endl;
}

void Robot::turn_right()
{
	switch (m_dir) {
	case NORTH:
		m_dir = EAST;
		break;
	case WEST:
		m_dir = NORTH;
		break;
	case SOUTH:
		m_dir = WEST;
		break;
	case EAST:
		m_dir = SOUTH;
		break;
	}

	std::cout << "The robot has turned right and is now facing ";
	current_direction_output(m_dir);
	std::cout << ".\n";
}

void Robot::move_forward(unsigned int dist)
{
	if (dist > m_battery_level) {
		std::cout << "The battery level is too low to complete the move.\n";
		return;
	}

	switch (m_dir) {
	case NORTH:
		m_position.x += dist;
		break;
	case WEST:
		m_position.y -= dist;
		break;
	case SOUTH:
		m_position.x -= dist;
		break;
	case EAST:
		m_position.y += dist;
		break;
	}

	m_battery_level -= dist;

	std::cout << "The robot has moved forward by " << dist << ". His current location is now (" << m_position.x << ", " << m_position.y << ").\n";
}

void Robot::move_backwards(unsigned int dist)
{
	if (dist > m_battery_level) {
		std::cout << "The battery level is too low to complete the move.\n";
		return;
	}

	switch (m_dir) {
	case NORTH:
		m_position.x -= dist;
		break;
	case WEST:
		m_position.y += dist;
		break;
	case SOUTH:
		m_position.x += dist;
		break;
	case EAST:
		m_position.y -= dist;
		break;
	}

	m_battery_level -= dist;

	std::cout << "The robot has moved backwards by " << dist << ". His current location is now (" << m_position.x << ", " << m_position.y << ").\n";
}

void Robot::recharge()
{
	m_battery_level = 100;
	std::cout << "The robot has been succesfully recharged!\n";
}

void Robot::get_info()
{
	std::cout << m_label << ":\n";
	std::cout << " Battery level: " << m_battery_level << std::endl;
	std::cout << " Position: (" << m_position.x << ", " << m_position.y << ")\n";
	std::cout << " Direction: ";
	current_direction_output(m_dir);
	std::cout << std::endl;
}

