#include "stdlib.h"
#include "stdio.h"
#define SIZE 2
struct goods
{
   char bh[8];
   char mc[20];
   char jhrq[10];
   int dj;
} goods_array[SIZE], g[SIZE];
int main()
{
   FILE *fp;
   int i;
  for (i = 0; i < SIZE; i++)
   {
      puts("Input code:");
      gets(goods_array[i].bh);
      puts("Input name:");
      gets(goods_array[i].mc);
      puts("Input date:");
      gets(goods_array[i].jhrq);
      puts("Input price:");
      gets(&goods_array[i].dj);
   }
   if ((fp = fopen("magasin.dat", "wb")) == NULL)
   {
      printf("can't open file.\n");
      exit(1);
   }
   fwrite(goods_array, sizeof(goods_array), 1, fp); // 整个数组内容一次写入文件
   fclose(fp);                          // 文件要及时关闭
   if ((fp = fopen("magasin.dat", "rb")) == NULL)
   {
      printf("can't open file.\n");
      exit(1);
   }
 
      fread(g, sizeof(goods_array), SIZE, fp); // 一次只读出一条记录，反复读出,Read to pointer g
      
      for (int i = 0; i < SIZE; i++)
      {
printf("product%d's number is: %s \t", i, g[i].bh);
      printf("product%d's name is: %s\t", i, g[i].mc);
      printf("product%d's date is: %s\t", i, g[i].jhrq);
      printf("product%d's price is: %d\n", i, g[i].dj);
      }
     

   fclose(fp);

   return 0;
}