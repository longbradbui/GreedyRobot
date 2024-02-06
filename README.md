# GreedyRobot
A robot is positioned on an integral point in a two-dimensional coordinate grid (xr, yr). There is
a treasure that has been placed at a point in the same grid at (xt, yt). All x’s and y’s will be
integral values. The robot can move up (North), down (South), left (West), or right (East).
Commands can be given to the robot to move one position in one of the four direction. That is,
“E” moves a robot one slot East (to the right) so if the robot was on position (3, 4), it would now
be on (4, 4). The command N would move the robot one position north so a robot at position
(4, 4) would be at (4, 5).
Because the robot cannot move diagonally, the shortest distance between a robot at (xr, yr) and
a treasure at (xt, yt) is
| xr – xt | + | yr - yt | = ShortestPossibleDistance
Write a recursive program which determines all the unique shortest possible paths from the
robot to the treasure with the following stipulation: The robot may never move in the same
direction more than max_distance times in a row.
The input to the program will be the max_distance value followed by the position of the robot
(xr, yr), followed by the position of the treasure (xt, yt). Assume that all five are integers and do
not worry about error conditions in inputs. Take these parameters as arguments to the
program on the command line.
Invoking greed_robot:
% greedy_robot max_distance robot_x robot_y treasure_x treasure_y
max_distance: maximum number of moves in one direction before a turn is required
robot_x: starting X coordinate of robot
robot_y: starting Y coordinate of robot
treasure_x: X coordinate of treasure
treasure_y: Y coordinate of treasure
