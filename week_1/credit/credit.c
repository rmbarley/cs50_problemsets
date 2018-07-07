#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Initialize variables
    long long cardNo, cardCopy;
    int lastDigit;
    // Prompt user for CC #
    cardNo = get_long_long("Credit Card Number: ");
    // Checksum to see if card is invalid
    cardCopy = cardNo;
    while (cardCopy != 0)
    {
        lastDigit = cardCopy % 10;
        printf("%i ", lastDigit);
        cardCopy /= 10;
    }
}