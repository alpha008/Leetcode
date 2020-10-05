#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<limits>
#include<stack>
using namespace std;
/**************************************************************************************************
1. 两个链表求和
2. 合并链表并返回头指针
3. 求单链表中结点的个数
4. 将单链表反转
5. 查找单链表中的倒数第K个结点
6. 查找单链表的中间结点
7. 从尾到头打印单链表
8. 判断单链表是否存在环
9. 找到环的入口点
10. 判断两个单链表是否相交
11. 求两个单链表相交的第一个节点
12. 合并k个有序链表，并返回头指针
 *************************************************************************************************/
class ListNode {
public:
    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }
    int val;
    ListNode *next;
};
/**********************************************************************************************************
1.两个链表求和
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8 
**********************************************************************************************************/
ListNode *addTwoNumbers(ListNode *l1,ListNode *l2){
    ListNode head(-1);
    int carry = 0;
    int ai = 0;
    int bi = 0;
    int value = 0;
    ListNode *prev = &head;  //头指针不存储数据
    for(ListNode *pa = l1, *pb = l2;
        pa != nullptr || pb != nullptr;  //两者其中一个不为空就执行
        pa = pa == nullptr ? nullptr : pa->next,pb = pb == nullptr ? nullptr : pb->next,prev = prev->next){
        ai = pa == nullptr ? 0 : pa->val; // 判断链表位置是否为 0
        bi = pb == nullptr ? 0 : pb->val;
        value = (ai + bi + carry) % 10;   //当前位置
        carry = (ai + bi + carry) / 10;             //进位
        prev->next = new ListNode(value);
    }
    if(carry > 0)   //判断最后是否存在进位
        prev->next = new ListNode(carry);
    return head.next;
}

/**********************************************************************************************************
2.合并链表并返回头指针
Merge two sorted linked lists and return it as a new list. e new list should be made by splicing
together the nodes of the first two lists.
**********************************************************************************************************/
ListNode *mergeTwoLists(ListNode*l1 , ListNode *l2){
    ListNode head(-1);
    for(ListNode * p = &head;l1 != nullptr || l2 != nullptr;p = p->next){
        int val1 = l1 == nullptr ? INT32_MAX : l1->val; 
        int val2 = l2 == nullptr ? INT32_MAX : l2->val;
        if(val1 <= val2){
            p->next = l1;
            l1 = l1->next;
        }else{
            p->next = l2;
            l2 = l2->next;
        }
    }
    return head.next;
}
/**********************************************************************************************************
3.求单链表中结点的个数
**********************************************************************************************************/
unsigned int GetListLength(ListNode * pHead) 
{ 
    unsigned int nLength = 0; 
    ListNode * pCurrent = pHead; 
    if(pHead == NULL) 
        return 0; 

    while(pCurrent != NULL) 
    { 
        nLength++; 
        pCurrent = pCurrent->next; 
    } 
    return nLength; 
}
/**********************************************************************************************************
4.将单链表反转
  链表反转时，需要前后两个节点来记录节点信息；与删除节点时，非常相似
从头到尾遍历原链表，每遍历一个结点，将其摘下放在新链表的最前端。注意链表为空和只有一个结点的情况。
**********************************************************************************************************/
ListNode * ReverseList(ListNode * pHead) 
{ 
     // 如果链表为空或只有一个结点，无需反转，直接返回原链表头指针 
    if(pHead == NULL || pHead->next == NULL)   
        return pHead; 
    ListNode * pReversedHead = NULL;     // 反转后的新链表头指针，初始为NULL 
    ListNode * pCurrent = pHead; 
    while(pCurrent != NULL) 
    { 
        ListNode * prev = pCurrent; 
        pCurrent = pCurrent->next; 
        prev->next = pReversedHead; // 将当前结点摘下，插入新链表的最前端 
        pReversedHead = prev; 
    } 
    return pReversedHead; 
} 
/**********************************************************************************************************
5.查找单链表中的倒数第K个结点 k > 0
  从头到尾遍历原链表，每遍历一个结点，将其摘下放在新链表的最前端。注意链表为空和只有一个结点的情况。
**********************************************************************************************************/ 
ListNode * RGetKthNode(ListNode * pHead, unsigned int k) // 函数名前面的R代表反向 
{ 
    if(k == 0 || pHead == NULL) // 这里k的计数是从1开始的，若k为0或链表为空返回NULL 
        return NULL; 
  
    ListNode * pAhead = pHead; 
    ListNode * pBehind = pHead; 
    while(k > 1 && pAhead != NULL) //没走完k个就不满足条件了，导致k>1 
    { 
        pAhead = pAhead->next; 
        k--; 
    } 
    if(k > 1 || pAhead == NULL)     // 结点个数小于k，返回NULL 
        return NULL; 
    while(pAhead->next != NULL)  // 前后两个指针一起向前走，直到前面的指针指向最后一个结点 
    { 
        pBehind = pBehind->next; 
        pAhead = pAhead->next; 
    } 
    return pBehind;  // 后面的指针所指结点就是倒数第k个结点 
}
/**********************************************************************************************************
6. 查找单链表的中间结点
   获取单链表中间结点，若链表长度为n(n>0)，则返回第n/2+1个结点 
**********************************************************************************************************/
ListNode * GetMiddleNode(ListNode * pHead) 
{ 
    if(pHead == NULL || pHead->next == NULL) // 链表为空或只有一个结点，返回头指针 
        return pHead; 
  
    ListNode * pAhead = pHead; 
    ListNode * pBehind = pHead; 
    while(pAhead->next != NULL) // 前面指针每次走两步，直到指向最后一个结点，后面指针每次走一步 
    { 
        pAhead = pAhead->next; 
        pBehind = pBehind->next; 
        if(pAhead->next != NULL)  //pAhead 该指针一个循环走连词
            pAhead = pAhead->next; 
    } 
    return pBehind; // 后面的指针所指结点即为中间结点 
}
/**********************************************************************************************************
7.从尾到头打印单链表
对于这种颠倒顺序的问题，我们应该就会想到栈，后进先出。所以，这一题要么自己使用栈，要么让系统使用栈，也就是递归
**********************************************************************************************************/
void RPrintList(ListNode * pHead) 
{ 
    std::stack<ListNode *> s; 
    ListNode * pNode = pHead; 
    while(pNode != NULL) 
    { 
        s.push(pNode); 
        pNode = pNode->next; 
    } 
    while(!s.empty()) 
    { 
        pNode = s.top(); 
        printf("%d\t", pNode->next); 
        s.pop(); 
    } 
}
/**********************************************************************************************************
8. 判断单链表是否存在环
题目描述：输入一个单向链表，判断链表是否有环。
分析：通过两个指针，分别从链表的头节点出发，
一个每次向后移动一步，另一个移动两步，两个指针移动速度不一样，如果存在环，那么两个指针一定会在环里相遇。
**********************************************************************************************************/
bool LinkListishaveCircle(ListNode *head)
 {
     ListNode *slow,*fast;	//定义两个指针(就是我们所说的快慢指针了)
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
9. 找到环的入口点
题目描述：输入一个单向链表，判断链表是否有环。如果链表存在环，如何找到环的入口点？
解题思路：由上题可知，按照 p2 每次两步，p1 每次一步的方式走，发现 p2 和p1 重合，确定了单向链表有环路了。
接下来，让p2回到链表的头部，重新走，每次步长不是走2了，而是走1，那么当 p1 和 p2 再次相遇的时候，就是环路的入口了。。
**********************************************************************************************************/
ListNode* findLoopPort(ListNode *head)
 {
     //如果head为空，或者为单结点，则不存在环
     if(head == NULL || head->next == NULL) return NULL;
     ListNode *slow,*fast;
     slow = fast = head;
     //先判断是否存在环
     while(fast != NULL &&  fast->next != NULL)
     {
         fast = fast->next->next;
         slow = slow->next;
         if(fast == slow)
             break;
     }
     if(fast != slow)  
        return NULL;    //不存在环直接返回
     fast = head;                //快指针从头开始走
     while(fast !=  slow)            //两者相遇即为入口点
     {
         fast = fast->next;	//快指针现在步长变为1
         slow = slow->next;	//慢指针还是继续行走
     }
     return fast;	//这个点就是入口点其实返回 slow 效果也是一样的
 }
 /*********************************************************************************************************
10. 判断两个单链表是否相交
如果两个链表相交于某一节点，那么在这个相交节点之后的所有节点都是两个链表所共有的。也就是说，
如果两个链表相交，那么最后一个节点肯定是共有的。先遍历第一个链表，记住最后一个节点，然后遍历第二个链表，
到最后一个节点时和第一个链表的最后一个节点做比较，如果相同，则相交，否则不相交。
时间复杂度为O(len1+len2)，因为只需要一个额外指针保存最后一个节点地址，空间复杂度为O(1)。
**********************************************************************************************************/
bool IsIntersected(ListNode * pHead1, ListNode * pHead2) 
{ // 判断两个尾指针是否相等
    if(pHead1 == NULL || pHead2 == NULL) 
          return false; 
    ListNode * pTail1 = pHead1; 
    while(pTail1->next != NULL) 
        pTail1 = pTail1->next; 
    ListNode * pTail2 = pHead2; 
    while(pTail2->next != NULL) 
        pTail2 = pTail2->next; 
    return pTail1 == pTail2; 
} 
 /*********************************************************************************************************
11.求两个单链表相交的第一个节点
对第一个链表遍历，计算长度len1，同时保存最后一个节点的地址。
对第二个链表遍历，计算长度len2，同时检查最后一个节点是否和第一个链表的最后一个节点相同，若不相同，不相交，结束。
两个链表均从头节点开始，假设len1大于len2，那么将第一个链表先遍历len1-len2个节点，
此时两个链表当前节点到第一个相交节点的距离就相等了，然后一起向后遍历，直到两个节点的地址相同。
**********************************************************************************************************/
ListNode* GetFirstCommonNode(ListNode * pHead1, ListNode * pHead2) 
{ 
    if(pHead1 == NULL || pHead2 == NULL) 
        return NULL; 
    int len1 = 1; 
    ListNode * pTail1 = pHead1; 
    while(pTail1->next != NULL) 
    { 
        pTail1 = pTail1->next; 
        len1++; 
    } 
    int len2 = 1; 
    ListNode * pTail2 = pHead2; 
    while(pTail2->next != NULL) 
    { 
        pTail2 = pTail2->next; 
        len2++; 
    } 
  
    if(pTail1 != pTail2) // 不相交直接返回NULL 
        return NULL; 
  
    ListNode * pNode1 = pHead1; 
    ListNode * pNode2 = pHead2; 
        // 先对齐两个链表的当前结点，使之到尾节点的距离相等 
    if(len1 > len2) 
    { 
        int k = len1 - len2; 
        while(k--) 
            pNode1 = pNode1->next; 
    } 
    else 
    { 
        int k = len2 - len1; 
        while(k--) 
            pNode2 = pNode2->next; 
    } 
    while(pNode1 != pNode2)  // 两个指针处于同级别的起始位置，然后在同时往下面走，这时就可以了
    { 
        pNode1 = pNode1->next; 
        pNode2 = pNode2->next; 
    } 
    return pNode1; 
}
/**********************************************************************************************************
12.合并k个有序链表，并返回头指针
**********************************************************************************************************/
class MergeTwoLists{
public:
    ListNode *mergeTwoLists(ListNode*l1 , ListNode *l2){
        ListNode head(-1);
        for(ListNode * p = &head;l1 != nullptr || l2 != nullptr;p = p->next){
            int val1 = l1 == nullptr ? INT32_MAX : l1->val;
            int val2 = l2 == nullptr ? INT32_MAX : l2->val;
            if(val1 <= val2){    //较小的链表存储起来，然后指向这个元素
                p->next = l1; 
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
        }
        return head.next;
    }

   ListNode *mergeKlists(vector<ListNode *>&Lists){
        if(Lists.size() == 0 ) 
            return nullptr;
        ListNode * p = Lists[0];
        for(int i = 1;i < Lists.size(); i++){
            p = mergeTwoLists(p, Lists[i]);
        }
   }
};
//13.两个链表求和
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(-1);
        if(l1 == NULL || l2 == NULL)
            return NULL;
        int carry = 0;
        
        ListNode *prev = &head;
        for(ListNode *p1=l1,*p2=l2 ; p1!=NULL||p2!=NULL;
            p1 = p1->next!=NULL ? p1->next :NULL ,p2 = p2->next!=NULL ? p2->next: NULL,
           prev=prev->next)
        {
            int ai =  p1 == NULL ? 0: p1->val;
            int bi =  p2 == NULL ? 0: p2->val;
            int val = (ai + bi + carry) %10;
            carry = (ai + bi + carry) /10;
            prev->next = new ListNode(val);
        }
        if(carry > 0)
            prev->next = new ListNode(carry);
        return head.next;
    }
};
//14. 删除倒数第k个结点
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy;
        ListNode *q = &dummy;
        for(int i =0; i< n;i++)
        {
            q = q->next;
        }
        while(q->next)
        {
            p = p->next;
            q = q->next;
        }
        ListNode *temp = p->next;
        p->next = p->next->next;
        delete temp ;
        return dummy.next;
    }
};

//15合并两个有序链表
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode  head(-1);
        for(ListNode *p = &head ;l1!=NULL || l2!=NULL;p = p->next)    
        {        
            int val1 = l1 == NULL ? INT32_MAX : l1->val;// 当出现某个链表中为INT32_MAX，那么说明另外一个链表中的节点比较小
            int val2 = l2 == NULL ? INT32_MAX : l2->val;
            if(val1 <= val2)
            {
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
        }
        return head.next;
    }
};
//16.删除链表中重复结点
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        for(ListNode *p = head; p!=NULL && p->next!=NULL; p = p->next){
            if(p->val == p->next->val){
                   ListNode * temp ;
                   temp = p->next;
                   p->next = p->next->next;
                   delete temp;                   
            }
        }
        return head;
    }
};

//17. 删除链表中重复结点，不允许重复
// 删除节点时，当前cur设置了标记位，当删除重复的节点后，还要判断该结点是否为空
// 然后继续遍历
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode dummy(-1);
        ListNode * cur = head,*prev = &dummy;
        while(cur!=NULL){
            bool duplicated = false;
            while(cur->next !=NULL && cur->next->val == cur->val){
                duplicated = true;
                ListNode *temp = cur;
                cur = cur->next;
                delete temp;
            }
            if(duplicated){
                ListNode*temp = cur;
                cur = cur->next;
                delete temp;
                continue;
            }
            prev->next = cur;
            prev = prev->next;
            cur = cur->next;    
        }
        prev->next = cur;
        return dummy.next;
    }
};
//18. 147. Insertion Sort List  //插入法排序将链表排序
//  1 --- 0 --- 0 --- 0 --- 0
// prev  head   cur
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *newhead = new ListNode(-1);
        while(head != NULL){
            ListNode *cur = head->next; // cur开始移动
            ListNode *pre = newhead;//每次都从头开始
            while(pre->next != NULL &&pre->next->val < head->val){
                pre = pre->next; //找到第一个比未排序的大的点
            }
            head->next = pre->next;
            pre->next = head;
            head = cur;
        }
        return newhead->next;
    }
};
//141. Linked List Cycle  判断链表是否有环
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast !=NULL && fast->next!=NULL){
            slow =slow->next;
            fast = fast->next;
            if(fast == slow){
                return true;
            }else{
                return false;
            }
        }
        return false;
    }

};
//142. Linked List Cycle II
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next ==NULL ) return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                break;
            }
        }
        if(fast!=slow) return NULL;
        fast = head;
        while(slow!=fast){
            slow  = slow->next;
            fast  =fast->next;
        }
        return fast;
    }
};
//160. Intersection of Two Linked Lists 求两个链表相交的点
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       if(headA == NULL || headB == NULL) return NULL;
       int k1 = 1;
       int k2 = 1;
        ListNode *l1 = headA;
        ListNode *l2 = headB;
        while(l1){
            l1 = l1->next;
            k1++;
        }
        while(l2){
            l2 = l2->next;
            k2++;
        }
        if(l1 != l2){
            return NULL;
        }
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        if(k1 > k2){
            int n = k1-k2;
            while(n --)
                p1= p1->next;
        }else{
            int n = k2-k1;
            while(n--)
                p2 = p2->next;
        }
        while(p1!=p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
//445. Add Two Numbers II
// 头插法
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode *res = new ListNode(0);
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {sum += s1.top(); s1.pop();}
            if (!s2.empty()) {sum += s2.top(); s2.pop();}
            res->val = sum % 10;
            ListNode *head = new ListNode(sum / 10);
            head->next = res;
            res = head;
            sum /= 10;//消除上一次的进位
        }
        return res->val == 0 ? res->next : res;
    }
};
//203. Remove Linked List Elements
//删除链表中某一元素
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr)return head;
        ListNode* p=new ListNode(0);
        p->next=head;
        ListNode* cur=p;
        while(cur&&cur->next){
            if(cur->next->val==val){
                cur->next=cur->next->next;
            }
            else{
                cur=cur->next;
            }
        }
        return p->next;
    }
};
//24. Swap Nodes in Pairs
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        while (pre->next && pre->next->next) {
            ListNode *t = pre->next->next;
            pre->next->next = t->next;
            t->next = pre->next;
            pre->next = t;
            pre = t->next;
        }
        return dummy->next;
    }
};

/*************************************************************************************************
 根据数组创建链表，头结点的数据域一般不使用
 *************************************************************************************************/
void createlist(ListNode *phead,vector<int> nums)
{
    ListNode *ptemp = phead; //指向头结点
    ptemp->val = nums[0]; //头结点是否存储数据
    for(int i = 1; i < nums.size();i++){
        ListNode *pnewNode = new ListNode(-1);
        pnewNode->val = nums[i];
        ptemp->next = pnewNode;
        pnewNode->next = nullptr;
        ptemp = pnewNode;
    }
}
/*************************************************************************************************
添加节点，添加到尾部，需要遍历链表
 *************************************************************************************************/
void addNode(ListNode *phead,int value)
{
    ListNode * ptmp = phead;
    ListNode *pNewNode = new ListNode(value);
    if(phead == NULL)
        phead = pNewNode;
    else
    {
        while(ptmp->next != NULL) {
            ptmp = ptmp->next;
        }
        ptmp->next = pNewNode;
    }
}
/*************************************************************************************************
删除节点时，需要记录上个节点的信息
 *************************************************************************************************/
void delNode(ListNode *phead,int value)
{
    ListNode * ptmp = phead;
    if(phead == NULL) return ;
    ListNode * prev;
    ListNode * pcur = phead;
    while(pcur->val != value)
    {
        prev = pcur;//记录要删除结点的上一个结点
        pcur = pcur->next ;
    }
    prev -> next = pcur->next; 
}

/*************************************************************************************************
 遍历链表
 *************************************************************************************************/
void printlist(ListNode *phead)
{
    ListNode *ptemp = phead;
    if(phead == nullptr)
        return ;

    while(ptemp)
    {
        cout << "val-> = "<< ptemp->val << "; " ;
        ptemp = ptemp ->next;
    }
    cout << endl;
}
int main()
{
    cout << "sizeof(ListNode)) =  " << sizeof(ListNode) << endl;
    vector<int> numsA = {2,4,3};
    vector<int> numsB = {5,6,4};
    ListNode *phead1 = new ListNode(-1);
    ListNode *phead2 = new ListNode(-1);
    createlist(phead1,numsA);
    createlist(phead2,numsB);
    printlist(phead1);
    printlist(phead2);
    ListNode * addsum = addTwoNumbers(phead1,phead2);
    printlist(addsum);

    return 0;
}

