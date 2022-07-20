#include <stdio.h>

typedef struct
{
    float red;
    float green;
    float  blue;
}
rgb;

int main(void)
{
    // Make a data structure similar to rgb and do average
    rgb array[2];

    array[0].red = 0;
    array[0].green = 0;
    array[0].blue = 0;

    array[1].red = 10;
    array[1].green = 10;
    array[1].blue = 10;

    // Average
    rgb average;
    // Red
    average.red = (array[0].red + array[1].red) / 2.0;
    // Green
    average.green = (array[0].green + array[1].green) / 2.0;
    // Blue
    average.blue = (array[0].blue + array[1].blue) / 2.0;

    printf("Red:   %2f\n", average.red);
    printf("Green: %2f\n", average.green);
    printf("Blue:  %2f\n", average.blue);
}
