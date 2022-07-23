#include <math.h>
#include <stdio.h>

#include "helpers.h"

RGBTRIPLE do_average(RGBTRIPLE *array, double len);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++) // Rows
    {
        for (int j = 0; j < width; j ++) // Columns
        {
            // Calculate the average
            double average_raw = round((((double)image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0));
            int average = average_raw;

            // Set the rgb values to average
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++) // Rows
    {
        for (int j = 0; j < width; j ++) // Columns
        {
            // Compute sepia values
             int sepiaRed = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
             if (sepiaRed > 255)
             {
                sepiaRed = 255;
             }

             int sepiaGreen = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
             if (sepiaGreen > 255)
             {
                sepiaGreen = 255;
             }

             int sepiaBlue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));
             if (sepiaBlue > 255)
             {
                sepiaBlue = 255;
             }

             // Update rgb values
             image[i][j].rgbtBlue = sepiaBlue;
             image[i][j].rgbtGreen = sepiaGreen;
             image[i][j].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a new copy of the image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i ++) // Loop through all the rows
    {
        for (int j = 0; j < width; j ++) // Loop through all the columns in that row
        {
            // Copy the pixels to new array
            copy[i][j] = image[i][j];
        }
    }

    // Do the reflection
    for (int i = 0; i < height; i ++) // Loop through all the rows
    {
        for (int j = 0; j < width; j ++) // Loop through all the columns
        {
            // rgbtBlue
            image[i][j] = copy[i][(width - (j + 1))];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a new copy of the image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i ++) // Loop through all the rows
    {
        for (int j = 0; j < width; j ++) // Loop through all the columns in that row
        {
            // Copy the pixels to new array
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
            copy[i][j].rgbtRed = image[i][j].rgbtRed;

        }
    }

    // Blur
    // These are variables for storing rgb values of the surrounding pixels
    RGBTRIPLE left;
    RGBTRIPLE right;
    RGBTRIPLE up;
    RGBTRIPLE down;
    RGBTRIPLE up_left;
    RGBTRIPLE down_left;
    RGBTRIPLE up_right;
    RGBTRIPLE down_right;
    RGBTRIPLE original;

    // for (each pixel)
    // Assign values to the variables of the surrounding pixels
    // Compute the blur
    // Update the original image's pixel values
    for (int i = 0; i < height; i ++) // Loop through all rows
    {
        for (int j = 0; j < width; j ++) // Loop through all the columns within the current row
        {
            // Original pixel
            original = copy[i][j];

            // Left
            if (j != 0)
            {
                left = copy[i][j - 1];
            }

            // Right
            if (j != (width - 1))
            {
                right = copy[i][j + 1];
            }

            // Down
            if (i != (height - 1))
            {
                down = copy[i + 1][j];
            }

            // Up
            if (i != 0)
            {
                up = copy[i - 1][j];
            }

            // Up_left
            if (i != 0 && j != 0)
            {
                up_left = copy[i - 1][j - 1];
            }

            // Up_right
            if (i != 0 && j != (width - 1))
            {
                up_right = copy[i - 1][j + 1];
            }

            // Down_left
            if (i != (height - 1) && j != 0)
            {
                down_left = copy[i + 1][j - 1];
            }

            // Down_right
            if (i != (height - 1) && j != (width - 1))
            {
                down_right = copy[i + 1][j + 1];
            }



            // Calculate the average and update the value of the original image's pixels
            // Right edge
            if (i != 0 && i != (height - 1) && j == (width - 1))
            {
                RGBTRIPLE neighbors[] = {up, up_left, left, down_left, down, original};
                image[i][j] = do_average(neighbors, 6);
            }

            // Left edge
            else if (i != 0 && i != (height - 1) && j == 0)
            {
                RGBTRIPLE neighbors[] = {up, up_right, right, down_right, down, original};
                image[i][j] = do_average(neighbors, 6);
            }

            // Up edge
            else if (i == 0 && j != (width - 1) && j != 0)
            {
                RGBTRIPLE neighbors[] = {right, down_right, down, down_left, left, original};
                image[i][j] = do_average(neighbors, 6);
            }

            // Down edge
            else if (i == (height - 1) && j != (width - 1) && j != 0)
            {
                RGBTRIPLE neighbors[] = {left, up_left, up, up_right, right, original};
                image[i][j] = do_average(neighbors, 6);
            }

            // Extreme up-right
            else if (i == 0 && j == (width - 1))
            {
                RGBTRIPLE neighbors[] = {left, down_left, down, original};
                image[i][j] = do_average(neighbors, 4);
            }

            // Extreme up-left
            else if (i == 0 && j == 0)
            {
                RGBTRIPLE neighbors[] = {right, down_right, down, original};
                image[i][j] = do_average(neighbors, 4);
            }

            // Extreme down-left
            else if (i == (height - 1) && j == 0)
            {
                RGBTRIPLE neighbors[] = {right, up_right, up, original};
                image[i][j] = do_average(neighbors, 4);
            }

            // Extreme down-right
            else if (i == (height - 1) && j == (width - 1))
            {
                RGBTRIPLE neighbors[] = {left, up_left, up, original};
                image[i][j] = do_average(neighbors, 4);
            }

            // Middle pixel
            else
            {
                RGBTRIPLE neighbors[] = {up, left, right, down, up_left, up_right, down_left, down_right, original};
                image[i][j] = do_average(neighbors, 9);
            }
        }
    }
    return;
}

RGBTRIPLE do_average(RGBTRIPLE *array, double len)
{
    // Return a blurred pixel
    RGBTRIPLE blurred_pixel;

    // Red
    double sum_red = 0;
    for (int i = 0; i < len; i ++)
    {
        sum_red += array[i].rgbtRed;
    }

    blurred_pixel.rgbtRed = round(sum_red / len);

    // Green
    double sum_green = 0;
    for (int i = 0; i < len; i ++)
    {
        sum_green += array[i].rgbtGreen;
    }

    blurred_pixel.rgbtGreen = round(sum_green / len);

    // Blue
    double sum_blue = 0;
    for (int i = 0; i < len; i ++)
    {
        sum_blue += array[i].rgbtBlue;
    }

    blurred_pixel.rgbtBlue = round(sum_blue / len);

    return blurred_pixel;
}