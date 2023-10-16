#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main()
{
    // printf("please entre your interger number");
    int N = 100;
    // scanf("%d", &N);
    int i, j, re;
    bool tt = true;
    for (i = 2; i < N; i++)

    {
        for (j = 2; j <= (i / 2); j++)

        {
            tt = true;
            re = i % j;
            if (re == 0)
            {
                tt = false;
                break;
            }
        }
        if (tt)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}
//prime function
bool prime(int a)
{
    bool tt = true;
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

