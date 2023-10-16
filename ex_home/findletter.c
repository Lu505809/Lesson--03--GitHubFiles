#include "stdio.h"
#include "string.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
void find(char s[], int p[], char *chmax, int *max);
int main()
{
    int p[26];
    int i=0, max;
    //char s[]="how do you do?";
    char s[80];
    char chmax;
    printf("please entre your word:\n");
    gets(s);// scanf won't take the espace of letter
    find(s, p, &chmax, &max);
  // while (s[i] != '\0')
 //{printf("%c\n",s[i]);i++;}
    for (i = 0; i < 26; i++)
    {
        if (p[i])
           {printf("the letter %c is appeared %d times\n ", (char)(i + 97), p[i]);} 
    }
    printf("the letter %c is appeared most: %d \n ", chmax, max);
    return 0;
}
void find(char s[], int p[], char *chmax, int *max)
{
    for (int i = 0; i < 26; i++)
    {
        p[i] = 0;
    }          // put 0 to array p;
    strlwr(s); // change the string in lowercase
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            p[(s[i] - 'a')]++;
        }
         i++;
    } // calculate the number of every letter
    *max = p[0];
    int k = 0;
    for (i = 1; i < 26; i++)
    {
        if (p[i] > *max)
        {
            *max = p[i];
            k = i;
        }
    } // find the max number of letter
    *chmax = k + 97;
}