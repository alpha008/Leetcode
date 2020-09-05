#include<iostream>
#include<vector>
using namespace std;
struct Node
{
    /* data */
    int data;
    struct Node*next;
};
/*********************************************************************************************************
1. 判断单链表是否存在环
题目描述：输入一个单向链表，判断链表是否有环。
分析：通过两个指针，分别从链表的头节点出发，
一个每次向后移动一步，另一个移动两步，两个指针移动速度不一样，如果存在环，那么两个指针一定会在环里相遇。
**********************************************************************************************************/
bool LinkListishaveCircle(Node *head)
 {
     Node *slow,*fast;	//定义两个指针(就是我们所说的快慢指针了)
     slow = fast = head;	//让他们已开始都指向头结点
     while(fast != NULL &&  fast->next != NULL)	
     {	/*fast->next!= NULL 保证了 即使fast每次走两步当他距离最后一个节点还有一步时还能再走两步,(第一步走到最后一个结点第二步走到最后节点
         的指针域为NULL,这样就能出循环了)*/
         fast = fast->next->next;	//快指针走两步
         slow = slow->next;	//慢指针走一步
         if(fast == slow)	//当他们只想的结点相等时,就能说明存在环
         {
             return true;	//返回true 代表存在环!!!
         }
     }
     return false;
 }
/*********************************************************************************************************
2. 找到环的入口点
题目描述：输入一个单向链表，判断链表是否有环。如果链表存在环，如何找到环的入口点？
解题思路：由上题可知，按照 p2 每次两步，p1 每次一步的方式走，发现 p2 和p1 重合，确定了单向链表有环路了。
接下来，让p2回到链表的头部，重新走，每次步长不是走2了，而是走1，那么当 p1 和 p2 再次相遇的时候，就是环路的入口了。。
**********************************************************************************************************/
Node* findLoopPort(Node *head)
 {
     //如果head为空，或者为单结点，则不存在环
      if(head == NULL || head->next == NULL) return NULL;
     Node *slow,*fast;
     slow = fast = head;
     //先判断是否存在环(上一个部分就不再给出解释了!!!!)
     while(fast != NULL &&  fast->next != NULL)
     {
         fast = fast->next->next;
         slow = slow->next;
         if(fast == slow)
             break;
     }
     if(fast != slow)  return NULL;    //不存在环直接返回
 	//现在是存在环的情况!!!
     fast = head;                //快指针从头开始走
     while(fast !=  slow)            //两者相遇即为入口点
     {
         fast = fast->next;	//快指针现在步长变为1
         slow = slow->next;	//慢指针还是继续行走
     }
     return fast;	//这个点就是入口点其实返回 slow 效果也是一样的
 }




