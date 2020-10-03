/*
73.反向输出一个链表

题目：反向输出一个链表。　

程序分析：无。
*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct LNode
{
  int      data;
  struct LNode *next;
}LNode,*LinkList;
 
LinkList CreateList(int n);
void print(LinkList h);

int main()
{
  LinkList Head=NULL;
  int n;
  printf("输入数据个数:\n"); 
  scanf("%d",&n);
  Head=CreateList(n);
  
  printf("反向输出的链表为：\n");
  print(Head);
  
  printf("\n\n");
  system("pause");
  return 0;
}

LinkList CreateList(int n)
{
  LinkList L,p,q;
  int i;
  p=malloc(sizeof(LNode));
  if(!p)return 0;
  p->next=NULL;
  q=p;

  for(i=1;i<=n;i++)
  {
    //p=(LinkList)malloc(sizeof(LNode));
    printf("请输入第%d个元素的值:",i);
    scanf("%d",&(q->data));
    L=malloc(sizeof(LNode));
    L->next=q;
    q=L;
    //L->next=NULL;
    //q->next=p;
    //q=p;
  }
  return L;
}

void print(LinkList h)
{
  LinkList p=h->next;
  while(p!=NULL)
  {
    printf("%d ",p->data);
    p=p->next;
  }
}
