#ifndef GRID_COORDINATES_H_
#define GRID_COORDINATES_H_
class Coordinates
{
public:
	Coordinates();
	Coordinates(int x, int y);
	int x() const;
	int y() const;
	void SetX(int x);
	void SetY(int y);

private:
	int x_;
	int y_;
};
#endif

