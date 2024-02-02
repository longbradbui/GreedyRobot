#ifndef GRID_COORDINATES_H_
#define GRID_COORDINATES_H_
using namespace std;

class Coordinates
{
public:
	// Contructors
	Coordinates();
	Coordinates(int x, int y);
	// Setters and Getters
	int GetX() const;
	int GetY() const;
	void SetX(int x);
	void SetY(int y);
	// Operator Overloading
	Coordinates& operator+=(const Coordinates& rhs);
	Coordinates& operator-=(const Coordinates& rhs);
	Coordinates operator+(const Coordinates& rhs) const;
	Coordinates operator-(const Coordinates& rhs) const;
	bool operator==(const Coordinates& rhs) const;
	bool operator!=(const Coordinates& rhs) const;

private:
	// Represents x and y coordinates of Robot and Treasure
	int x_;
	int y_;
};
#endif

