#include "Kelvin.h"
#include "Celsius.h"    
#include "Fahrenheit.h" 
#include <iostream>
using namespace std;


Kelvin::Kelvin() {
    temp = 0;
}

Kelvin::Kelvin(float val) {
    if (val >= 0) {
        temp = val;
    }
}


void Kelvin::assign(float val) {
    if (val >= 0) {
        temp = val;
    }
}


void Kelvin::display() const {
    cout << "The temperature is " << temp << " Kelvin" << endl;
}


Celsius Kelvin::toCelsius() {
    return Celsius(temp - 273.15);
}


Fahrenheit Kelvin::toFahrenheit() {
    return Fahrenheit((temp - 273.15) * 9 / 5 + 32);
}
