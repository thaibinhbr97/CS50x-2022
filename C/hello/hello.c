#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Ask user for input
    string name = get_string("What's your name? ");

    // Print
    printf("hello, %s\n", name);
}