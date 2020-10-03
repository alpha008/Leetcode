/*
79.字符串排序

题目：字符串排序。

程序分析：无。
*/

#include<stdio.h>
#include <string.h>
 
void swap(char*str1,char*str2);

int main()
{
  char str1[20],str2[20],str3[20];

  printf("请输入3个字符串,每个字符串以回车结束!:\n");
  gets(str1);
  gets(str2);
  gets(str3);

  /*int strcmp(char *str1, char *str2);比较两个字符串str1, str2, 若str1<str2,返回负数,str1=str2,返回0,str1>str2,返回正数*/
  if(strcmp(str1,str2)>0)  
    swap(str1,str2);
  if(strcmp(str2,str3)>0)
    swap(str2,str3);
  if(strcmp(str1,str3)>0)
    swap(str1,str3);

  printf("从小到大排序:：\n");
  printf("%s\n%s\n%s\n",str1,str2,str3);
  return 0;
}

void swap(char*str1,char*str2)
{
  char tem[20];
  strcpy(tem,str1);  /*char * strcpy(char *str1,char * str2);把str2指向的字符串复制到str1中, 返回str1  */
  strcpy(str1,str2);
  strcpy(str2,tem);
}
