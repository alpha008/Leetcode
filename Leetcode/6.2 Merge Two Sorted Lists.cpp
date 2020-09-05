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



