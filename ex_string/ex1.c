#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
void findlettre(char find, char str[]);
void reverse(char restr[], char str[]);
int main()
{
    char s[] = "how are you?";
    int len;
    len = strlen(s);//get length of string
    char res[len];//define newstring
    reverse(res, s);//reverse string
    printf("the 1st string is: %s\n", s);
    printf("the reverses string is :%s\n", res);
    //findlettre(f, s);
    return 0;
}
void findlettre(char find, char str[])
{
    int size = strlen(str);
    bool tt = false;
    for (int i = 0; i < size; i++)
    {
        if (find == str[i])
        {
            printf("the letter %c is in position %d\n", find, i);
            tt = true;
        }
    }
    if (!tt)
    {
        printf("the letter %c is not in the string\n", find);
    }
}

void reverse(char restr[], char str[])
{
    int size = strlen(str);
    for (int i = 0; i < size; i++)
    {
        restr[i]=str[size-1-i];
    }
    
}