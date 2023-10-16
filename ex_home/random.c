
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
char *randstring(size_t length);
void randarray(int tab[],int length);
void printarray(int array[], int len);
int main()
{
    srand(time(NULL)); 
    //printf("%s",randstring(10));
    int tab [10];
    randarray(tab,10);
    printarray(tab,10);
    return 0;
}
void randarray(int tab[],int length) 
{
    for (int i = 0; i < length; i++)
    {
        tab[i]=rand()%100;//generate random numbers from 0 to 100
    }
}
char *randstring(size_t length) {

    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";        
    char *randomString = NULL;

    if (length) {
        randomString = malloc(sizeof(char) * (length +1));// assign a specified amount of memory for an array to be created

        if (randomString) {            
            for (int n = 0;n < length;n++) {            
                int key = rand() % (int)(sizeof(charset) -1);
                randomString[n] = charset[key];
            }

            randomString[length] = '\0';
        }
    }
    return randomString;
}
void printarray(int array[], int len)
{
    printf("the integer array is:");
    for (int i = 0; i < len; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}
