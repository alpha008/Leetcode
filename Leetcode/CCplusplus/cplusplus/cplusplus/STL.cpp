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
using namespace std;
#if 0
// 算法      容器    迭代器   数据结构算法分离
// 高可用    高性能  跨平台   容器可以嵌套容器
// 序列容器  关联容器    迭代器(遍历元素)    算法(通过有限步骤结局具体问题)
//  增加  删除  修改   查找   替换
int countNum(int *start,int *end,int val)
{
	int num = 0;
	while (start != end)
	{
		if (*start == val)
		{
			num++;
		}
		start++;
	}
	return num;
}
void test01()
{
	int arry[10] = { 1, 2, 3, 4, 5, 6, 7 };
	int *begin = arry;
	int *end = &(arry[sizeof(arry) / sizeof(int)]);
	cout << countNum(begin, end, 3) << endl;
}
void printV(int v)
{
	cout << v << " " ;
}
// 容器算法迭代器
void test02()
{// 向尾部添加元素，当超过其容量时，进行动态扩容
	vector<int> vector1;
	vector1.push_back(10);
	vector1.push_back(20);
	vector<int>::iterator pBegin = vector1.begin();
	vector<int>::iterator pEnd = vector1.end();
	for_each(pBegin, pEnd, printV);
}
class Person{
public:
	Person(int age, int id) :age(age), id(id){}
	int age;
	int id;
};
void test03(){
	vector<Person>vector1;
	Person p1(10, 20);
	Person p2(10, 30);
	Person p3(10, 40);
	vector1.push_back(p1);
	vector1.push_back(p2);
	vector1.push_back(p3);
	for (vector<Person>::iterator it = vector1.begin(); it != vector1.end(); it++){
		cout << "(*it).age: " << (*it).age << " (*it).id " << (*it).id << endl;
	}
}
void main(){	
	//test02();
	test03();
	system("pause");
}
#endif
