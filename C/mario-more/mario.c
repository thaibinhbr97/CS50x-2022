#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare n
    int n;

    // Repeat until the condition for input n is met
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // For loop to print the pyramid
    for (int i = 0; i < n; i++)
    {
        // Printing the left side of the pyramid
        for (int j = 1; j <= n; j++)
        {
            if (j < n - i)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        // Printing the middle spaces of the pyramid
        printf("  ");

        // Print the right side of the pyramid
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // Add the end of each line, print the new line character to go to the next line
        if (i != n)
        {
            printf("\n");
        }
    }
}