// C program to check
// if a number is even or odd
// using command line arguments

#include <stdio.h>
#include <stdlib.h> /* atoi */

// Function to the check Even or Odd
int isEvenOrOdd(int num)
{
    return (num % 2);
}

// Driver code
int main(int argc, char* argv[])
{

    int num, res = 0;

    // Check if the length of args array is 1
    if (argc == 1)
        printf("No command line arguments found.\n");

    else {

        // Get the command line argument and
        // Convert it from string type to integer type
        // using function "atoi( argument)"
        num = atoi(argv[1]);

        // Check if it is even or odd
        res = isEvenOrOdd(num);

        // Check if res is 0 or 1
        if (res == 0)
            // Print Even
            printf("Even\n");
        else
            // Print Odd
            printf("Odd\n");
    }
    return 0;
}