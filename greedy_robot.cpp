#include <iostream>
#include <string>
#include <cstdlib>
#include "robot.h"
#include "grid_coordinates.h"
using namespace std;

int main(int argc, char* argv[])
{
    int max_distance = stoi(argv[1]);
    int robot_x = stoi(argv[2]);
    int robot_y = stoi(argv[3]);
    int treasure_x = stoi(argv[4]);
    int treasure_y = stoi(argv[5]);
    Robot r(max_distance, robot_x, robot_y, treasure_x, treasure_y);
    return 0;
}
