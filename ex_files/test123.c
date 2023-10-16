#include "stdio.h"
#include "stdlib.h"
int main()
{	FILE *fp;
	char s[100];
	if((fp=fopen("123.TXT","w"))==NULL)
	{	printf("can't open file\n");
		exit(1); }
	char *str="22.5,22.4,22.6,21.3";
    fputs(str, fp);
    fclose(fp);
    if((fp=fopen("123.TXT","r"))==NULL)
	{  printf("can't open file\n");
	 exit(1);  }
	 fgets(s,20,fp); //put the 19lettre of file into string s
             puts(s);//display s
    return 0;
}