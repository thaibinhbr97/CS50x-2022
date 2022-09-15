#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Check if every char in a string s is unique. Return 1 if it is True and False otherwise.
int is_char_unique(string s)
{
    int length = strlen(s);
    int letter_count[length];
    int count;
    for (int i = 0; i < length; ++i)
    {
        count = 0;
        for (int j = 0; j < length; ++j)
        {
            if (s[j] == s[i])
            {
                count++;
            }
        }
        letter_count[i] = count;
    }
    for (int k = 0; k < length; ++k)
    {
        if (letter_count[k] != 1)
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, string argv[])
{
    // This string used to map the plaintext to ciphertext
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Steps
    // 1: get key
    // 2: validate key
    // 3: get plaintext
    // 4: encipher
    // 5: print ciphertext

    // 1: get key
    // program accepts single command line arg, the key. The key is case-insensitive.
    // no command line arg or > 1 -> handle error
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // 2: validate key
    // the invalid key includes:
    // not contain 26 chars
    // contain any char that is not an alphabetic char
    // not contain each letter exactly one
    // for all these cases -> handle error
    string key = argv[1];
    int length = strlen(key);
    // If it is a valid key
    if (length == 26)
    {
        for (int i = 0; i < length; i++)
        {
            if (!isalpha(key[i]))
            {
                printf("Key must not contain alphabetic characters.\n");
                return 1;
            }
        }

        if (!is_char_unique(key))
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // 3: get plaintext
    // use get_string to get input from user
    string plaintext = get_string("plaintext:  ");

    // 4: encipher
    // for each alphabetic char, check what letter it maps to
    // preserve case
    // leave non-alphabetic chars as it is
    int length_text = strlen(plaintext);
    int ciphertext[length_text];
    // Check a position of a letter of plaintext in a mapping, then use it to map back from key to ciphertext
    for (int i = 0; i < length_text; ++i)
    {
        if (isalpha(plaintext[i]))
        {
            for (int j = 0; j < length; ++j)
            {
                if (isupper(plaintext[i]))
                {
                    if (plaintext[i] == toupper(alphabet[j]))
                    {
                        ciphertext[i] = toupper(key[j]);
                    }
                }
                else
                {
                    if (plaintext[i] == tolower(alphabet[j]))
                    {
                        ciphertext[i] = tolower(key[j]);
                    }
                }
            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    // 5: print ciphertext
    // use printf to print the result and return 0
    printf("ciphertext: ");
    for (int i = 0; i < length_text; ++i)
    {
        printf("%c", ciphertext[i]);
    }
    printf("\n");
    return 0;
}
