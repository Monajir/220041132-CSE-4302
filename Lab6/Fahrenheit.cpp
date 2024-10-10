#include "Fahrenheit.h"
#include "Celsius.h"   
#include "Kelvin.h"    
#include <iostream>
using namespace std;


Fahrenheit::Fahrenheit() {
    temp = 0;
}

Fahrenheit::Fahrenheit(float val) {
    if (val >= -459.67) {
        temp = val;
    }
}


void Fahrenheit::assign(float val) {
    if (val >= -459.67) {
        temp = val;
    }
}


void Fahrenheit::display() const {
    cout << "The temperature is " << temp << " Fahrenheit" << endl;
}


Celsius Fahrenheit::toCelsius() {
    return Celsius((temp - 32) * 5 / 9);
}


Kelvin Fahrenheit::toKelvin() {
    return Kelvin((temp - 32) * 5 / 9 + 273.15);
}
