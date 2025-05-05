#ifndef TEMPERATURE_H
#define TEMPERATURE_H

float celsius_to_fahrenheit(float c);
float fahrenheit_to_celsius(float f);
float celsius_to_kelvin(float c);
float kelvin_to_celsius(float k);

float to_celsius(float value, char scale);
float from_celsius(float celsius, char target);
const char* categorize(float celsius);
const char* advisory(const char* category);

#endif
