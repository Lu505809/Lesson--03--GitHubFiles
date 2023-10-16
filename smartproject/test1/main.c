#include <stdlib.h>
#include <stdio.h>
#include "head.h"

// go to complier C:\Users\u505809\cclu\mainc02\smartproject>gcc main.c lib.c head.h
//create a.exe file
//than run a.exe file   
int main()
{
    Point p1;
    //Point *ptr;
    //ptr = &p1;
    p1.x = 1.5;
    p1.y = 2.6;
    printf("x results is:%f\n", p1.x);
    printf("y results is:%f\n", p1.y);
    Average(p1);
    return 0;
}