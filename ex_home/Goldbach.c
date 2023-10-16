#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
bool prime(int a);
int main()
{
    int nb, i, j;
    printf("please entre your even number:\n");
    scanf("%d", &nb);
    bool t1, t2;
    int k;
    for (j = 6; j <= nb; j += 2)
    {
        printf("\n the number is: %d\n", j);
        printf("the result:\t");
        for (i = 3; i <= (j / 2); i += 2)
        {
            if (prime(i)&& prime(j-i))
            {
                printf("%d+%d=%d\t", i, j-i, j);
            }
        }
    }
    return 0;
}

bool prime(int a)
{
    bool tt=true;
    int re;
    for (int j = 2; j <= (a / 2); j++)
    {
        tt = true;
        re = a % j;
        if (re == 0)
        {
            tt = false;
            break;
        }
    }
    return tt;
}
