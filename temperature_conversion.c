
#include <stdio.h>
#include <ctype.h>

// Helper to convert temperature to Celsius
double to_celsius(double value, char scale) {
    if (scale == 'C') return value; // default as per lab instructions
    if (scale == 'F') return (value - 32) * 5.0 / 9.0; // farenheit to celsius
    if (scale == 'K') return value - 273.15; // kelvin to celsius
    return -9999; // invalid
}

// Helper to convert Celsius to target scale
double from_celsius(double celsius, char target) {
    if (target == 'C') return celsius; 
    if (target == 'F') return (celsius * 9.0 / 5.0) + 32; // celsius to farenheit
    if (target == 'K') return celsius + 273.15; // celsius to kelvin
    return -9999;
}

// Categorize temperature in Celsius
const char* categorize(double celsius) {
    if (celsius < 0) return "Freezing";
    if (celsius < 10) return "Cold";
    if (celsius < 25) return "Comfortable";
    if (celsius < 35) return "Hot";
    return "Extreme Heat"; // above 35
}

// Give weather advice based on category
const char* advisory(const char* category) {
    if (category == "Freezing") return "Stay indoors.";
    if (category == "Cold") return "Wear a jacket.";
    if (category == "Comfortable") return "Enjoy the weather!";
    if (category == "Hot") return "Stay hydrated.";
    return "Stay indoors and cool!";
}

int main() {
    double value;
    char input_scale, target_scale;

    printf("Enter temperature value: ");
    scanf("%lf", &value); // reads double floating point

    printf("Enter input scale (F/C/K): ");
    scanf(" %c", &input_scale); // reads single character
    input_scale = toupper(input_scale);

    printf("Enter target scale (F/C/K): ");
    scanf(" %c", &target_scale); // reads single character
    target_scale = toupper(target_scale);

    if ((input_scale != 'F' && input_scale != 'C' && input_scale != 'K') ||
        (target_scale != 'F' && target_scale != 'C' && target_scale != 'K')) { // neither C K or F
        printf("Invalid temperature scale.\n");
        return 1;
    }

    // conver temps
    double celsius = to_celsius(value, input_scale);
    double converted = from_celsius(celsius, target_scale);

    printf("\nConverted temperature: %.2f %c\n", converted, target_scale);

    const char* category = categorize(celsius);
    const char* advice = advisory(category);

    printf("Category: %s\n", category);
    printf("Weather advisory: %s\n", advice);

    return 0;
}
