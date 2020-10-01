#include<iostream>
using namespace std;

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
int calBitPc()
{
    int num = 0;
    int a = 0;
    printf("a = %d\n",a);
    #if 0
    if(a = )
    {
        printf("computer is %d\n",a);
    }
    #endif
    return num;
}
int main()
{
    calBitPc();
    cout << "sizeof(ListNode) = " << sizeof(ListNode) << endl;
    return 0;
}