/**************************************************************************************************

 *************************************************************************************************/


/**********************************************************************************************************
You are given two linked lists representing two non-negative numbers. e digits are stored in reverse
order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8 
**********************************************************************************************************/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};

class Solution{
public:
    ListNode *addTwoNumbers(ListNode *l1,ListNode *l2){
        ListNode head(-1);
        int carry = 0;
        ListNode *prev = &head;
        for(ListNode *pa = l1, *pb = l2;
            pa != nullptr || pb != nullptr;
            pa = pa == nullptr ? nullptr : pa->next,
            pb = pb == nullptr ? nullptr : pb->next,
            prev = prev->next){
            const int ai = pa == nullptr ? 0 : pa-val;
            const int bi = pb == nullptr ? 0 : pb->val;
            const int value = (ai + bi + carry) % 10;
            carry = (ai + bi + carry) / 10;
            prev->next = new ListNode(value);
        }
        if(carry > 0)
            prev->next = new ListNode(carry);
        return head.next;
    }
};

/**********************************************************************************************************
Merge two sorted linked lists and return it as a new list. e new list should be made by splicing
together the nodes of the first two lists.
**********************************************************************************************************/

class Solution{
public:
    ListNode *mergeTwoLists(ListNode*l1 , ListNode *l2){
        ListNode head(-1);
        for(ListNode * p = &head;l1 != nullptr || l2 != nullptr;p = p->next){
            int val1 = l1 == nullptr ? INT_MAX : l1->val;
            int val2 = l2 == nullptr ? INT_MAX : l2->val;
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
};

6.3 Merge k Sorted Lists


class Solution{
public:
    ListNode *mergeTwoLists(ListNode*l1 , ListNode *l2){
        ListNode head(-1);
        for(ListNode * p = &head;l1 != nullptr || l2 != nullptr;p = p->next){
            int val1 = l1 == nullptr ? INT_MAX : l1->val;
            int val2 = l2 == nullptr ? INT_MAX : l2->val;
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

   ListNode *mergeKlists(vector<ListNode *>&Lists){
        if(Lists.size() == 0 ) return nullptr;
        ListNode * p = Lists[0];
        for(int i = 0;i < Lists.size(); i++){
            p = mergeTwoLists(p, Lists[i]);
        }
   }
};



