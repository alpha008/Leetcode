#include<iostream>
using namespace std;
//赋值运算符
#if 0
class Person
{
public:
	Person(int age)
	{
		p_age = new int(age);
	}
	~Person(){
		if (p_age!=NULL)
		{
			delete p_age;
			p_age = NULL;
		}
	}
	//感觉和memcpy很像
	Person& operator = (Person&p){
		// 先判断自己的堆上是否有数据，如果有那么先释放干净
		if (p_age != NULL)
		{
			delete p_age;
			p_age = NULL;
		}
		p_age = new int(*p.p_age);//解引用原来的
		return *this;
	}
	int *p_age;// 堆区域
};
void test01()
{
	Person p1(18);
	Person p2(20);
	Person p3(19);
	p3 = p1 = p2; // 返回引用才能连续操作
	cout << "年龄为:" << *p1.p_age << endl;
	cout << "年龄为:" << *p2.p_age << endl;
	cout << "年龄为:" << *p3.p_age << endl;
}
void main()
{
	test01();

	system("pause");
}
#endif