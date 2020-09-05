#include<iostream>
#include<queue>
using namespace std;
#if 0
声明，queue<变量类型> 变量名。
入队，q.push(x); 将x接到队列的末端。
出队，q.pop(); 弹出队列的第一个元素，不会返回被弹出元素的值。
访问队首元素，q.front()，即最早被压入队列的元素。
访问队尾元素，q.back()，即最后被压入队列的元素。
判断队列空，q.empty()，当队列空时，返回true。
获得元素个数，q.size()。
#endif
#include <iostream>
#include <queue>
using namespace std;
int testQueue04()
{
	//声明
	queue<int> q;
	//元素入队
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	//获得队列大小
	cout << q.size() << endl;
	//队列是否为空
	cout << q.empty() << endl;
	//访问队首
	cout << q.front() << endl;
	//访问队尾
	cout << q.back() << endl;
	//弹出当前队首元素
	q.pop();
	return 0;
}
