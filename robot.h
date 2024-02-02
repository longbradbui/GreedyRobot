#ifndef ROBOT_H_
#define ROBOT_H_
#include "grid_coordinates.h"
#include <vector>
#include <string>
using namespace std;

class Robot
{
public:
	// Constructor
	Robot();
	Robot(int max_distance, int robot_x, int robot_y, int treasure_x, int treasure_y);
	// Setters and Getters
	int GetMaxDistance() const;
	int GetShortestPath() const;
	void SetRobotPath(string& new_path);
	// Actions
	void PrintTotalPath(int path) const;
	bool DisplayPath() const;
	bool IsValidMove(const string& path_so_far, string& move) const;
	int CountPaths(Coordinates robot, Coordinates treasure, string path_so_far, string new_move);

private:
	int max_distance_;
	string path_so_far_;
	string new_move_;
	vector<string> robot_path_;
	// Robot and Treasure are instances of Coordinates
	Coordinates robot_;
	Coordinates treasure_;
};

#endif

