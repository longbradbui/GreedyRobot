#ifndef GRID_COORDINATES_H_
#define GRID_COORDINATES_H_
using namespace std;

class Coordinates
{
public:
	Coordinates();
	Coordinates(int x, int y);
	int GetX() const;
	int GetY() const;
	void SetX(int x);
	void SetY(int y);
	Coordinates& operator+=(const Coordinates& rhs);
	Coordinates& operator-=(const Coordinates& rhs);
	Coordinates operator+(const Coordinates& rhs) const;
	Coordinates operator-(const Coordinates& rhs) const;

private:
	int x_;
	int y_;
};

#endif

