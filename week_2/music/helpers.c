// Helper functions for music

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // Convert numerator and denominator into individual ints
    int numerator = fraction[0] - '0';
    int denominator = fraction[2] - '0';
    // If fraction is simplified (i.e.: not x/8), multiply both sides by 2 until it is
    while (denominator != 8)
    {
        denominator *= 2;
        numerator *= 2;
    }
    return numerator;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // Parse string into note and octave
    int n;
    double f;
    int octave = note[strlen(note) - 1] - '0';
    // n is how many semitones note is from A
    switch (note[0])
    {
        case 'C' :
            n = -9;
            break;
        case 'D' :
            n = -7;
            break;
        case 'E' :
            n = -5;
            break;
        case 'F' :
            n = -4;
            break;
        case 'G' :
            n = -2;
            break;
        case 'A' :
            n = 0;
            break;
        case 'B' :
            n = 2;
            break;
        default:
            return 0;
    }
    // If note is sharp n + 1 UNLESS it is to the left of A
    if (note[1] == '#')
    {
        n = n <= 0 ? n + 1 : n - 1;
    }
    // Else if note is flat n - 1 UNLESS it is to the left of A
    else if (note[1] == 'b')
    {
        n = n >= 0 ? n - 1 : n + 1;
    }
    // f = (2 ^ n/12) * 440
    f = pow(2, (n / 12.0)) * 440.0;
    // Frequency increases or decreases at ~2^(|octave - 4|)
    f = octave > 4 ? f * pow(2, (octave - 4)) : f / pow(2, (4 - octave));
    return round(f);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // If next string is an empty line return true, else return false
    if (s[0] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}
