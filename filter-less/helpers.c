#include <math.h>
#include <stdio.h>

#include "helpers.h"

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
            copy[i][j] = image[i][j];
        }
    }

    // Variables for the surrounding pixels
    RGB
    return;
}
