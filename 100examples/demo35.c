/*
35.字符串反转

题目：字符串反转，如将字符串 "www.freecplus.net" 反转为 "ten.sulpceerf.www"。

程序分析：无。
*/

#include <stdio.h>
 
void reverse(char* s)
{
  // 获取字符串长度
  int len = 0;
  char* p = s;
  while (*p != 0)
  {
    len++;
    p++;
  }
  
  // 交换 ...
  int i = 0;
  char c;
  while (i <= len / 2 - 1)
  {
    c = *(s + i);
    *(s + i) = *(s + len - 1 - i);
    *(s + len - 1 - i) = c;
    i++;
  }
}
 
int main()
{
  char s[] = "www.freecplus.net";
  printf("'%s' =>\n", s);
  reverse(s);       // 反转字符串
  printf("'%s'\n", s);
  return 0;
}
