#include <stdio.h>

float average (float array[]);

int main(void)
{
    // Do some averages
    float array1[] = {2, 1, 2};
    float array2[] = {7, 6, 6};
    float array3[] = {8, 5, 7};

    printf("Array1: %3f\n", average(array1));
    printf("Array2: %f\n", average(array2));
    printf("Array3: %f\n", average(array3));
}

float average (float array[])
{
    float len = sizeof(*array) / sizeof(int);
    float sum = 0;

    for (int i = 0; i < len; i ++)
    {
        sum += array[i];
    }

    return (sum / len);
}