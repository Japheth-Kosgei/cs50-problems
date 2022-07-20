#include <stdio.h>

float average (int array[]);

int main(void)
{
    // Do some averages
    int array1[] = {2, 1, 2};
    int array2[] = {7, 6, 6};
    int array3[] = {8, 5, 7};

    printf("Array1: %f\n", average(array1));
    printf("Array2: %f\n", average(array2));
    printf("Array3: %f\n", average(array3));
}

float average (int array[])
{
    int len = sizeof(array) / sizeof(int);
    float sum = 0;
    int count = 0;

    for (int i = 0; i < *len; i ++)
    {
        sum += array[i];
        count ++;
    }

    return (sum / count);
}