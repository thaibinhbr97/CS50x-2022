#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    printf("Score1: %i\n", score1);
    printf("Score2: %i\n", score2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    // Initilize the score, length for the word
    int score = 0;
    int length = strlen(word);

    // A loop going through each letter in the word
    for (int i = 0; i < length; i++)
    {
        // If the letter is in uppercase, turn them into a lowercase letter
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            word[i] = word[i] + 32;
        }
        // Now it is all in lowercase, use it and the POINTS array to get a point for that letter
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            score += POINTS[word[i] - 97];
        }
    }
    return score;
}
