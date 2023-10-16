#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// array add
/*int main()
{
 int tab[] = {110,79,77,88,57,49,10};
 size_t length = sizeof(tab) / sizeof(tab[0]);//get length of array
 printf("the length of the array is %d\n",length);
  int newtab[length+1];
  int i=0,s=66;
   for(i=0; i <length; i++)
   {
    newtab[i]=tab[i];
   }
  newtab[length]=s;
  for(i=0; i <(length+1); i++)
   {
    printf("%d\t",newtab[i]);
   }
return 0;
}

//add arrayfirst
int main()
{
 int tab[] = {110,79,77,88,57,49,10};
 size_t length = sizeof(tab) / sizeof(tab[0]);//get length of array
 printf("the length of the array is %d\n",length);
  int newtab[length+1];
  int i=0,s=66;
   for(i=0; i <length; i++)
   {
    newtab[i+1]=tab[i];
   }
  newtab[0]=s;
  for(i=0; i <(length+1); i++)
   {
    printf("%d\t",newtab[i]);
   }
return 0;
}*/
// add 2 array
void printarray(int array[], int len);
void add2array(int tab1[], int tab2[], int newtab[],int l1,int l2);
void randarray(int tab[],int length);
int main()
{
   srand(time(NULL)); 
   int l1=8,l2=10;
   int tab1[l1],tab2[l2];
   randarray(tab1,l1);
   randarray(tab2,l2);
   //size_t l1 = sizeof(tab1) / sizeof(tab1[0]); // get length of array
   //size_t l2 = sizeof(tab2) / sizeof(tab2[0]); // get length of array
  // printf("the length of the array1 is %d and the array2 is %d\n", l1, l2);
   int l = l1 + l2;
   int newtab[l];
   add2array(tab1, tab2, newtab,l1,l2);
   printarray(tab1, l1);
   printarray(tab2, l2);
   printarray(newtab, l);
   return 0;
}
void add2array(int tab1[], int tab2[], int newtab[],int l1,int l2)
{
   int i;
   for (i = 0; i < l1; i++)
   {
      newtab[i] = tab1[i];
   }
   for (i = 0; i < l2; i++)
   {
      newtab[l1 + i] = tab2[i];
   }
}
void printarray(int array[], int len)
{
   printf("the array is:");
   for (int i = 0; i < len; ++i)
   {
      printf("%d ", array[i]);
   }
   printf("\n\n");
}
void randarray(int tab[],int length) 
{
    for (int i = 0; i < length; i++)
    {
        tab[i]=rand()%100;//generate random numbers from 0 to 100
    }
}