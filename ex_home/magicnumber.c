#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define CHANCE 10
bool checkNum(int n);
int get_number(const char *prompt, int *valp);
int main()
{
    srand(time(NULL));
    int num = rand() % 100; // generate random numbers from 0 to 100
    int guess;
    int try = 0;
    int validinput = 1;
    printf("num is %d", num);
    printf("let's start,you will have %d chances to guess it.\n", CHANCE);

    while (try<CHANCE)
    {
         if (!get_number("please entre 1 number between 1 to 100", &guess)) 
         {return 1;}
            if (checkNum(guess))
            {
                try++;
                if (guess > num)
                {
                    printf("too big! and you still have %d chance.\n", (CHANCE - try));
                }
                if (guess < num)
                {
                    printf("too small!and you still have %d chance.\n", (CHANCE - try));
                }
                if (guess == num)
                {
                    printf("bravo! you just got it! with %d times test!\n", try);
                    break;
                }
                if (guess != num & try == CHANCE)
                {
                    printf("sorry you just lose the game\n");
                }
            }
            else
            {
                printf("wrong input,number not in range, try agagin!\n");
            }
    }

    return 0;
}
bool checkNum(int n)
{
    bool check = false;
    if (n > 0 && n <= 100)
    {
        check = true;
    }
    return check;
}
int get_number(const char *prompt, int *valp)
 { char c;
    printf("%s:\n", prompt);
    while (scanf("%d", valp) != 1) {
        printf("Not a number, try again:\n");
        while ((c = getchar()) != EOF && c != '\n')
            continue;
        if (c == EOF)
            return 0;
    }
    return 1;
}
