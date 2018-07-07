#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Initialize variables
    int height;
    // Get height from user
    do
    {
        height = get_int("Height: ");
    }
    // Check that height is between 0 and 23
    while (height < 0 || height > 23);
    for (int i = 0; i < height; i++)
    {
        for (int j = height; j > 0; j--)
        {
            if (j - i > 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        // Add gutter
        printf("  ");
        // Start new loop to make other half of pyramid
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}