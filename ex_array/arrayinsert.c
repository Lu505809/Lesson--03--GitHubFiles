
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//add integer into right position;
void printarray(int array[], int len);
//void add2array(int tab1[], int tab2[], int newtab[],int l1,int l2);
void randarray(int tab[],int length);
int main()
{
   srand(time(NULL)); 
   int l1=10,l2=11,add,pos;
   int tab1[l1],tab2[l2];
   randarray(tab1,l1);//creat a random array,
   printarray(tab1, l1);//print the array
   add=rand()%100;
   printf("the integer you want to add is:%d\n",add);
   int sorttab1[10];
    int i, j, temp;
    for (i = 0; i < 10; i++)
    {
        sorttab1[i] = tab1[i];
        for (j = i; j < 10; j++)
        {
            if (sorttab1[i] > tab1[j])
            {
                temp= sorttab1[i];
                sorttab1[i] = tab1[j];
                tab1[j] = temp;
            }
        }
    }
    printarray(sorttab1, l1);//print the array in right order
for (i = 0; i < 10; i++)// find insert position;
    {if (sorttab1[i]<=add &&sorttab1[i+1]>=add )
    {
        pos=i+1;
        break;
    }}
    printf("insert position is %d\n",pos);
 for(i=0; i <pos; i++)
   {
    tab2[i]=sorttab1[i];
   }
   tab2[pos]=add;
for(i=pos+1; i <l2; i++)
   {
    tab2[i]=sorttab1[i-1];
   } 
   printarray(tab2, l2);//print the new array
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
   printf("\n");
}
void randarray(int tab[],int length) 
{
    for (int i = 0; i < length; i++)
    {
        tab[i]=rand()%100;//generate random numbers from 0 to 100
    }
}