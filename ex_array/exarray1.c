#include <stdio.h>
#include <stdlib.h>
// use global memary
void printarray(int array[], int len);
int findmax(int tab[], int size);
int sumarray(int tab[], int size);
void reverseorder(int tab[],int size);
void swap(int tab[], int size, int pos1, int pos2);
int deletedup(int tab[], int tab3[], int l);
void sortarray(int tab[], int tab2[],int size);
int main()
{
    int tab1[] = {5, 6, 7, 8, 9, 10, 15, 5,8};
    int l1 = sizeof(tab1) / sizeof(tab1[0]); // get length of array
    printf("the 1st array is:\n");
    printarray(tab1, l1); // print the 1starray
    reverseorder(tab1, l1);
    printf("the reverse array is:\n");
    printarray(tab1, l1); // print the reverse array
    int max, sum;
    max = findmax(tab1, l1);
    sum = sumarray(tab1, l1);
    printf("the max value of the array is %d\n", max);
    printf("the sum of the array is %d\n", sum);
    int pos1=3,pos2=5;
    swap(tab1, l1, pos1, pos2);
    printf("after change the positioin %d and %d tha array is:\n", pos1,pos2);
    printarray(tab1, l1); // the reverse array change the position
    int tab3[l1]; //tab3 is the new array size will be equal or smaller than l1
    int n; //n is the new size of tab3
    n=deletedup(tab1, tab3, l1);
    printf("the array after delete duplicate is:\n");
    printarray(tab3, n); //the reverse array delete the duplicate
    int tab2[l1];//define new array to store the sorted array
    sortarray(tab1, tab2, l1);
    printf("the array after sorted:\n");
    printarray(tab2, l1); //the reverse array delete the duplicate
    return 0;
}
void printarray(int array[], int len)
{
    //printf("the array is:");
    for (int i = 0; i < len; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int findmax(int tab[], int size)
{
    int max = tab[0];
    for (int i = 0; i < size; i++)
    {
        if (tab[i] > max)
            max = tab[i];
    }
    return max;
}
void reverseorder(int tab[], int size)
{
    for (int i = 0; i < (size/2); i++)
    {   int temp;
        temp=tab[i];
        tab[i] = tab[size - 1 - i];
        tab[size - 1 - i]=temp;
    }
}
int sumarray(int tab[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + tab[i];
    }
    return sum;
}
void swap(int tab[], int size, int pos1, int pos2)
{
    int temp;
    temp = tab[pos1];
    tab[pos1] = tab[pos2];
    tab[pos2] = temp;
}
int deletedup(int tab[], int tab3[], int l) //n as new array size;
{
   int n=0;
   for (int i = 0; i < l; i++)
    { int duplicate=0;
        for ( int j = 0; j <n; j++)
        {
            if (tab[i]==tab3[j])
            {
                duplicate=1;
                break;
            }   }
      if (!duplicate)
      {
        tab3[n]=tab[i];
        n++;
      }}
      return n;
}
void sortarray(int tab[], int tab2[],int size)
{
    int temp;
for (int i = 0; i < 10; i++)
    {
        tab2[i] = tab[i];
        for (int j = i; j < size; j++)
        {
            if (tab2[i] > tab[j])
            {
                temp = tab2[i];
                tab2[i] = tab[j];
                tab[j] = temp;
            }
        }
}
}