#include <math.h>

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

    // for (each pixel)
    // Assign values to the variables of the surrounding pixels
    // Compute the blur
    // Update the original image's pixel values
    for (int i =0; i < height; i ++) // Loop through all rows
    {
        for (int j =0; j < width; j ++) // Loop through all the columns within the current row
        {
            // Left
            if (j != 0)
            {
                // Blue
                left = copy[i][(width - 1)];
            }

            // Right
            if (j != width - 1)
            {
                // Blue
                right = copy[i][width + 1];
            }

            // Up
            if (i != 0)
            {
                // Blue
                up = copy[(height - 1)][j];
            }

            // Down
            if (i != height - 1)
            {
                // Blue
                down = copy[(height + 1)][j];
            }

            // up_left
            if (i != 0 && j != 0)
            {
                // Blue
                up_left = copy[(height - 1)][(width - 1)];
            }

            // down_left
            if (i != height - 1 && j != 0)
            {
                // Blue
                down_left = copy[(height + 1)][(width -1)];
            }

            // up_right
            if (i != 0 && j != width - 1)
            {
                // Blue
                up_right = copy[(height - 1)][(width + 1)];
            }

            // down_right
            if (i != height - 1 && j != width - 1)
            {
                // Blue
                down_right = copy[(height + 1)][(width + 1)];
            }



            // Compute the blur
            // Extreme up_left
            if (i == 0 && j == 0)
            {
                // Blue
                image[i][j].rgbtBlue = round(((float)right.rgbtBlue + down_right.rgbtBlue + down.rgbtBlue) / 3.0);
                // Red
                image[i][j].rgbtRed = round(((float)right.rgbtRed + down_right.rgbtRed + down.rgbtRed) / 3.0);
                // Green
                image[i][j].rgbtGreen = round(((float)right.rgbtGreen + down_right.rgbtGreen + down.rgbtGreen) / 3.0);
            }

            // Extreme up_right
            else if (i == 0 && j == width - 1)
            {
                // Blue
                image[i][j].rgbtBlue = round(((float)left.rgbtBlue + down_left.rgbtBlue + down.rgbtBlue) / 3.0);
                // Green
                image[i][j].rgbtGreen = round(((float)left.rgbtGreen + down_left.rgbtGreen + down.rgbtGreen)/ 3.0);
                // Red
                image[i][j].rgbtRed = round(((float)left.rgbtRed + down_left.rgbtRed + down.rgbtRed) / 3.0);
            }

            // Extreme down-left
            else if (i == height - 1 && j == 0)
            {
                // Blue
                image[i][j].rgbtBlue = round(((float)up.rgbtBlue + up_right.rgbtBlue + right.rgbtBlue) / 3.0);
                // Green
                image[i][j].rgbtGreen = round(((float)up.rgbtGreen + up_right.rgbtGreen + right.rgbtGreen) / 3.0);
                // Red
                image[i][j].rgbtRed = round(((float)up.rgbtRed + up_right.rgbtRed + right.rgbtRed) / 3.0);
            }

            // Extreme down_right
            else if (i == 0 && j == width - 1)
            {
                // Blue
                image[i][j].rgbtBlue = round(((float)up.rgbtBlue + up_left.rgbtBlue + left.rgbtBlue)/ 3.0);
                // Green
                image[i][j].rgbtGreen = round(((float)up.rgbtGreen + up_left.rgbtGreen + left.rgbtGreen)/ 3.0);
                // Red
                image[i][j].rgbtRed = round(((float)up.rgbtRed + up_left.rgbtRed + left.rgbtRed)/ 3.0);
            }

            // Up edge
            else if (i == 0 && j != width - 1 && j != 0)
            {
                // Blue
                image[i][j].rgbtBlue = round((left.rgbtBlue + down_left.rgbtBlue + down.rgbtBlue + down_right.rgbtBlue + right.rgbtBlue)/ 5.0);
                // Green
                image[i][j].rgbtGreen = round((left.rgbtGreen + down_left.rgbtGreen + down.rgbtGreen + down_right.rgbtGreen + right.rgbtGreen)/ 5.0);
                // Red
                image[i][j].rgbtRed = round((left.rgbtRed + down_left.rgbtRed + down.rgbtRed + down_right.rgbtRed + right.rgbtRed)/ 5.0);
            }

            // Down edge
            else if (i == height - 1 && j != width - 1 && j != 0)
            {
                // Blue
                image[i][j].rgbtBlue = round(((float)left.rgbtBlue + up_left.rgbtBlue + up.rgbtBlue + up_right.rgbtBlue + right.rgbtBlue)/ 5.0);
                // Green
                image[i][j].rgbtGreen = round(((float)left.rgbtGreen + up_left.rgbtGreen + up.rgbtGreen + up_right.rgbtGreen + right.rgbtGreen)/ 5.0);
                // Red
                image[i][j].rgbtRed = round(((float)left.rgbtRed + up_left.rgbtRed + up.rgbtRed + up_right.rgbtRed + right.rgbtRed)/ 5.0);
            }

            // Left edge
            else if (i != 0 && i != height - 1 && j == 0)
            {
                // Blue
                image[i][j].rgbtBlue = round(((float)up.rgbtBlue + up_right.rgbtBlue + right.rgbtBlue + down_right.rgbtBlue + down.rgbtBlue)/ 5.0);
                // Green
                image[i][j].rgbtGreen = round(((float)up.rgbtGreen + up_right.rgbtGreen + right.rgbtGreen + down_right.rgbtGreen + down.rgbtGreen)/ 5.0);
                // Red
                image[i][j].rgbtRed = round(((float)up.rgbtRed + up_right.rgbtRed + right.rgbtRed + down_right.rgbtRed + down.rgbtRed)/ 5.0);
            }

            // Right edge
            else if (i != 0 && i != height - 1 && j == width - 1)
            {
                // Blue
                image[i][j].rgbtBlue = round(((float)up.rgbtBlue + up_left.rgbtBlue + left.rgbtBlue + down_left.rgbtBlue + down.rgbtBlue)/ 5.0);
                // Green
                image[i][j].rgbtGreen = round(((float)up.rgbtGreen + up_left.rgbtGreen + left.rgbtGreen + down_left.rgbtGreen + down.rgbtGreen)/ 5.0);
                // Red
                image[i][j].rgbtRed = round(((float)up.rgbtRed + up_left.rgbtRed + left.rgbtRed + down_left.rgbtRed + down.rgbtRed)/ 5.0);
            }

            // All other pixels
            else
            {
                // Blue
                image[i][j].rgbtBlue = round(((float)up.rgbtBlue + down.rgbtBlue + left.rgbtBlue + right.rgbtBlue + up_left.rgbtBlue + up_right.rgbtBlue + down_left.rgbtBlue + down_right.rgbtBlue)/ 8.0);
                // Green
                image[i][j].rgbtGreen = round(((float)up.rgbtGreen + down.rgbtGreen + left.rgbtGreen + right.rgbtGreen + up_left.rgbtGreen + up_right.rgbtGreen + down_left.rgbtGreen + down_right.rgbtGreen)/ 8.0);
                // Red
                image[i][j].rgbtRed = round(((float)up.rgbtRed + down.rgbtRed + left.rgbtRed + right.rgbtRed + up_left.rgbtRed + up_right.rgbtRed + down_left.rgbtRed + down_right.rgbtRed)/ 8.0);
            }

        }
    }
    return;
}
