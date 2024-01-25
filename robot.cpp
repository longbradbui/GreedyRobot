#include "robot.h"
#include "grid_coordinates.h"
#include <iostream>
using namespace std;

int Robot::RobotX() const
{
	return robot_location_.x();
}

int Robot::RobotY() const
{
	return robot_location_.y();
}

int Robot::TreasureX() const
{
	return treasure_location_.x();
}

int Robot::TreasureY() const
{
	return treasure_location_.y();
}

void Robot::SetRobotLocation(int x, int y)
{
	robot_location_.SetX(x);
	robot_location_.SetY(y);
}

void Robot::SetTreasureLocaation(int x, int y)
{
	treasure_location_.SetX(x);
	treasure_location_.SetY(y);
}
