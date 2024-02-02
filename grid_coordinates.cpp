#include "grid_coordinates.h"
#include <iostream>
using namespace std;

Coordinates::Coordinates() : x_(0), y_(0)
{
}

Coordinates::Coordinates(int x, int y) : x_(x), y_(y)
{
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
	x_ = this->x_ + rhs.x_;
	y_ = this->y_ + rhs.y_;
	return *this;
}

Coordinates& Coordinates::operator-=(const Coordinates& rhs)
{
	x_ = this->x_ - rhs.x_;
	y_ = this->y_ - rhs.y_;
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

bool Coordinates::operator==(const Coordinates& rhs) const
{
	return ((this->x_ == rhs.x_) && (this->y_ == rhs.y_));
}

bool Coordinates::operator!=(const Coordinates& rhs) const
{
	return !(*this == rhs);
}
