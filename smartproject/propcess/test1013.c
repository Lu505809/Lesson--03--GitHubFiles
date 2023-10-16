#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define PI 3.1415
#define log(message) printf("message: %s, line: %d\n", message, __LINE__)
#define ASSERT(boolean_expression)                                                                       \
    if (!(boolean_expression))                                                                           \
    {                                                                                                    \
        printf("boolean:%s is faux, the file:%s, the line:%d", #boolean_expression, __FILE__, __LINE__); \
        exit(0);                                                                                         \
    }
int main()
{
    float v1;
    v1 = PI;
    printf("the number is%g\n", v1);
    return 0;
}