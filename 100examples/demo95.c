/*
95.结构体应用实例

题目：简单的结构体应用实例。

程序分析：无。
*/

#include <stdio.h>

struct programming
{
  float constant;
  char *pointer;
};

int main()
{
  struct programming variable;
  char string[] = "C语言技术网：www.freecplus.net";
  
  variable.constant = 1.23;
  variable.pointer = string;
  
  printf("%f\n", variable.constant);
  printf("%s\n", variable.pointer);
  
  return 0;
}
