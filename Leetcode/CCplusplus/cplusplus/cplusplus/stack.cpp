#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<stack>
#if 0
using namespace std;
void test()
{
	stack<int> stack1;
	stack1.push(100);
	stack1.push(200);
	cout << "stack1.size()= " << stack1.size()<<endl;
	while (!stack1.empty()){
		int val = stack1.top();
		cout << " val  = " << val << endl;
		stack1.pop();
	}
}
//栈不支持遍历，不提供迭代器，不支持随机存取
void main()
{
	test();
	system("pause");
}
#endif