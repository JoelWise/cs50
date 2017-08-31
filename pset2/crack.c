#define _XOPEN_SOURCE
#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <crypt.h>

int main(int argc, string argv[]){

    if(argc != 2){
        printf("Error: You must past exactly one hashed password as argument.\n");
        return 1;
    }

	// Digit set for a base52 number system
    char base52[] = "ABCDEFGHIJKLMNOPQRSTUVQKYZabcdefghijklmnopqrstuvqkyz";
    char convertedbase52[] = "\0\0\0\0";
    int j = 0;

    // Iterate over all base10 numbers represented by a 4 digit base52 number (52^2 = 7311616)
    for(long i = 0; i < 7311616; i++)
    {
        // Convert base10 number into a base52 number ordered LSB to MSP left to right
        for(long n = i; n > 0; n /= 52)
        {
            convertedbase52[j] = base52[n % 52];
            j++;
        }

        // Base52 number represents a possible password. Salt/hash & compare to user-provided hashed password
        if (strcmp(crypt(convertedbase52, "50"), argv[1]) == 0)
        {
            printf("%s\n", convertedbase52);
            return 0;
        }

        j = 0;
    }
}