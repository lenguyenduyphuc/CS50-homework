#include "helpers.h"
#include <math.h>

int grey(float a, float b, float c);
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // float red = 0.0;
    // float green = 0.0;
    // float blue = 0.0;
    // RGBTRIPLE copy[height][width];
    // float divide;
    // for (int i = 0; i< height; i++)
    // {
    //     for (int j = 0; j < width; j++)
    //     {
    //         copy[i][j] = image[i][j];
    //     }
    // }
    // for (int i = 0; )
    // return;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rgb_avg = grey(image[i][j].rgbtRed, image[i][j].rgbtBlue, image[i][j].rgbtGreen);
            image[i][j].rgbtRed = rgb_avg;
            image[i][j].rgbtGreen = rgb_avg;
            image[i][j].rgbtBlue = rgb_avg;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // for (int i = 0; i < height; i++)
    // {
    //     for (int j = 0; j < width; j++)
    //     {
    //         if ((i == 0 && j == width - 1) || (i == height -1 && j == 0) || (i == 0 && j == 0) || (i == height - 1 && j == width
    //         -1))
    //         {

    //         }
    //     }
    // }
    float red, green, blue, divide;
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            divide = 0.0;
            red = 0.0;
            green = 0.0;
            blue = 0.0;
            for (int x = i - 1; x <= i + 1; x++)
            {
                for (int y = j - 1; y <= j + 1; y++)
                {
                    if (x != -1 && y != -1 && x != height && y != width)
                    {
                        red += copy[x][y].rgbtRed;
                        green += copy[x][y].rgbtGreen;
                        blue += copy[x][y].rgbtBlue;
                        divide++;
                    }
                }
            }
            image[i][j].rgbtRed = (int) round(red / divide);
            image[i][j].rgbtGreen = (int) round(green / divide);
            image[i][j].rgbtBlue = (int) round(blue / divide);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Declare new variable for duplicate
    RGBTRIPLE copyimage[height][width];

    // Duplicate the original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copyimage[i][j] = image[i][j];
        }
    }

    // Initialize Gx and Gy matrices
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // create variables for Gxsum and Gysum
    float sumGxRed, sumGxGreen, sumGxBlue;
    float sumGyRed, sumGyGreen, sumGyBlue;

    // Calculate new values for each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize sum each pixels and counter
            sumGxRed = sumGxGreen = sumGxBlue = 0;
            sumGyRed = sumGyGreen = sumGyBlue = 0;

            // Loop to find the neighbouring pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    // Condition to find and eliminate invalid pixel
                    if (x + i < 0 || x + i > height - 1 || y + j < 0 || y + j > width - 1)
                    {
                        continue;
                    }

                    // Multiply pixels by Gx matrix
                    sumGxRed += copyimage[x + i][y + j].rgbtRed * Gx[x + 1][y + 1];
                    sumGxGreen += copyimage[x + i][y + j].rgbtGreen * Gx[x + 1][y + 1];
                    sumGxBlue += copyimage[x + i][y + j].rgbtBlue * Gx[x + 1][y + 1];

                    // Multiply pixels by Gy matrix
                    sumGyRed += copyimage[x + i][y + j].rgbtRed * Gy[x + 1][y + 1];
                    sumGyGreen += copyimage[x + i][y + j].rgbtGreen * Gy[x + 1][y + 1];
                    sumGyBlue += copyimage[x + i][y + j].rgbtBlue * Gy[x + 1][y + 1];
                }
            }
            // Find the Square roots and addition of the squares of each color channel
            int rootRed = round(sqrt(pow(sumGxRed, 2) + pow(sumGyRed, 2)));
            int rootGreen = round(sqrt(pow(sumGxGreen, 2) + pow(sumGyGreen, 2)));
            int rootBlue = round(sqrt(pow(sumGxBlue, 2) + pow(sumGyBlue, 2)));

            // Cap new square root value at 255 and copy values to original image
            if (rootRed > 255)
            {
                rootRed = 255;
            }

            if (rootGreen > 255)
            {
                rootGreen = 255;
            }

            if (rootBlue > 255)
            {
                rootBlue = 255;
            }

            // Copy new values to original image
            image[i][j].rgbtRed = rootRed;
            image[i][j].rgbtGreen = rootGreen;
            image[i][j].rgbtBlue = rootBlue;
        }
    }
    return;
}

int grey(float a, float b, float c)
{
    float avg = round((a + b + c) / 3.0);
    avg = (int) avg;
    return avg;
}
