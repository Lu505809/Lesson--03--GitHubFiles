
#include <stdio.h>
#include <stdlib.h>
void printarray(int tab [][5],int nb1,int nb2);
int main()
 {
    int nb1=3,nb2=5;
    int tab [nb1][nb2];
    int nb=nb1*nb2;
    int tab2 [nb];
for (int i = 0; i < nb1; i++)
{
    for (int j = 0; j < nb2; j++)
    {
        tab [i][j]=i+j;
        tab2[i*5+j]=tab [i][j];
        printf("%d\t", tab[i][j]);
    }
    printf("\n");
}
printarray(tab,3,5);
printf("the new array is:\n");
for (int i = 0; i < nb; i++)
{
   printf("%d\t", tab2[i]);
}
    return 0;
 }
 
 void printarray(int tab [][5],int nb1,int nb2)
 {
    for (int i = 0; i < nb1; i++)
{
    for (int j = 0; j < nb2; j++)
    {
        printf("%d\t", tab[i][j]);
    }
    printf("\n");
 }}