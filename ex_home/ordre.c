#include <stdio.h>
#include <stdlib.h>
int main()
{
    int arry[10] = {6, 7, 2, 4, 15, 9, 10, 12, 25, 16};
    int newarry[10];
    int i, j, a;
    for (i = 0; i < 10; i++)
    {
        newarry[i] = arry[i];
        for (j = i; j < 10; j++)
        {
            if (newarry[i] > arry[j])
            {
                a = newarry[i];
                newarry[i] = arry[j];
                arry[j] = a;
            }
        }
        printf("%d\n", newarry[i]);
    }
    return 0;
}