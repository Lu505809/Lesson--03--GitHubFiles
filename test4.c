#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    float x;
    float y;
} Point;
typedef struct
{
    float temper;
    Point point;
} Temperature;
float average_temp(Temperature t1,Temperature t2);
int main(void)
{
    Point p1;
    Point *ptr;
    ptr = &p1;
    (*ptr).x = 1.5;
    (*ptr).y = 2.6;
    Temperature t1,t2;
    float a1=38.5;
    float a2=-26.5;

    t1.temper=a1;
    t2.temper=a2;
    float avg=average_temp(t1,t2);
    
    if(avg!=(a1+a2)/2)
    printf("there is some error in line %d\n", __LINE__);
    printf("%f",avg);
    //printf("x results is:%f\n", p1.x);
    //printf("y results is:%f\n", p1.y);
}
float average_temp(Temperature t1,Temperature t2)
{
    float avg_temp;
    avg_temp=(t1.temper+t2.temper)/2;
    return avg_temp;
}