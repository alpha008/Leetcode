/*
10.打印楼梯，同时在楼梯上方打印两个笑脸

题目：打印楼梯，同时在楼梯上方打印两个笑脸。

程序分析：Linux下用11来表示两个笑脸；用i控制行，j来控制列，j根据i的变化来控制输出黑方格的个数。
*/

#include<stdio.h>
 
int main()
{
  int i,j;

  printf("11\n"); /*输出11来表示两个笑脸*/

  for(i=1;i<11;i++)
  {
    for(j=1;j<=i;j++)
      printf("%c%c",70,70);
    printf("\n");
  }
  return 0;
}

