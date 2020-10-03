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
//map也是基于红黑树排序的  也是根据key排序
//key 如果是自定义结构，需要指定排序规则
class Person{
public:
	Person(string name, int age) :name(name), age(age){}
	string name;
	int age;
};
class mycompare{// 查找时，仅仅会根据age排序
public:
	bool operator()(const Person& v1, const Person& v2){
		return v1.age > v2.age;
	}
};
void printMap(map<int, string> &map1)
{
	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); it++){
		cout << (it)->first << "  " << it->second << endl;
	}
	cout << endl;
}
void test01()
{
	map<int, string>map1;
	pair<int, string>p1(10,"alpha");
	map1.insert(p1);
	map1.insert(make_pair(20,"spider"));
	map1.insert(map<int,string>::value_type(30,"beta"));
	map1[40] = "gama";// 支持随机访问 

	printMap(map1);
	pair<map<int, string>::iterator, bool> ret1 = map1.insert(make_pair(50, "spider"));
	map1[40] = "aaaa"; //不存在则插入，存在就覆盖
	if (ret1.second){
		cout << "insert sucess" << endl;
	}
	else{
		cout << "insert failed" << endl;
	}
	printMap(map1);



}
void main()
{
	test01();
	system("pause");
}
#endif