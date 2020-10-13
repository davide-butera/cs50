#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;
            float originalBlue =  image[i][j].rgbtBlue;

            int sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            int sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            image[i][j].rgbtRed = (sepiaRed <= 255) ? sepiaRed : 255;
            image[i][j].rgbtGreen = (sepiaGreen <= 255) ? sepiaGreen : 255;
            image[i][j].rgbtBlue = (sepiaBlue <= 255) ? sepiaBlue : 255;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE temp =  image[i][width - j - 1];
            image[i][width - j - 1] = image[i][j];
            image[i][j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int box = 1;
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;
            float originalBlue =  image[i][j].rgbtBlue;

            float newRed = 0.0, newGreen = 0.0, newBlue = 0.0;
            int counter = 0;

            for (int k = -1; k < 2; k++)
            {
                //if the box is out of bound, it skips checking that pixel
                if (i + k < 0 || i + k > height - 1)
                {
                    continue;
                }

                for (int l = -1; l < 2; l++)
                {
                    if (j + l < 0 || j + l > width - 1)
                    {
                        continue;
                    }

                    newRed += image[i + k][j + l].rgbtRed;
                    newGreen += image[i + k][j + l].rgbtGreen;
                    newBlue += image[i + k][j + l].rgbtBlue;
                    counter++;
                }
            }
            temp[i][j].rgbtRed = round(newRed / counter);
            temp[i][j].rgbtGreen = round(newGreen / counter);
            temp[i][j].rgbtBlue = round(newBlue / counter);

        }
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[j][i].rgbtBlue = temp[j][i].rgbtBlue;
            image[j][i].rgbtGreen = temp[j][i].rgbtGreen;
            image[j][i].rgbtRed = temp[j][i].rgbtRed;
        }
    }
    return;
}
