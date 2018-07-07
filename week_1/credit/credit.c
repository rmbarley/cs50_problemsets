#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Initialize variables
    long long cardNo, cardCopy;
    int lastDigit;
    int digits;
    int underlinedSum = 0;
    int otherSum = 0;
    int checkSum = 0;
    bool digitIsUnderlined = false;
    // Prompt user for CC #
    // Test CC 378282246310005
    cardNo = get_long_long("Credit Card Number: ");
    // Checksum to see if card is invalid
    cardCopy = cardNo;
    digits = (int)log10(cardNo);
    while (cardCopy != 0)
    {
        lastDigit = cardCopy % 10;
        cardCopy /= 10;
        // Using verbiage that every other digit starting at 2nd to last is 'underlined'
        if (digitIsUnderlined)
        {
            // Multiply by 2
            lastDigit *= 2;
            // If result is greater than 9, add digits individually (i.e. 14 yields 1 + 4)
            while (lastDigit != 0)
            {
                underlinedSum += lastDigit % 10;
                lastDigit /= 10;
            }
            // Next digit is not underlined
            digitIsUnderlined = false;
        }
        else
        {
            // add together
            otherSum += lastDigit;
            // Next digit is underlined
            digitIsUnderlined = true;
        }
    }
    checkSum = underlinedSum + otherSum;
    // To be valid, the last digit of checkSum must be 0
    if (checkSum % 10 == 0)
    {
        if ((int)(cardNo / pow(10, digits)) == 4 && (digits == 13 || digits == 15))
        {
            printf("VISA\n");
        }
        else if (cardNo >= 5100000000000000 && cardNo < 5600000000000000)
        {
            printf("MASTERCARD\n");
        }
        else if ((cardNo >= 340000000000000 && cardNo < 350000000000000) || (cardNo >= 370000000000000 && cardNo < 380000000000000))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}