#include "stdio.h"
static int fib(int n);
int main()
{
    int n = 6;
    printf("the fibonacci result of %d is %d", n, fib(n));
    return 0;
}
static int fib(int n)
{
    int result;
    if (n == 0)
        result = 0;
    else if (n == 1)
    {
        result = 1;
    }

    else
    {
        result = fib(n - 1) + fib(n - 2);
    }
    return result;
}