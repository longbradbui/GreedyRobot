#ifndef GRID_COORDINATES_H_
#define GRID_COORDINATES_H_
using namespace std;

class Coordinates
{
public:
	int x_;
	int y_;
	Coordinates();
	Coordinates(int x, int y);
	Coordinates& operator+=(const Coordinates& rhs);
	Coordinates& operator-=(const Coordinates& rhs);
	Coordinates operator+(const Coordinates& rhs) const;
	Coordinates operator-(const Coordinates& rhs) const;
	bool operator==(const Coordinates& rhs) const;
	bool operator!=(const Coordinates& rhs) const;
	
};
#endif

