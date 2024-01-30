#include <iostream>
#include "robot.h"
#include "grid_coordinates.h"
using namespace std;

int main()
{
    cout << "Hello World!\n";
    Robot r(2,1,2,3,5);
    cout << r.GetShortestPath() << endl;
    cout << r.GetMaxDistance() << endl;
    cout << r.GetTotalPaths() << endl;
    cout << r.RobotX() << endl;
    cout << r.RobotY() << endl;
    cout << r.TreasureX() << endl;
    cout << r.TreasureY() << endl;
    cout << r.PathSoFar() << endl; // this is currently an empty string
    return 0;
}
