#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;
    long id = 0;
    int num = 0;
    int right = 0;
    int left = 0;
    int odds = 0;
    int evens = 0;
    int luhn = 0;
    int count = 0;
    bool check = true;
    bool use = false;
    bool tens;
    
    // Ask user to input credit card
    card = get_long("\nPlease input a credit card number ");
    
    // Translate card number to variables for validation
    id = card;
    num = card;
    
    // Divide card number until reach first two numbers to identify issuing company
    while (id > 100)
    {
        id = id / 10;
    }
    
    // Loop for singling out every other number to execute Luhn's algorithm
    while (card > 0)
    {
        // Determine remainder of card for last two digits
        num = card % 10;
        
        // Multiply remainder by two for verification
        num = num * 2;
        
        // Add +1 to count to determine input length
        count++;
        
        // If on even position then perform first part of Luhn's algorithm 
        if (use == true)
        {
            // Variables for singling out digits > 10
            right = num;
            left = num;
            {
                // Modulo 10 of number to get first value
                right = num % 10;
                
                // Number / 10 to get second digit in case it is > 10
                left = num / 10;
                
                // Sum addition of all even numbers for Luhn's algo
                evens = evens + (right + left);
            }
        }
        
        // If on odd position then perform second part of Luhn's Algorithm
        if (use == false)
        {
            // Determine and add odd numbers
            odds = odds + (card % 10);
        }
        
        // Divide card number by 10 to move one position left and repeat process
        card = card / 10;
        
        // Toggle boolean data type for allocation of numbers in either even or odds variable
        use = !use;
    }
    
    // Put addition of even and odds in a variable for calculation
    luhn = evens + odds;
    
    // Calculate modulo 10 of evens + odds
    luhn = luhn % 10;
    
    // Boolean expression - if luhn check OK, true, if not, false
    if (luhn == 0)
    {
        check = true;
    }
    
    else if (luhn != 0)
    {
        check = false;
    }
    
    // Check start numbers and valid = AMEX
    if ((id == 34 || id == 37) && check == true && count == 15)
    {
        printf("AMEX\n");
    }
    
    // Check start numbers and valid = Mastercard
    if ((id == 51 || id == 52 || id == 53 || id == 54 || id == 55) && check == true && count == 16)
    {
        printf("MASTERCARD\n");
    }
    
    // Check start numbers, valid result and count = Visa
    if (id / 10 == 4 && check == true && count >= 13 && count <= 16)
    {
        printf("VISA\n");
    }
    
    // Check if algo invalid - Invalid Result
    if (check == false)
    {
        printf("INVALID\n");
    }
    
    // Check if algo valid but starting numbers not correct - Invalid
    if (check == true && id != 34 && id != 37 && id != 51 && id != 52 && id != 53 && id != 54 && id != 55 && id / 10 != 4)
    {
        printf("INVALID\n");
    }
    
    // Check if algo ok, but total digits < 13 or > 16 - Invalid
    else if (check == true && (count < 13 || count > 16))
    {
        printf("INVALID\n");
    }
}