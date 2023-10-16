#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int guess(char g, char mot[], char new[]);
int main()
{
     char mot[] = "abandon"; // to use random mot
    // char mot[10]; // declaration of char array
    // printf("Enter the first string : \n");
    // scanf("%s", mot);
    char test;
    int length = strlen(mot);
    char devine[length]; // array to put the devine mot
    int essai = 1;       // define test number
    int a, fail = 0;     // define fail number
    printf("%s has %zu byte\n", mot, length);
    for (int i = 0; i < length; i++)
    {
        devine[i] = '_';
    }
    for (int j = 1; j <= 50; j++)
    {
        printf("please entre the %d char you guessed:\n", j);
        scanf(" %c", &test);
        a = guess(test, mot, devine);
        if (a == 1) // wrong char being tested
        {
            fail = fail + 1;
            printf("you have guessed %d times wrong char:\n", fail);
        }
        if (fail == 5) // wrong number to 5,failed
        {
            printf("sorry,you just killed the man!\n");
            break;
        }
        if (!strcmp(mot, devine)) // strcmp(mot,devine)=0 when the same
        {
            printf("you are great, the world is correct!\n");
            break;
        }
    }
    // printf("%s\n", mot);
    // printf("%s\n", devine);

    // for (int i = 0; i < length; i++)
    // {
    //     if (devine[i] == '_')
    //     {
    //         ss = false;
    //         break;
    //     }
    // }
    return 0;
}

int guess(char g, char mot[], char new[])
{
    int length = strlen(mot);
    bool te = false;
    int fa;
    for (int i = 0; i < length; i++)
    {
        if (g == mot[i])
        {
            new[i] = g;
            te = true;
        }
    }
    if (!te)
    {
        printf("oups, the chat %c is not in the mot.\n", g);
        fa = 1;
    }
    else
    {
        printf("%s\n", new);
        fa = 0;
    }
    return fa;
}