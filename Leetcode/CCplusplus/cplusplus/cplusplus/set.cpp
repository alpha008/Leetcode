#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<list>
#include<set>  //元素有序  指定排序规则   mulset支持多个key
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<stack>
#if 0
using namespace std;
//不能通过迭代器修改其值，要改变，先删除然后在插入
void printSet(set<int> &set1)
{
	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
}
void test01()
{
	set<int> set1;//平衡二叉树  RB - tree
	for (int index = 0; index < 20; index++){
		set1.insert(index);//必须保证插入的元素要能排序，否则要自定义排序规则
	}
	printSet(set1);                       //默认从小到大排序
	set<int>::iterator it = set1.find(8);
	set1.erase(10); // 按照element删除.不能按照迭代器删除
	set1.erase(set1.begin());
	cout << "*it = "<<*it << endl;
	cout << "size = " << set1.size() << endl;
	cout << "empty = " << set1.empty()<< endl;
	printSet(set1);// 先序遍历 中序遍历 后序遍历
	//如何改变默认排序
}
void test02()
{
	set<int> s1;//平衡二叉树  RB - tree
	for (int index = 0; index < 20; index++){
		s1.insert(index);//必须保证插入的元素要能排序，否则要自定义排序规则
	}
	printSet(s1);
	set<int>::iterator it = s1.find(10);
	if (s1.end() != it){
		cout << "*s1 = " << *it << endl;
	}
	else{
		cout << "not found" << endl;
	}
	it = s1.lower_bound(2); //返回第一个>=2的值
	cout << "lower_bound = " << *it << endl;
	it = s1.upper_bound(2); //返回第一个>2的值
	cout << "upper_bound = " << *it << endl;
	pair<set<int>::iterator, set<int>::iterator> it1;
	it1 = s1.equal_range(2); //返回第一个>2的值
	if (it1.first == s1.end()){
		cout << "1没找到" << endl;
	}
	else
	{
		cout << "1找到了" << *it1.first << endl;
	}
	if (it1.second == s1.end()){
		cout << "2没找到" << endl;
	}
	else
	{
		cout << "2找到了" << *it1.second << endl;
	}

}

void main()
{
	test02();
	//test01();
	system("pause");
}
#endif