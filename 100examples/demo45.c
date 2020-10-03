/*
45.使用register定义变量

题目：学习使用register定义变量的方法。

程序分析：无。
*/

#include <stdio.h>

int main()
{
  register int i;
  int tmp=0;

  for(i=1;i<=100;i++)
    tmp+=i;

  printf("总和为 %d\n",tmp);

  return 0;
}
