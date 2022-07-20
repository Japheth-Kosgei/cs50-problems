#include <stdio.h>

double average (double array[]);

int main(void)
{
    // Do some averages
    double array1[] = {2, 1, 2};
    double array2[] = {7, 6, 6};
    double array3[] = {8, 5, 7};

    printf("Array1: %.6lf\n", average(array1));
    printf("Array2: %.6lf\n", average(array2));
    printf("Array3: %.6lf\n", average(array3));
}

double average (double array[])
{
    double len = sizeof(*array) / sizeof(int);
    double sum = 0;

    for (int i = 0; i < len; i ++)
    {
        sum += array[i];
    }

    return (sum / len);
}