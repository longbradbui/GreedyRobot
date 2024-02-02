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
	DisplayPath();
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
	DisplayPath();
	PrintTotalPath(path);
}

/* Return the shortest, possible number of moves for the given Coordinates of Robot and Treasure */
int Robot::GetShortestPath() const
{
	return (abs(robot_.GetX() - treasure_.GetX()) + abs(robot_.GetY() - treasure_.GetY()));
}

/* Return the Max Distance in one direction */
int Robot::GetMaxDistance() const
{
	return max_distance_;
}

/* Append the new path to the vector holding all possible paths */
void Robot::SetRobotPath(string& new_path)
{
	robot_path_.push_back(new_path);
}

/* Validate the move before adding to the current path */
bool Robot::IsValidMove(const string& path_so_far, string& move) const
{
	int counter = 0; // Initalize a flag to keep track of the state of the counting procedure
	// Always "true" when the current path is empty or length of current path equals 1 (with max distance greater than 1)
	if (path_so_far.empty() || (GetMaxDistance() > 1 && path_so_far.length() == 1))
	{
		return true;
	}
	// Counting backwards, if the extracted character matches the new move more than "max_distance" times, consider a false
	for (int i = path_so_far.length() - 1; i >= 0; i--)
	{
		if (path_so_far.substr(i, 1) == move)
		{
			counter++;
		}
		// Break out of the loop when the extracted character and move are unmatched
		else
		{
			break;
		}
	}
	return counter <= GetMaxDistance();
}

/* Recursive Function: Compute the possible paths for given Robot and Treasure coordinates*/
int Robot::CountPaths(Coordinates robot, Coordinates treasure, string path_so_far, string new_move)
{
	path_so_far += new_move;
	if ((path_so_far.length() > GetShortestPath()) || (!IsValidMove(path_so_far, new_move)))
	{
		return 0;
	}
	else if ((robot == treasure) && (IsValidMove(path_so_far, new_move)))
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

/* In this version, the "endl" keyword is only printed after each path if it is not the last path in the robot_path_ vector.
This way, I can avoid printing an extra newline after the last path, especially when working with empty vector. */
bool Robot::DisplayPath() const
{
	if (robot_path_.empty())
	{
		return false;
	}
	else
	{
		for (auto iterator = robot_path_.begin(); iterator != robot_path_.end(); ++iterator)
		{
			cout << *iterator;
			if (iterator != robot_path_.end())
			{
				cout << endl;
			}
		}
		return true;
	}
}

/* Print the total of possible paths from robot to the treasure */
void Robot::PrintTotalPath(int path) const
{
	/* This "if" statement checks out the condition when the initial coordinates of Robot and Treasure are identical */
	if (robot_ == treasure_)
	{
		cout << "Number of path: 0" << endl;
	}
	/* "path" is returned from the recursive function CountPaths */
	else
	{
		cout << "Number of paths: " << path << endl;
	}
}


