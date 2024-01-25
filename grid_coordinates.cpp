#include "grid_coordinates.h"

Coordinates::Coordinates()
{
	SetX(0);
	SetY(0);
}

Coordinates::Coordinates(int x, int y)
{
	SetX(x);
	SetY(y);
}

int Coordinates::x() const
{
	return x_;
}

int Coordinates::y() const
{
	return y_;
}

void Coordinates::SetX(int x)
{
	this->x_ = x;
}

void Coordinates::SetY(int y)
{
	this->y_ = y;
}
