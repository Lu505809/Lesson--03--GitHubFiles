#include <stdio.h>
#include <stdbool.h>
// sorted array or not
int main()
{
 int array[] = { 110,79,77,88,57,49,10};
 size_t length = sizeof(array) / sizeof(array[0]);//get length of array
 printf("%d\n",length);
 bool increase=true, decrease=true;
 //sort increase
for(int i=0; i <(length-1); i++)
{
if (array[i]>array[i+1])
{
    increase=false;
    break;
}
}
//sort decrease
for(int i=0; i <(length-1); i++)
{
if (array[i]<array[i+1])
{
    decrease=false;
    break;
}
}
if (increase)
{
   printf("the array is in a increase order");
}
else if (decrease)
{
    printf("the array is in a decrease order");
}
else
{
    printf("the array is not in order");
}
return 0;
}