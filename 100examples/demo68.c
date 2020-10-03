/*
68.自定义数字移位

题目：有 n个整数，使其前面各数顺序向后移 m 个位置，最后m个数变成最前面的 m 个数。

程序分析：无。
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int arr[20];
  int i,n,offset;

  //输入数组大小和数组内容
  printf("一共有几个数?\n");
  scanf("%d",&n);
  printf("请输入数字\n",n);

  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

  //输入滚动偏移量
  printf("请设置偏移量\n");
  scanf("%d",&offset);
  printf("偏移量是 %d.\n",offset);

  //打印滚动前数组
  print_arr(arr,n);
  //滚动数组并打印
  move(arr,n,offset);
  print_arr(arr,n);
}
 
//打印数组
void print_arr(int array[],int n)
{
  int i;
  for(i=0;i<n;++i)
    printf("%4d",array[i]);
  printf("\n");
}

//滚动数组
void move(int array[],int n,int offset)
{
  int *p,*arr_end;
  arr_end=array+n;    //数组最后一个元素的下一个位置
  int last;
  
  //滚动直到偏移量为0
  while(offset)
  {
    last=*(arr_end-1);
    for(p=arr_end-1;p!=array;--p)   //向右滚动一位
      *p=*(p-1);
    *array=last;
    --offset;
  }
}
