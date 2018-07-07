#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Initialize variables
    float change;
    int numSteps = 0;
    int cashBack;
    // Get input from user
    do
    {
        change = get_float("How much change do you need? ");
    }
    while (change < 0.0);
    // Transform change from dollars to cents, and round for precision
    cashBack = round(change * 100.00);
    // Check for quarters
    while (cashBack >= 25)
    {
        cashBack -= 25;
        numSteps++;
    }
    // Check for dimes
    while (cashBack >= 10)
    {
        cashBack -= 10;
        numSteps++;
    }
    // Check for nickels
    while (cashBack >= 5)
    {
        cashBack -= 5;
        numSteps++;
    }
    // Check for pennies
    while (cashBack >= 1)
    {
        cashBack -= 1;
        numSteps++;
    }
    printf("%i\n", numSteps);
}