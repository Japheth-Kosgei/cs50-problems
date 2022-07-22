
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
    for (int i =0; i < height; i ++) // Loop through all rows
    {
        for (int j =0; j < width; j ++) // Loop through all the columns within the current row
        {
            int blue = image[i][j].rgbtBlue;
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;


            // Left
            if (j != 0)
            {
                // Blue
                left = copy[i][(j - 1)];
            }

            // Right
            if (j != width - 1)
            {
                // Blue
                right = copy[i][j + 1];
            }

            // Up
            if (i != 0)
            {
                // Blue
                up = copy[(i - 1)][j];
            }

            // Down
            if (i != height - 1)
            {
                // Blue
                down = copy[(i + 1)][j];
            }

            // up_left
            if (i != 0 && j != 0)
            {
                // Blue
                up_left = copy[(i - 1)][(j - 1)];
            }

            // down_left
            if (i != height - 1 && j != 0)
            {
                // Blue
                down_left = copy[(i + 1)][(j - 1)];
            }

            // up_right
            if (i != 0 && j != width - 1)
            {
                // Blue
                up_right = copy[(i - 1)][(j + 1)];
            }

            // down_right
            if (i != height - 1 && j != width - 1)
            {
                // Blue
                down_right = copy[(i + 1)][(j + 1)];
            }



            // Compute the blur
            // Extreme up_left
            if (i == 0 && j == 0)
            {
                // Blue
                image[i][j].rgbtBlue = round(((double)right.rgbtBlue + down_right.rgbtBlue + down.rgbtBlue) / 3.0);
                printf("Blue:  %i\n", image[i][j].rgbtBlue);
                // Red
                image[i][j].rgbtRed = round(((double)right.rgbtRed + down_right.rgbtRed + down.rgbtRed) / 3.0);
                printf("Red:   %i\n", image[i][j].rgbtRed);
                // Green
                image[i][j].rgbtGreen = round(((double)right.rgbtGreen + down_right.rgbtGreen + down.rgbtGreen) / 3.0);
                printf("Green: %i\n", image[i][j].rgbtGreen);
            }

            // Extreme up_right
            else if (i == 0 && j == width - 1)
            {
                // Blue
                image[i][j].rgbtBlue = round(((double)left.rgbtBlue + down_left.rgbtBlue + down.rgbtBlue) / 3.0);
                // Green
                image[i][j].rgbtGreen = round(((double)left.rgbtGreen + down_left.rgbtGreen + down.rgbtGreen)/ 3.0);
                // Red
                image[i][j].rgbtRed = round(((double)left.rgbtRed + down_left.rgbtRed + down.rgbtRed) / 3.0);
            }

            // Extreme down-left
            else if (i == height - 1 && j == 0)
            {
                // Blue
                image[i][j].rgbtBlue = round(((double)up.rgbtBlue + up_right.rgbtBlue + right.rgbtBlue) / 3.0);
                // Green
                image[i][j].rgbtGreen = round(((double)up.rgbtGreen + up_right.rgbtGreen + right.rgbtGreen) / 3.0);
                // Red
                image[i][j].rgbtRed = round(((double)up.rgbtRed + up_right.rgbtRed + right.rgbtRed) / 3.0);
            }

            // Extreme down_right
            else if (i == 0 && j == width - 1)
            {
                // Blue
                image[i][j].rgbtBlue = round(((double)up.rgbtBlue + up_left.rgbtBlue + left.rgbtBlue)/ 3.0);
                // Green
                image[i][j].rgbtGreen = round(((double)up.rgbtGreen + up_left.rgbtGreen + left.rgbtGreen)/ 3.0);
                // Red
                image[i][j].rgbtRed = round(((double)up.rgbtRed + up_left.rgbtRed + left.rgbtRed)/ 3.0);
            }

            // Up edge
            else if (i == 0 && j != width - 1 && j != 0)
            {
                // Blue
                image[i][j].rgbtBlue = round((left.rgbtBlue + down_left.rgbtBlue + down.rgbtBlue + down_right.rgbtBlue + right.rgbtBlue)/ 5.0);
                printf("Blue:  %i\n", image[i][j].rgbtBlue);
                // Green
                image[i][j].rgbtGreen = round((left.rgbtGreen + down_left.rgbtGreen + down.rgbtGreen + down_right.rgbtGreen + right.rgbtGreen)/ 5.0);
                printf("Green: %i\n", image[i][j].rgbtGreen);
                // Red
                image[i][j].rgbtRed = round((left.rgbtRed + down_left.rgbtRed + down.rgbtRed + down_right.rgbtRed + right.rgbtRed)/ 5.0);
                printf("Red:   %i\n", image[i][j].rgbtRed);
            }


            // Down edge
            else if (i == height - 1 && j != width - 1 && j != 0)
            {
                // Blue
                image[i][j].rgbtBlue = round(((double)left.rgbtBlue + up_left.rgbtBlue + up.rgbtBlue + up_right.rgbtBlue + right.rgbtBlue)/ 5.0);
                // Green
                image[i][j].rgbtGreen = round(((double)left.rgbtGreen + up_left.rgbtGreen + up.rgbtGreen + up_right.rgbtGreen + right.rgbtGreen)/ 5.0);
                // Red
                image[i][j].rgbtRed = round(((double)left.rgbtRed + up_left.rgbtRed + up.rgbtRed + up_right.rgbtRed + right.rgbtRed)/ 5.0);
            }

            // Left edge
            else if (i != 0 && i != height - 1 && j == 0)
            {
                // Blue
                image[i][j].rgbtBlue = round(((double)up.rgbtBlue + up_right.rgbtBlue + right.rgbtBlue + down_right.rgbtBlue + down.rgbtBlue)/ 5.0);
                // Green
                image[i][j].rgbtGreen = round(((double)up.rgbtGreen + up_right.rgbtGreen + right.rgbtGreen + down_right.rgbtGreen + down.rgbtGreen)/ 5.0);
                // Red
                image[i][j].rgbtRed = round(((double)up.rgbtRed + up_right.rgbtRed + right.rgbtRed + down_right.rgbtRed + down.rgbtRed)/ 5.0);
            }

            // Right edge
            else if (i != 0 && i != height - 1 && j == width - 1)
            {
                // Blue
                image[i][j].rgbtBlue = round(((double)up.rgbtBlue + up_left.rgbtBlue + left.rgbtBlue + down_left.rgbtBlue + down.rgbtBlue)/ 5.0);
                // Green
                image[i][j].rgbtGreen = round(((double)up.rgbtGreen + up_left.rgbtGreen + left.rgbtGreen + down_left.rgbtGreen + down.rgbtGreen)/ 5.0);
                // Red
                image[i][j].rgbtRed = round(((double)up.rgbtRed + up_left.rgbtRed + left.rgbtRed + down_left.rgbtRed + down.rgbtRed)/ 5.0);
            }

            // All other pixels (Middle pixel)
            else
            {
                // Blue
                image[i][j].rgbtBlue = round((up.rgbtBlue + down.rgbtBlue + left.rgbtBlue + right.rgbtBlue + up_left.rgbtBlue + up_right.rgbtBlue + down_left.rgbtBlue + down_right.rgbtBlue)/ 8.0);
                // Green
                image[i][j].rgbtGreen = round((up.rgbtGreen + down.rgbtGreen + left.rgbtGreen + right.rgbtGreen + up_left.rgbtGreen + up_right.rgbtGreen + down_left.rgbtGreen + down_right.rgbtGreen)/ 8.0);
                // Red
                image[i][j].rgbtRed = round((up.rgbtRed + down.rgbtRed + left.rgbtRed + right.rgbtRed + up_left.rgbtRed + up_right.rgbtRed + down_left.rgbtRed + down_right.rgbtRed)/ 8.0);
            }

        }
    }