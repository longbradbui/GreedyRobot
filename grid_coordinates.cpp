#include "grid_coordinates.h"
#include <iostream>
using namespace std;

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

int Coordinates::GetX() const
{
	return x_;
}

int Coordinates::GetY() const
{
	return y_;
}

void Coordinates::SetX(int x)
{
	x_ = x;
}

void Coordinates::SetY(int y)
{
	y_ = y;
}

Coordinates& Coordinates::operator+=(const Coordinates& rhs)
{
	x_ = this->GetX() + rhs.GetX();
	y_ = this->GetY() + rhs.GetY();
	return *this;
}

Coordinates& Coordinates::operator-=(const Coordinates& rhs)
{
	x_ = this->GetX() - rhs.GetX();
	y_ = this->GetY() - rhs.GetY();
	return *this;
}

Coordinates Coordinates::operator+(const Coordinates& rhs) const
{
	Coordinates temp = *this;
	temp += rhs;
	return temp;
}

Coordinates Coordinates::operator-(const Coordinates& rhs) const
{
	Coordinates temp = *this;
	temp += rhs;
	return temp;
}
