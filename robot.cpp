#include "robot.h"
#include "grid_coordinates.h"
#include <iostream>
using namespace std;

Robot::Robot()
{
	robot_.x_ = 1;
	robot_.y_ = 1;
	treasure_.x_ = 1;
	treasure_.y_ = 1;
	max_distance_ = 1;
	num_paths_ = 0;
	path_so_far_ = "";
}

Robot::Robot(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y)
{
	robot_.x_ = robot_x ;
	robot_.y_ = robot_y;
	treasure_.x_ = treasure_x;
	treasure_.y_ = treasure_y;
	max_distance_ = max_distance;
	num_paths_ = 0;
	path_so_far_ = "";
	CountPathLhs(robot_.x_, robot_.y_, treasure_.x_, treasure_.y_, path_so_far_);
	CountPathRhs(robot_.x_, robot_.y_, treasure_.x_, treasure_.y_, path_so_far_);
}

int Robot::RobotX() const
{
	return robot_.GetX();
}

int Robot::RobotY() const
{
	return robot_.GetY();
}

int Robot::TreasureX() const
{
	return treasure_.GetX();
}

int Robot::TreasureY() const
{
	return treasure_.GetY();
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

string Robot::GetPathSoFar() const
{
	return path_so_far_;
}

vector<string> Robot::GetRobotPath() const
{
	return robot_path_;
}

void Robot::SetPathSoFar(char& new_move)
{
	path_so_far_ += new_move;
}

void Robot::SetRobotPath(string& new_path)
{
	robot_path_.push_back(new_path);
}

bool Robot::CheckValidMove(string& path_so_far, char& move) const
{
	int counter = 0;
	if ((path_so_far.length() == 0) || ((GetMaxDistance() > 1) && (path_so_far.length() == 1)))
	{
		return true;
	}
	for (int i = path_so_far.length() - 1; i >= 0; i--)
	{
		if (path_so_far.at(i) == move)
		{
			counter++;
		}
		else if (path_so_far.at(i) != move)
		{
			break;
		}
	}
	return counter <= GetMaxDistance();
}

void Robot::CountPathRhs(int robot_x, int robot_y, int treasure_x, int treasure_y, string path_so_far)
{
}

void Robot::CountPathLhs(int robot_x, int robot_y, int treasure_x, int treasure_y, string path_so_far)
{
}

void Robot::PrintTotalPath() const
{
	if ((RobotX() == TreasureX()) && (RobotY() == TreasureY()))
	{
		cout << "Number of path: 0" << endl;
	}
	else 
	{
		cout << "Number of path: " << GetTotalPaths() << endl;
	}
}
