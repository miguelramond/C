#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Counter Prototype
int counter(string text, int mode);

int main(void)
{
    int count[3];
    int mode = 0;

    // Get text to analyse from user
    string text = get_string("Text: ");

    // Run counter, iterate through modes after each count and and save in array
    for (int i = 0; i < 3; i++)
    {
        count[i] = counter(text, mode);
        mode++;
    }

    // Perform Coleman-Liau's formula
    float index = (0.0588 * (((float) count[0] / (float) count[1]) * 100)) - (0.296 * (((float) count[2] / 
                  (float) count[1]) * 100)) - 15.8;

    index = round(index);

    // Print Coleman-Liau index result - if 16 add '+'
    
    if (index >= 16)
    {
        printf("Grade 16+\n");        
    }
    
    else if (index <= 0) 
    {
        printf("Before Grade 1\n");
    }
    
    else
    {
        printf("Grade %i\n", (int)index);
    }

    return 0;
}

// Counter helper function
int counter(string text, int mode)
{
    int value = 0;

    if (mode == 0)
    {
        // Make loop to find and count every letter in string
        for (int i = 0, n = strlen(text); i < n; i++)
        {
            // Only count if character is alphabetic
            if (isalpha(text[i]))
            {
                value++;
            }
        }
    }

    if (mode == 1)
    {
        // Make loop to find and count spaces in string - ALSO COUNT END \0
        for (int i = 0, n = strlen(text); i <= n; i++)
        {
            // Only count if character is alphabetic
            if (isspace(text[i]) || text[i] == '\0')
            {
                value++;
            }
        }
    }

    if (mode == 2)
    {
        // Make loop to find and count '.', '?' and '!' in string to count sentences
        for (int i = 0, n = strlen(text); i < n; i++)
        {
            // Only count if character is alphabetic
            if (text[i] == '.' || text[i] == '?' || text[i] == '!')
            {
                value++;
            }
        }
    }

    return value;
}