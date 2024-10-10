#pragma once
class Coordinate
{
private:
	float x;
	float y;
public:
	Coordinate();
	Coordinate(float abs, float ord);
	void display() const;
	float operator-(Coordinate c);
	float getDistance() const;
	void move_x(float val);
	void move_y(float val);
	void move(float x_val, float y_val);
	bool operator >(Coordinate& c);
	bool operator <(Coordinate& c);
	bool operator >=(Coordinate& c);
	bool operator <=(Coordinate& c);
	bool operator ==(Coordinate& c);
	bool operator !=(Coordinate& c);


	~Coordinate();
};

