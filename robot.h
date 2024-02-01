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
	int GetMaxDistance() const;
	int GetShortestPath() const;
	string GetPathSoFar() const;
	vector<string> GetRobotPath() const;
	void PrintTotalPath(int path) const;
	bool PrintAllPath() const;
	void SetRobotPath(string& new_path);
	bool CheckValidMove(const string& path_so_far, string& move) const;
	int CountPaths(Coordinates robot, Coordinates treasure, string path_so_far, string new_move);

private:
	int max_distance_;
	string path_so_far_;
	vector<string> robot_path_;
	Coordinates robot_;
	Coordinates treasure_;
};

#endif

