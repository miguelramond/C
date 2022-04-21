#include <cs50.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int min = 9;
    int start;
    int target;
    int growth;
    int years = 0;

    // Prompt for start amount
    do
    {
        start = get_int("\nHow many llamas do you see grazing on the plains? ");

        // Error messages if user inputs number < min start amount
        if (start < min && start > 0)
        {
            printf("\n---> Those %i llamas seem quite lonely... There surely must be at least 9. Look harder!\n", start);
        }
        else if (start < 0)
        {
            printf("\n---> Futures trading of llamas and alpacas is yet to be implemented in this program.\n");
        }
        else if (start == 0)
        {
            printf("\n---> It is pretty much impossible for there to be %i llamas in these rolling bolivian plains. Look harder!\n", start);
        }
    }

    while (start < min);

    // Prompt for end amount
    do
    {
        target = get_int("\n%i Llamas seems about right. And how many llamas would you like to eventually see feasting on these fine pastures? ",
                         start);

        // Error message if user inputs number < start amount
        if (target < start)
        {
            printf("\n---> These generous lands will ensure this herd of majestic llamas will grow steadily as times passes. Please enter a larger number.\n");
        }
    }
    while (target < start);

    // Function in case target is same number as year
    if (start == target)
    {
        printf("\nYears: %i\n\n", years);
    }
    
    // Calculate number of years until we reach threshold
    else
    {
        do
        {
            growth = (float)(start / 3) - (float)(start / 4);
            start = (float)start + (float)growth;
            years++;
        }
        while (start < target);
        
        printf("\nYears: %i\n\n", years);
    }
    
}
