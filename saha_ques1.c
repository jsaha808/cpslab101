#include <stdio.h>

int main() {

    float fahrenheit;
    float celsius;

    printf("Enter temperature in Fahrenheit: ");

    scanf("%f", & fahrenheit);

    celsius = (fahrenheit - 32) * 5 / 9;

    printf("Temperature in Celsius: %f\n", celsius);

    return 0;

}