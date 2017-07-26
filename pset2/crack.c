// My solution for crack problem. No comments on purpose. Method hint: double dabble.

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
    
    char base52[] = "ABCDEFGHIJKLMNOPQRSTUVQKYZabcdefghijklmnopqrstuvqkyz";
    char convertedbase52[] = "\0\0\0\0";
    int j = 0;
    
    for(long i = 0; i < 7311616; i++)
    {
        j = 0;
        
        for(long n = i; n > 0; n /= 52)
        {
            convertedbase52[j] = base52[n % 52];
            j++;
        }
        
        if (strcmp(crypt(convertedbase52, "50"), argv[1]) == 0)
        {
            printf("%s\n", convertedbase52);
            return 0;
        }
    }
}