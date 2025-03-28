
#include "temperature.h"
#include <stdio.h> 
#include <ctype.h> 
#include <string.h>


int main() {
    float value; // temp input
    char input_scale, target_scale; // input/output unit

    printf("Enter temperature value: ");
    scanf("%f", &value); // read temp

    printf("Enter input scale (F/C/K): ");
    scanf(" %c", &input_scale); // read input unit
    input_scale = toupper(input_scale); // force uppercase

    printf("Enter target scale (F/C/K): ");
    scanf(" %c", &target_scale); // read target unit
    target_scale = toupper(target_scale); // force uppercase

    if ((input_scale != 'F' && input_scale != 'C' && input_scale != 'K') ||
        (target_scale != 'F' && target_scale != 'C' && target_scale != 'K')) {
        printf("Invalid temperature scale.\n"); // invalid unit
        return 1; // exit
    }

    float celsius = to_celsius(value, input_scale); // convert to celsius
    float converted = from_celsius(celsius, target_scale); // convert to target

    printf("\nConverted temperature: %.2f %c\n", converted, target_scale); // show result

    const char* category = categorize(celsius); // get label
    const char* advice = advisory(category); // get message

    printf("Category: %s\n", category); // print label
    printf("Weather advisory: %s\n", advice); // print message

    return 0; // done
}
