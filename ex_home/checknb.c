#include <stdio.h>
// function to check the scanf of right number!
int get_number(const char *prompt, int *valp);
int main()
{
    int a;
    if (!get_number("Number a", &a))
    {
        return 1;
    }
    printf("%d\n", a);
    return 0;
}

int get_number(const char *prompt, int *valp)
{
    char c;
    printf("%s:\n", prompt);
    while (scanf("%d", valp) != 1)
    {
        printf("Not a number, try again:\n");
        while ((c = getchar()) != EOF && c != '\n')
            continue;
        if (c == EOF)
            return 0;
    }
    return 1;
}