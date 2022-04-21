#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[1])
{
    // Check if second argument is input
    if (argc != 2)
    {
        // Error if argument is not input
        printf("Please enter a key for encryption\n");
        return 1;
    }
    
    // Proceed if second argument is present
    else
    {
        // If second argument is not number -> Print Error
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                printf("Usage: ./ceasar key\n");
                return 1;
            }
        }
        
        // Prompt User for plaintext
        string plaintext = get_string("plaintext: ");
        
        printf("ciphertext: ");
        
        // Loop for rotating characters
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            int cipher = 0;
            
            // Check if character is uppercase
            if (isupper(plaintext[i]))
            {
                cipher = ((int) plaintext[i] - 64) + atoi(argv[1]) % 26;
                
                cipher += 64;
                
                if (cipher >= 123)
                {
                    cipher -= 26;
                }
            }
            
            // Check if character is lowercase
            else if (islower(plaintext[i]))
            {
                cipher = ((int) plaintext[i] - 96) + atoi(argv[1]) % 26;
                
                cipher += 96;
                
                if (cipher >= 123)
                {
                    cipher -= 26;
                }
            }
            
            // If character is anything else, just print
            else
            {
                cipher = plaintext[i];
            }

            // Print result
            printf("%c", cipher);
        }
        
        // Print new line to finish
        printf("\n");
        return 0;
    }
}