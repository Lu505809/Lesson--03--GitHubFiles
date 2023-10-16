// ex of pointer,dislay/sum/min/inerst

#include <stdio.h>
// #include <stdbool.h>
#include <stdlib.h>
// #include <string.h>
#include <time.h>
#define SIZE 7
void display(int *ptr, int size);
void displayReverse(int *ptr, int size);
int sumArray(int *ptr, int size);
void insertEnd(int *ptr, int size, int newnb);
int *insertFirst(int *tab, int size, int newnb);
int main()
{
   int *tab = (int *)malloc(SIZE * sizeof(int));
   srand(time(NULL));
   for (int i = 0; i < SIZE; i++) // creat random number from 1 to 100;
   {
      tab[i] = rand() % 100;
   }
   printf("the orignial array is: ");
   display(tab, SIZE);
   // insertEnd(ptr, SIZE, 66);
   int *newtab;
   newtab = insertFirst(tab, SIZE, 66);
   printf("\nthe new array is:");
   display(newtab, SIZE + 1);
   free(newtab);
   return 0;
}
int sumArray(int *ptr, int size)
{
   int sum = 0;
   for (int i = 0; i < size; i++)
   {
      sum = sum + *ptr;
      ptr++;
   }
   return sum;
}
void displayReverse(int *ptr, int size)
{
   ptr = ptr + size - 1;
   for (int i = 0; i < size; i++)
   {
      printf("%d \t", *ptr);
      ptr--;
   }
}
void display(int *ptr, int size)
{
   for (int i = 0; i < size; i++)
   {
      printf("%d \t", *(ptr + i));
   }
   // printf("adresse in display%p \n", ptr);
}
void insertEnd(int *ptr, int size, int newnb)
{
   ptr = ptr + size;
   *ptr = newnb;
}
int *insertFirst(int *tab, int size, int newnb)
{

   // int *newtab = (int *)realloc(tab,(size+1)*sizeof(int));
   int *newtab = (int *)realloc(tab, (size + 1) * sizeof(int));
   if (newtab == NULL)
   {
      printf("Memory reallocation failed.\n");
      free(tab);   // Free the original array
      return NULL; // Exit with an error code
   }
   for (int i = size; i >0; i--)
   {   
      *(newtab + i) =*(newtab + i-1) ; // only change the values
   }
   *newtab = newnb;
   return newtab;
}