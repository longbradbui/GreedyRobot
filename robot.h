#ifndef ROBOT_H_
#define ROBOT_H_
#include "grid_coordinates.h"
class Robot
{
public:

	int RobotX() const;
	int RobotY() const;
	int TreasureX() const;
	int TreasureY() const;
	void SetRobotLocation(int x, int y);
	void SetTreasureLocaation(int x, int y);

private:
	int max_distance_;
	int num_paths_;
	Coordinates robot_location_;
	Coordinates treasure_location_;
};
#endif

