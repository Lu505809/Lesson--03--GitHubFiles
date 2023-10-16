#include <stdio.h>
#include <stdbool.h>
// array searching
int main()
{
 int array[] = { 110,79,77,88,57,49,10};
 size_t length = sizeof(array) / sizeof(array[0]);//get length of array
 printf("%d\n",length);
 bool search=false;
 int n=11,pos;
 //search n
for(int i=0; i <length; i++)
{
if (array[i]==n)
{
    pos=i;
    search=true;
    break;
}
}
if (search)
{
    printf("the %d is at the position %d of array!",n,pos);
}
else
{
    printf("the %d is not in array!(-1)",n);
}
return 0;
}