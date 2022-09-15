#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg = 0.0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = round((image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3);
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// // Swap BYTEs using pointers
// void swap(BYTE *a, BYTE *b)
// {
//     BYTE temp = *a;
//     *a = *b;
//     *b = temp;
// }

// Swap RGBTRIPLE using pointers
void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE temp = *a;
    *a = *b;
    *b = temp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // // Without pointers
    // RGBTRIPLE temp;
    // for (int i = 0; i < height; i++)
    // {
    //     for (int j = 0; j < width / 2; j++)
    //     {
    //         temp.rgbtRed = image[i][j].rgbtRed;
    //         temp.rgbtBlue = image[i][j].rgbtBlue;
    //         temp.rgbtGreen = image[i][j].rgbtGreen;
    //         image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
    //         image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
    //         image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
    //         image[i][width - j].rgbtRed = temp.rgbtRed;
    //         image[i][width - j].rgbtBlue = temp.rgbtBlue;
    //         image[i][width - j].rgbtGreen = temp.rgbtGreen;
    //     }
    // }

    // // Using pointers (BYTEs)
    // for (int i = 0; i < height; i++)
    // {
    //     for (int j = 0; j < width / 2; j++)
    //     {
    //         swap(&image[i][j].rgbtRed, &image[i][width - 1 - j].rgbtRed);
    //         swap(&image[i][j].rgbtBlue, &image[i][width - j].rgbtBlue);
    //         swap(&image[i][j].rgbtGreen, &image[i][width - j].rgbtGreen);
    //     }
    // }

    // Using pointers (RGBTRIPLEs)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            swap(&image[i][j], &image[i][width - 1 - j]);
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Copy original image to temp
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j].rgbtRed = image[i][j].rgbtRed;
            temp[i][j].rgbtBlue = image[i][j].rgbtBlue;
            temp[i][j].rgbtGreen = image[i][j].rgbtGreen;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed, sumBlue, sumGreen;
            sumRed = sumBlue = sumGreen = 0;
            float counter = 0.0;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int x_pos = i + x;
                    int y_pos = j + y;

                    // Check if neighboring pixel is valid
                    if (x_pos < 0 || x_pos > height - 1 || y_pos < 0 || y_pos > width - 1)
                    {
                        continue;
                    }

                    // Get image value
                    sumRed += image[x_pos][y_pos].rgbtRed;
                    sumBlue += image[x_pos][y_pos].rgbtBlue;
                    sumGreen += image[x_pos][y_pos].rgbtGreen;

                    counter++;
                }

                // Calculate average of neighboring pixels
                temp[i][j].rgbtRed = round(sumRed / counter);
                temp[i][j].rgbtBlue = round(sumBlue / counter);
                temp[i][j].rgbtGreen = round(sumGreen / counter);
            }
        }
    }

    // Copy temp pixels to the origional image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3];
    int Gy[3][3];
    Gx[0][0] = -1;
    Gx[0][1] = 0;
    Gx[0][2] = 1;
    Gx[1][0] = -2;
    Gx[1][1] = 0;
    Gx[1][2] = 2;
    Gx[2][0] = -1;
    Gx[2][1] = 0;
    Gx[2][2] = 1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            Gy[i][j] = Gx[j][i];
            // printf("%i ", Gy[i][j]);
        }
        // printf("\n");
    }

    // Copy original image to temp
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j].rgbtRed = image[i][j].rgbtRed;
            temp[i][j].rgbtBlue = image[i][j].rgbtBlue;
            temp[i][j].rgbtGreen = image[i][j].rgbtGreen;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRedX, sumBlueX, sumGreenX, sumRedY, sumBlueY, sumGreenY;
            sumRedX = sumBlueX = sumGreenX = sumRedY = sumBlueY = sumGreenY = 0;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int x_pos = i + x;
                    int y_pos = j + y;

                    // Check if neighboring pixel is valid
                    if (x_pos < 0 || x_pos > height - 1 || y_pos < 0 || y_pos > width - 1)
                    {
                        continue;
                    }

                    sumRedX += image[x_pos][y_pos].rgbtRed * Gx[x + 1][y + 1];
                    sumBlueX += image[x_pos][y_pos].rgbtBlue * Gx[x + 1][y + 1];
                    sumGreenX += image[x_pos][y_pos].rgbtGreen * Gx[x + 1][y + 1];

                    sumRedY += image[x_pos][y_pos].rgbtRed * Gy[x + 1][y + 1];
                    sumBlueY += image[x_pos][y_pos].rgbtBlue * Gy[x + 1][y + 1];
                    sumGreenY += image[x_pos][y_pos].rgbtGreen * Gy[x + 1][y + 1];
                }
            }

            double sumRed = sqrt(pow(sumRedX, 2) + pow(sumRedY, 2));
            double sumBlue = sqrt(pow(sumBlueX, 2) + pow(sumBlueY, 2));
            double sumGreen = sqrt(pow(sumGreenX, 2) + pow(sumGreenY, 2));

            if (sumRed > 255)
            {
                sumRed = 255;
            }
            if (sumBlue > 255)
            {
                sumBlue = 255;
            }
            if (sumGreen > 255)
            {
                sumGreen = 255;
            }

            temp[i][j].rgbtRed = round(sumRed);
            temp[i][j].rgbtBlue = round(sumBlue);
            temp[i][j].rgbtGreen = round(sumGreen);
        }
    }
    // Copy temp pixels to the origional image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }

    return;
}
