#include<iostream>
#include<stack>
using namespace std;
#include <vector>  
#include <deque>  
#include <iostream>  

using namespace std;

int test01()
{
	deque<int> mydeque(2, 100); // 队列  初始化2个100
	vector<int> myvector(2, 200);

	stack<int> first;
	stack<int> second(mydeque);

	stack<int, vector<int> > third; // 指明用vector实现一个栈（存放int），空栈size=0
	stack<int, vector<int> > fourth(myvector);

	cout << "size of first: " << (int)first.size() << endl;
	cout << "size of second: " << (int)second.size() << endl;
	cout << "size of third: " << (int)third.size() << endl;
	cout << "size of fourth: " << (int)fourth.size() << endl;
	return 0;
}
int test02()
{
	stack<int> mystack;
	int sum(0);

	for (int i = 1; i <= 10; i++) 
		mystack.push(i);

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}

	cout << "total: " << sum << endl;

	return 0;
}
int test03()
{
	stack<int> mystack;

	for (int i = 0; i<5; ++i)
		mystack.push(i);

	cout << "Popping out elements...";
	while (!mystack.empty())
	{
		cout << " " << mystack.top();
		mystack.pop();
	}
	cout << endl;

	return 0;
}
int test04()
{
	stack<int> mystack;

	for (int i = 0; i<5; ++i) 
		mystack.push(i);

	cout << "Popping out elements...";
	while (!mystack.empty())
	{
		cout << " " << mystack.top();
		mystack.pop();
	}
	cout << endl;

	return 0;
}
int main03()
{
	test01();
	test02();
	test03();
	test04();
	return 0;
}