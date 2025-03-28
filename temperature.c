#include "temperature.h"
#include <stdio.h> 
#include <ctype.h> 
#include <string.h>

// quick conversion helpers
float celsius_to_fahrenheit(float c) { return (c * 9.0 / 5.0) + 32; } 
float fahrenheit_to_celsius(float f) { return (f - 32) * 5.0 / 9.0; } 
float celsius_to_kelvin(float c) { return c + 273.15; } 
float kelvin_to_celsius(float k) { return k - 273.15; } 

float to_celsius(float value, char scale) { // convert any scale to celsius
    if (scale == 'C') return value; // no conversion
    if (scale == 'F') return fahrenheit_to_celsius(value); // F to C
    if (scale == 'K') return kelvin_to_celsius(value); // K to C
    return -9999; // invalid
}

float from_celsius(float celsius, char target) { // convert celsius to target
    if (target == 'C') return celsius; // no conversion
    if (target == 'F') return celsius_to_fahrenheit(celsius); // C to F
    if (target == 'K') return celsius_to_kelvin(celsius); // C to K
    return -9999; // invalid
}

const char* categorize(float celsius) { // temp category
    if (celsius < 0) return "Freezing"; // < 0
    if (celsius < 10) return "Cold"; // 0–10
    if (celsius < 25) return "Comfortable"; // 10–25
    if (celsius < 35) return "Hot"; // 25–35
    return "Extreme Heat"; // > 35
}

const char* advisory(const char* category) {
    if (strcmp(category, "Freezing") == 0) return "Stay warm indoors."; // freezing
    if (strcmp(category, "Cold") == 0) return "Wear a jacket."; // cold
    if (strcmp(category, "Comfortable") == 0) return "Enjoy the weather!"; // good
    if (strcmp(category, "Hot") == 0) return "Stay hydrated."; // hot
    return "Stay indoors and cool!"; // extreme heat
}

