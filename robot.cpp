#include "robot.h"
#include "grid_coordinates.h"
#include <iostream>
using namespace std;

static const Coordinates North(0, 1);
static const Coordinates South(0, -1);
static const Coordinates East(1, 0);
static const Coordinates West(-1, 0);

Robot::Robot()
{
	robot_.SetX(0);
	robot_.SetY(0);
	treasure_.SetX(0);
	treasure_.SetY(0);
	max_distance_ = 1;
	path_so_far_ = "";
	new_move_ = "";
	int path = CountPaths(robot_, treasure_, path_so_far_, new_move_);
	PrintAllPath();
	PrintTotalPath(path);
}

Robot::Robot(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y)
{
	robot_.SetX(robot_x);
	robot_.SetY(robot_y);
	treasure_.SetX(treasure_x);
	treasure_.SetY(treasure_y);
	max_distance_ = max_distance;
	path_so_far_ = "";
	new_move_ = "";
	int path = CountPaths(robot_, treasure_, path_so_far_, new_move_);
	PrintAllPath();
	PrintTotalPath(path);
}

int Robot::GetMaxDistance() const
{
	return max_distance_;
}

int Robot::GetShortestPath() const
{
	return (abs(robot_.GetX() - treasure_.GetX()) + abs(robot_.GetY() - treasure_.GetY()));
}

string Robot::GetPathSoFar() const
{
	return path_so_far_;
}

vector<string> Robot::GetRobotPath() const
{
	return robot_path_;
}

void Robot::SetRobotPath(string& new_path)
{
	robot_path_.push_back(new_path);
}

bool Robot::IsValidMove(const string& path_so_far, string& move) const
{
	int counter = 0;
	if (path_so_far.empty() || (GetMaxDistance() > 1 && path_so_far.length() == 1))
	{
		return true;
	}
	for (int i = path_so_far.length() - 1; i >= 0; i--)
	{
		if (path_so_far.substr(i, 1) == move)
		{
			counter++;
		}
		else
		{
			break;
		}
	}
	return counter <= GetMaxDistance();
}

int Robot::CountPaths(Coordinates robot, Coordinates treasure, string path_so_far, string new_move)
{
	path_so_far += new_move;
	if (path_so_far.length() > GetShortestPath() || !IsValidMove(path_so_far, new_move))
	{
		return 0;
	}
	else if ((robot == treasure) && IsValidMove(path_so_far, new_move))
	{
		SetRobotPath(path_so_far);
		return 1;
	}
	else
	{
		if ((treasure.GetX() < robot.GetX()) && (treasure.GetY() > robot.GetY()))
		{
			return CountPaths(robot + North, treasure, path_so_far, "N") + CountPaths(robot + West, treasure, path_so_far, "W");
		}
		else if ((treasure.GetX() > robot.GetX()) && (treasure.GetY() > robot.GetY()))
		{
			return CountPaths(robot + North, treasure, path_so_far, "N") + CountPaths(robot + East, treasure, path_so_far, "E");
		}
		else if ((treasure.GetX() > robot.GetX()) && (treasure.GetY() < robot.GetY()))
		{
			return CountPaths(robot + South, treasure, path_so_far, "S") + CountPaths(robot + East, treasure, path_so_far, "E");
		}
		else if ((treasure.GetX() < robot.GetX()) && (treasure.GetY() < robot.GetY()))
		{
			return CountPaths(robot + South, treasure, path_so_far, "S") + CountPaths(robot + West, treasure, path_so_far, "W");
		}		
		else if ((treasure.GetX() == robot.GetX()) && (treasure.GetY() > robot.GetY()))
		{
			return CountPaths(robot + North, treasure, path_so_far, "N");
		}
		else if ((treasure.GetX() == robot.GetX()) && (treasure.GetY() < robot.GetY()))
		{
			return CountPaths(robot + South, treasure, path_so_far, "S");
		}
		else if ((treasure.GetX() < robot.GetX()) && (treasure.GetY() == robot.GetY()))
		{
			return CountPaths(robot + West, treasure, path_so_far, "W");
		}
		else if ((treasure.GetX() > robot.GetX()) && (treasure.GetY() == robot.GetY()))
		{
			return CountPaths(robot + East, treasure, path_so_far, "E");
		}
	}
	return 0;
}

void Robot::PrintTotalPath(int path) const
{
	if (robot_ == treasure_)
	{
		cout << "Number of path: 0" << endl;
	}
	else 
	{
		cout << "Number of paths: " << path << endl;
	}
}

bool Robot::PrintAllPath() const
{
	if (robot_path_.empty())
	{
		return false;
	}
	else
	{
		for (const string& path : robot_path_)
		{
			cout << path << endl;
		}
		return true;
	}
}
