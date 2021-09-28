#include <iostream>
#include "robot.h"

int main(void)
{
	Robot robot("robby", 0, 0);
	robot.get_info();
	robot.move_forward(20);
	robot.turn_left();
	robot.move_backwards(40);
	robot.turn_right();
	robot.move_backwards(100);
	robot.recharge();
	robot.move_backwards(100);
	robot.get_info();
}
