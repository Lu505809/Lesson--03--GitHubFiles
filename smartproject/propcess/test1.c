#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define UNIVERSE 42
#define log(message) printf("message: %s, line: %d\n", message, __LINE__)
#define ASSERT(boolean_expression)                                                                       \
    if (!(boolean_expression))                                                                           \
    {                                                                                                    \
        printf("boolean:%s is faux, the file:%s, the line:%d", #boolean_expression, __FILE__, __LINE__); \
        exit(0);                                                                                         \
    }
int main()
{
    int v1;
    v1 = UNIVERSE;
    printf("the number is%d\n", v1);
    ASSERT(3 > 4);
    ASSERT(5 > 4);
    return 0;
}