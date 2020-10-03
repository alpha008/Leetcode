/*
87.结构体变量传递

题目：回答结果（结构体变量传递）。

程序分析：无。
*/

#include<stdio.h>
 
struct student
{
  int x;
  char c;
} a;
 
int main()
{
  a.x=3;
  a.c='a';
  f(a);
  printf("%d,%c\n",a.x,a.c);
}

f(struct student b)
{
  b.x=20;
  b.c='y';
}
