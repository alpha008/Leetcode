#include<iostream>
#include<string>
using namespace std;
#if 0
// this指针  隐含在每一个成员函数内
// 解决名字冲突，返回类对象本身
class Person
{
public:
	Person(int  age) {
		this->m_age = age;
	}
	Person& PersonAddAge(const Person&other)
	{	
		this->m_age = other.m_age + this->m_age;
		return *this;
	}
	int  m_age;
  
};
void test()
{
	Person p1(10);                // this指针指向调用的成员函数所属的对象
	cout << "p1.m_age = " << p1.m_age << endl;
	Person p2(100);  //this指针指向的是调用该成员函数的对象 链式编程方法
	p2.PersonAddAge(p1).PersonAddAge(p1);
	cout << "p2的年龄为:" << p2.m_age << endl;
}
void main()
{
	test();
	system("pause");
}
#endif