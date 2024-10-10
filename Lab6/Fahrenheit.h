#ifndef FAHRENHEIT_H
#define FAHRENHEIT_H
#pragma once

class Celsius;
class Kelvin;

class Fahrenheit {
private:
    float temp;
public:
    
    Fahrenheit();
    Fahrenheit(float val);

   
    void assign(float val);
    void display() const;

 
    Celsius toCelsius();
    Kelvin toKelvin();
};

#endif
