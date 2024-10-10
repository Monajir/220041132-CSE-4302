#include "Coordinate.h"
#include <cmath>
#include <iostream>

using namespace std;

Coordinate::Coordinate() {
	x = 0;
	y = 0;
}

Coordinate::Coordinate(float abs, float ord) {
	x = abs;
	y = ord;
}

void Coordinate::display() const{
	cout << "X: " << x << " Y: " << y << " " << getDistance() << endl;
}

Coordinate::~Coordinate() {

}

float Coordinate::operator-(Coordinate c)
{
	float dis = sqrt((x-c.x)*(x-c.x) + (y - c.y)*(y - c.y));
	return dis;
}
float Coordinate::getDistance() const {
	float dis = sqrt(x * x + y * y);
	return dis;
}

void Coordinate::move_x(float val) {
	x += val;
}

void Coordinate::move_y(float val) {
	y += val;
}

void Coordinate::move(float x_val, float y_val) {
	x += x_val;
	y += y_val;
}

bool Coordinate::operator >(Coordinate& c) {
	return (getDistance() > c.getDistance()) ? true : false;
}

bool Coordinate::operator <(Coordinate& c) {
	return (getDistance() < c.getDistance()) ? true : false;
}

bool Coordinate::operator >=(Coordinate& c) {
	return (getDistance() >= c.getDistance()) ? true : false;
}

bool Coordinate::operator <=(Coordinate& c) {
	return (getDistance() <= c.getDistance()) ? true : false;
}

bool Coordinate::operator ==(Coordinate& c) {
	return (getDistance() == c.getDistance()) ? true : false;
}

bool Coordinate::operator !=(Coordinate& c) {
	return (getDistance() != c.getDistance()) ? true : false;
}