#ifndef ROBOT_H_
#define ROBOT_H_
#include "grid_coordinates.h"
#include <vector>
#include <string>
using namespace std;

class Robot
{
public:
	Robot();
	Robot(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y);
	int RobotX() const;
	int RobotY() const;
	int TreasureX() const;
	int TreasureY() const;
	int GetTotalPaths() const;
	int GetMaxDistance() const;
	int GetShortestPath() const;
	string PathSoFar() const;
	vector<string> RobotPath() const;
	void SetPathSoFar(string& new_move);
	void SetRobotPath(string& new_path);

private:
	int max_distance_;
	int num_paths_;
	int shortest_path_;
	string path_so_far_;
	vector<string> robot_path_;
	Coordinates robot_location_;
	Coordinates treasure_location_;
};

#endif

