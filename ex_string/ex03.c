#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//int findlettre(char find, char str[]);
int main()
{
    char s[] = "How are you? I am fine!";
    char news[10];
    int len;
    int j=0;
    //int times;
    char spa=' ';
    len = strlen(s);//get length of string
    strlwr(s);
    if (s[0]>='a' && s[0]<='z')
    {
        news[j]=s[0]+'A'-'a';
        j++;
    }
    
    for (int i = 0; i < len-1; i++)
    {
        if (s[i]==spa && s[i+1]>='a' && s[i+1]<='z')
        {
            news[j]=s[i+1]+'A'-'a';
            j++;
        }
    }
    printf("the string is: %s\n", s);
    printf("the Acronym is: %s\n",news);
    return 0;
}
int findlettre(char find, char str[])
{
    int size = strlen(str);
    int times=0;
    for (int i = 0; i < size; i++)
    {
        if (find == str[i])
        {
            //printf("the letter %c is in position %d\n", find, i);
            times++;
        }
    }
    return times;
}