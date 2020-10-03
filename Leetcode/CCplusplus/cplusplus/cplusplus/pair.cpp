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
void printSet1(set<Person, mycompare> set1)
{
	for (set<Person, mycompare>::iterator it = set1.begin(); it != set1.end(); it++){
		cout << (*it).age<< " ";
	}
	cout << endl;
}
void test01()
{
	pair<int, int> pair1(10,20);
	cout << pair1.first << " " << pair1.second << endl;
	pair<string, int>pair2 = make_pair("alpha",100);
	pair<string, int>pair3 = pair2;
}
void main()
{
	set<Person, mycompare> s1;
	set<Person, mycompare>::iterator it = s1.begin();
	Person p1("zhangsan", 100);
	Person p2("lisi",200);
	s1.insert(p1);
	s1.insert(p2);

	printSet1(s1);
	system("pause");
}

#endif