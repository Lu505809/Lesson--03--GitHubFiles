#include <stdio.h>
#include <stdlib.h>
// ex for struct
typedef struct Point
{
    float x;
    float y;
} Point;
Point *new_point(float x, float y);
float minimum_three_numbers(float n1, float n2, float n3);
void main()
{
    Point newp;
    newp.x = 1.2;
    newp.y = 2.4;
    printf("the new point x value is: %f\n", newp.x);
    printf("the new point y value is: %f\n", newp.y);
    /*float n1 = 1.5;
    float n2 = 3.5;
    float n3 = 2.5;
    float min;
    min = minimum_three_numbers(n1, n2, n3);
    if (min != n1)
    {
        printf("there is some error on line %d", __LINE__);
    }
    float m1 = 2, m2 = -5, m3 = 9;
    if (minimum_three_numbers(m1, m2, m3) != m2)
    {
        printf("there is some error on line %d", __LINE__);
    }*/
}
Point *new_point(float x, float y)
{
    Point *newp;
    newp = (Point *)malloc(sizeof(Point));
    newp->x = x;
    newp->y = y;
    return newp;
}
float minimum_three_numbers(float n1, float n2, float n3)
{
    float temp;
    temp = (n1 < n2) ? n1 : n2;
    return (n3 < temp) ? n3 : temp;
}
int count_value_above_threshold(float *values, int n_value, float threshold)
{
    int count = 0;
    for (int i = 0; i < n_value; i++)
    {
        if (values[i] >= threshold)
        {
            count++;
        }
    }
    return count;
}
