#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode,*LinkList;

LinkList CreateList(int n);

void print(LinkList h);

void main()
{
  LinkList Head=NULL,Head2=NULL,f=NULL;
  int n,m;

  printf("请输入第一个链表数据个数:\n");
  scanf("%d",&n);
  Head=CreateList(n);
  printf("请输入第二个链表数据个数:\n");
  scanf("%d",&m);

  Head2=CreateList(m);
  f=Head;
  while(f->next!=NULL)
    f=f->next;
  f->next=Head2->next;

  printf("连接后的链表为:\n");
  print(Head);
  printf("\n");
}

LinkList CreateList(int n)
{
  LinkList L,p,q;
  int i;

  L=malloc(sizeof(LNode));
  if(!L)return 0;
  L->next=NULL;
  q=L;

  for(i=1;i<=n;i++)
  {
    p=malloc(sizeof(LNode));
    printf("请输入第%d个数据:\n",i);
    scanf("%d",&(p->data));
    p->next=NULL;
    q->next=p;
    q=p;
  }
  return L;
}

void print(LinkList h)
{
  LinkList p=h->next;

  while(p!=NULL)
  {
    printf("%d",p->data);
    p=p->next;
  }
}


