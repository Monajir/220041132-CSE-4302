#include "Celsius.h"
#include "Fahrenheit.h" 
#include "Kelvin.h"      
#include <iostream>
using namespace std;


Celsius::Celsius() {
    temp = 0;
}

Celsius::Celsius(float val) {
    if (val >= -273) {
        temp = val;
    }
}


void Celsius::assign(float val) {
    if (val >= -273) {
        temp = val;
    }
}


void Celsius::display() const {
    cout << "The temperature is " << temp << " Celsius" << endl;
}


Fahrenheit Celsius::toFahrenheit() {
    return Fahrenheit(temp * 9 / 5 + 32);
}


Kelvin Celsius::toKelvin() {
    return Kelvin(temp + 273);
}
