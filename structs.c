#include <stdio.h>
#include <math.h>

typedef struct
{
    float red;
    float green;
    float  blue;
}
rgb;

int main(void)
{
    // Test sum
    // Blue
    image[i][j].rgbtBlue = round((up.rgbtBlue + down.rgbtBlue + left.rgbtBlue + right.rgbtBlue + up_left.rgbtBlue + up_right.rgbtBlue + down_left.rgbtBlue + down_right.rgbtBlue)/ 8.0);
    // Green
    image[i][j].rgbtGreen = round((up.rgbtGreen + down.rgbtGreen + left.rgbtGreen + right.rgbtGreen + up_left.rgbtGreen + up_right.rgbtGreen + down_left.rgbtGreen + down_right.rgbtGreen)/ 8.0);
    // Red
    image[i][j].rgbtRed = round((up.rgbtRed + down.rgbtRed + left.rgbtRed + right.rgbtRed + up_left.rgbtRed + up_right.rgbtRed + down_left.rgbtRed + down_right.rgbtRed)/ 8.0);
}
