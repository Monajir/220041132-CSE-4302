#ifndef KELVIN_H
#define KELVIN_H
#pragma once


class Celsius;
class Fahrenheit;

class Kelvin {
private:
    float temp;
public:
    
    Kelvin();
    Kelvin(float val);

    
    void assign(float val);
    void display() const;

   
    Celsius toCelsius();
    Fahrenheit toFahrenheit();
};

#endif
