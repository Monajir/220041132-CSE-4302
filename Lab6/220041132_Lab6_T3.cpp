#include<iostream>
#include "Celsius.h"
#include "Fahrenheit.h"
#include "Kelvin.h"

using namespace std;


int main() {
	Celsius c1(50);
	Kelvin k(100);
	Fahrenheit f(100);

	Kelvin k1 = c1.toKelvin();
	Fahrenheit f1 = c1.toFahrenheit();

	c1.display();
	k.display();
	f.display();
	k1.display();
	f1.display();
}