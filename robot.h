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
	string GetPathSoFar() const;
	vector<string> GetRobotPath() const;
	void PrintTotalPath() const;
	void SetPathSoFar(char& new_move);
	void SetRobotPath(string& new_path);
	bool CheckValidMove(string& path_so_far, char& move) const;
	int CountPaths(Coordinates robot_, Coordinates treasure_, string path_so_far, int max_distance, int shortest_path);

private:
	int max_distance_;
	int num_paths_;
	int shortest_path_;
	string path_so_far_;
	vector<string> robot_path_;
	Coordinates robot_;
	Coordinates treasure_;
};

#endif

