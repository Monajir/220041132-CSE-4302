#include "Counter.h"
#include <iostream>

using namespace std;

Counter::Counter() {
	count = 0;
	IncStep = 1;
}

Counter::Counter(int val) {
	count = val;
	IncStep = 1;
}

void Counter::setIncrementStep(int val)
{
	if (count == 0) {
		if (val > 0) {
			IncStep = val;
		}
	}
	else {
		cout << "Cannot assign" << endl;
	}
}

int Counter::getCount() const{
	return count;
}

void Counter::increment() {
	count += IncStep;
}

void Counter::resetCount(int step) {
	count = 0;
	IncStep = step;
}

Counter Counter::operator+(Counter& c) const{
	if (IncStep == c.IncStep) {
		Counter temp;
		temp.IncStep = IncStep;
		temp.count = count + c.count;

		return temp;
	}
	else {
		cout << "Increment steps are not same." << endl;
	}
}

bool Counter::operator>(Counter& c) const{
	return (count > c.count) ? true : false;
}

bool Counter::operator<(Counter& c) const {
	return (count < c.count) ? true : false;
}

bool Counter::operator>=(Counter& c) const {
	return (count >= c.count) ? true : false;
}

bool Counter::operator<=(Counter& c) const {
	return (count <= c.count) ? true : false;
}

bool Counter::operator==(Counter& c) const {
	return (count == c.count) ? true : false;
}

bool Counter::operator!=(Counter& c) const {
	return (count != c.count) ? true : false;
}

void Counter::operator+=(Counter& c) {
	count += c.count;
	IncStep = max(IncStep, c.IncStep);
}

Counter Counter::operator++() {
	return Counter(++count);
}

Counter Counter::operator++(int) {
	return Counter(count++);
}