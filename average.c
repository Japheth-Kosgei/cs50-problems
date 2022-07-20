#include <stdio.h>

int average (int array);

int main(void)
{
    // Do some averages
    int array1[] = {2, 1, 2};
    int array2[] = {7, 6, 6};
    int array3[] = {8, 5, 7};

    printf("Array1: %f\n", (array1[0] + array1[1] + array1[2]) / 3.0);
    printf("Array2: %f\n", (array2[0] + array2[1] + array2[2]) / 3.0);
    printf("Array3: %f\n", (array3[0] + array3[1] + array3[2]) / 3.0);
}

int average (int array)
{
    int len = sizeof(array) / sizeof(int);
    int sum 0;

    for (int i = 0; i < len; i ++)
    {
        sum += array[i];
    }
}