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

int main()
{
	cout << "sizeof(ListNode) = " << sizeof(ListNode) << endl;
	return 0;

}