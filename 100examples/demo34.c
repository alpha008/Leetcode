/*
34.练习函数调用

题目：练习函数调用。

程序分析：无。
*/

#include <stdio.h>

void hello_world(void)
{
  printf("Hello, world!\n");
}

void three_hellos(void)
{
  int counter;
  for (counter = 1; counter <= 3; counter++)
    hello_world();/*调用此函数*/
}

int main(void)
{
  /*调用此函数*/
  three_hellos();
}
