#include <stdio.h>
#include <stdlib.h>
//delete the duplicates in array;
void printarray(int array[], int len);
int main()
{
  // srand(time(NULL)); 
   int tab1[]={5,6,7,8,9,10,10,9,8,10,15,25,58,5,4,3};
   int l1 = sizeof(tab1) / sizeof(tab1[0]); // get length of array
    printf("the length of original array is %d\n",l1);
   int l2=0;
   int tab2[l1];
   printarray(tab1, l1);//print the array
   for (int i = 0; i < l1; i++)
    { int duplicate=0;
        for ( int j = 0; j <l2; j++)
        {
            if (tab1[i]==tab2[j])
            {
                duplicate=1;
                break;
            }   }
      if (!duplicate)
      {
        tab2[l2]=tab1[i];
        l2++;
      }}
    printf("the length of the new array is %d\n",l2);
    int tab3[l2];//new tab with correct length
    for (int i = 0; i < l2; i++)
    {
        tab3[i]=tab2[i];
            }
    printarray(tab3, l2);
   return 0;
}
void printarray(int array[], int len)
{
   printf("the array is:");
   for (int i = 0; i < len; ++i)
   {
      printf("%d ", array[i]);
   }
   printf("\n");
}
void deletearray(int tab[],int tab2[],int l,int n) //n as the position of delete number;
{
    for (int i = 0; i < n; i++)
    {
        tab2[i]=tab[i];
            }
    for (int i = n; i < l-1; i++)
    {
        tab2[i]=tab[i+1];
            }   
}