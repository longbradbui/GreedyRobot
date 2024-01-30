#include "robot.h"
#include "grid_coordinates.h"
#include <iostream>
using namespace std;

Robot::Robot()
{
	max_distance_ = 1;
	robot_location_.SetX(1);
	robot_location_.SetY(1);
	treasure_location_.SetX(1);
	treasure_location_.SetY(1);
}

Robot::Robot(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y)
{
	max_distance_ = max_distance;
	robot_location_.SetX(robot_x);
	robot_location_.SetY(robot_y);
	treasure_location_.SetX(treasure_x);
	treasure_location_.SetY(treasure_y);
}

int Robot::RobotX() const
{
	return robot_location_.GetX();
}

int Robot::RobotY() const
{
	return robot_location_.GetY();
}

int Robot::TreasureX() const
{
	return treasure_location_.GetX();
}

int Robot::TreasureY() const
{
	return treasure_location_.GetY();
}

int Robot::GetTotalPaths() const
{
	return num_paths_;
}

int Robot::GetMaxDistance() const
{
	return max_distance_;
}

int Robot::GetShortestPath() const
{
	return (abs(RobotX() - TreasureX()) + abs(RobotY() - TreasureY()));
}
