#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            int avg = round((image[i][k].rgbtRed + image[i][k].rgbtGreen + image[i][k].rgbtBlue) / 3.0);

            image[i][k].rgbtRed = avg;
            image[i][k].rgbtGreen = avg;
            image[i][k].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            float sepiaRed = round(.393 * image[i][k].rgbtRed + .769 * image[i][k].rgbtGreen + .189 * image[i][k].rgbtBlue);
            float sepiaGreen = round(.349 * image[i][k].rgbtRed + .686 * image[i][k].rgbtGreen + .168 * image[i][k].rgbtBlue);
            float sepiaBlue = round(.272 * image[i][k].rgbtRed + .534 * image[i][k].rgbtGreen + .131 * image[i][k].rgbtBlue);

            image[i][k].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;
            image[i][k].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
            image[i][k].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width / 2; k++)
        {
            RGBTRIPLE temp = image[i][k];

            int opposite = width - 1 - k;

            image[i][k] = image[i][opposite];

            image[i][opposite] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            copy[i][k] = image[i][k];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            float sumRed = 0;
            float sumGreen = 0;
            float sumBlue = 0;

            int count = 0;

            for (int row = -1; row <= 1; row++)
            {
                for (int col = -1; col <= 1; col++)
                {

                    int newRow = i + row;
                    int newCol = k + col;

                    if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width)
                    {
                        sumRed += copy[newRow][newCol].rgbtRed;
                        sumGreen += copy[newRow][newCol].rgbtGreen;
                        sumBlue += copy[newRow][newCol].rgbtBlue;
                        count++;
                    }
                }
            }

            image[i][k].rgbtRed = round(sumRed / count);
            image[i][k].rgbtGreen = round(sumGreen / count);
            image[i][k].rgbtBlue = round(sumBlue / count);
        }
    }

    return;
}
