#ifndef CELSIUS_H
#define CELSIUS_H
#pragma once

class Fahrenheit;
class Kelvin;

class Celsius {
private:
    float temp;
public:
  
    Celsius();
    Celsius(float val);

    void assign(float val);
    void display() const;

    Fahrenheit toFahrenheit();
    Kelvin toKelvin();
};

#endif
