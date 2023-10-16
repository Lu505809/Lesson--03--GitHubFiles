#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
//ex1013 part1
typedef struct Position
{
    float x;
    float y;
} Position;
float distance(Position p1, Position p2)
{
    float x_diff = p1.x - p2.x;
    float y_diff = p1.y - p2.y;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}
Position* closest_positions(Position* positions,  int *array_size, Position query, float maximum_distance)
{
    Position * newp;
    newp=(Position *)calloc(sizeof(Position),*array_size);//malloc maxsize is the orininal size
    int newsize=0;
    for (int i = 0; i < *array_size; i++) {
        float dist = distance(positions[i], query);
        if (dist <= maximum_distance) {
            newp[newsize] = positions[i];
            newsize++;
        }
    }
     printf("newsize is %d",newsize);
    //allocate newsize;
    newp = (Position*)realloc(newp, (newsize) * sizeof(Position));
    //newp[newsize]={0,0};
   *array_size=newsize;
    return newp;
}
int main()
{
    /*Position Pos[3];

    Pos[0].x = 1.1;
    Pos[0].y = 2.2;
    Pos[1].x = 3.3;
    Pos[1].y = 4.4;
    Pos[2].x = 5.3;
    Pos[2].y = 6.4;
    int size=3;
    Position query={1,1};
    float max_dis=2;
    Position* newp = closest_positions(Pos, &size,query, max_dis);
    //int newsize;
    int i=0;
     while (i<size)
     {
      printf("the closeset position %d is: x=%g,y=%g\n",i,newp[i].x,newp[i].y);
        i++;
     }
     free(newp);
    //printf("the ditance is %g", dist);*/
    float* data;
    int size=5;
    data=(float*)malloc(size*sizeof(float));
    data[0] = 1.1;
    data[1] = 2.2;
    data[2] = 5.6;
    data[3] = 7.8;
    data[4] = 9.0;
    char *strdata;
    strdata=(char*)calloc(sizeof(float),100);
    for (int i = 0; i < 5; ++i) {
        // Convert float to string
        char buffer[20];
        snprintf(buffer, sizeof(buffer), "%.2f", data[i]);
        char *str2=", ";
        if (i==4)
        {
           str2=". ";
        }
        strcat(buffer,str2);
        strcat(strdata,buffer);
    }
    printf("strdata is %s",strdata);
    return 0;
}