#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // int n = 50;
    // int *p = &n;
    // printf("%p\n", p);
    // printf("%i\n", *p);

    // // string s = "HI!";
    // char *s = "HI!";
    // char *p = &s[0];
    // printf("%p\n", s);
    // printf("%p\n", p);

    // char *s = "HI!";
    // char *p = &s[0];
    // // char **k = &s;
    // printf("%p\n", s);
    // printf("%p\n", &s[0]);
    // printf("%p\n", &s[1]);
    // printf("%p\n", &s[2]);
    // printf("%p\n", &s[3]);
    // // printf("%p\n", k);
    // // printf("%p\n", &s);

    // printf("%p\n", s);
    // printf("%p\n", &s[0]);
    // printf("%p\n", &s[1]);
    // printf("%p\n", &s[2]);
    // printf("%p\n", &s[3]);

    // char *s = "HI!";
    // // printf("%p\n", s);
    // // printf("%p\n", &s[0]);
    // printf("%c\n", *s);
    // printf("%c\n", *(s + 1));
    // printf("%c\n", *(s + 2));

    // // Testing (ignore)
    // char *s = "HI!";
    // char **p = &s;
    // printf("%c\n", **p);
    // printf("%c\n", **(p + 1));
    // printf("%c\n", **(p + 2));

    int numbers[] = {4, 6, 8, 2, 7, 5, 0};
    printf("%i\n", *(numbers));
    printf("%i\n", *(numbers + 1));
    printf("%i\n", *(numbers + 2));
    printf("%i\n", *(numbers + 3));
    printf("%i\n", *(numbers + 4));
    printf("%i\n", *(numbers + 5));
    printf("%i\n", *(numbers + 6));
}