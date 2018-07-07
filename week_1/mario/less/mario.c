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
        for (int j = height + 1; j > 0; j--)
        {
            // There will be i + 1 hashes on each row
            if (j - i > 2)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}