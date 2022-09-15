#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Initialize n from the user
    long n = get_long("Number: ");
    long copy_n = n;

    int other_digit = 0;
    int digit = 0;
    int result_other_digit = 0;
    int result_digit = 0;
    int check_sum = 0;
    int count_digit = 0;

    // Initialize odd_pos to check if a digit in odd position or even position
    bool odd_pos = true;

    // Initialize first and second digit of n from the left
    int first = 0;
    int second = 0;

    // Initialize first and second digit of a result when multiplying a number by 2 (for adding products' digits)
    int first_digit = 0;
    int second_digit = 0;

    // Initialize the last digit of check_sum. If it is 0, n is a valid card number
    int last_digit = 0;

    while (true)
    {
        // Check if it is a last digit from the right, break the loop if it is
        if (n / 10 == 0)
        {
            // Keep track of number of digits of n
            count_digit += 1;

            first = n;
            if (odd_pos == false)
            {
                other_digit = (n % 10) * 2;
                if (other_digit >= 10)
                {
                    first_digit = other_digit % 10;
                    second_digit = other_digit / 10;
                    other_digit = first_digit + second_digit;
                }
                result_other_digit += other_digit;
            }
            else
            {
                result_digit += (n % 10);
            }
            break;
        }
        if (n / 100 == 0)
        {
            second = n % 10;    
        }
        // Check if a digit is in an odd position
        if (odd_pos == false)
        {
            other_digit = (n % 10) * 2;
            if (other_digit >= 10)
            {
                first_digit = other_digit % 10;
                second_digit = other_digit / 10;
                other_digit = first_digit + second_digit;
            }
            result_other_digit += other_digit;
            odd_pos = true;
        }
        // Check if a digit is in an even position
        else
        {
            digit = (n % 10);
            result_digit += digit;
            odd_pos = false;
        }
        n = n / 10;
        count_digit += 1;
    }
    // Calculate check_sum
    check_sum = result_other_digit + result_digit;

    // Get the last digit of check_sum
    last_digit = check_sum % 10;

    // printf("Check_Sum: %i\n", check_sum);
    // printf("Last_Digit: %i\n", last_digit);
    // printf("First: %i\n", first);
    // printf("Second: %i\n", second);
    // printf("Count_Digit: %i\n", count_digit);

    // Given a last_digit, check if n is a valid card number or not.
    // If it is, check if n is a valid AMEX, Mastercard, or Visa card.
    if (last_digit == 0)
    {
        if (count_digit == 13)
        {
            if (first == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (count_digit == 15)
        {
            if ((first == 3) && (second == 4 || second == 7))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (count_digit == 16)
        {
            if (first == 4)
            {
                printf("VISA\n");
            }
            else if (first == 5 && (1 <= second && second <= 5))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}