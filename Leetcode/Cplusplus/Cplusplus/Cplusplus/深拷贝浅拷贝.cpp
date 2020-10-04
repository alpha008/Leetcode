#include<iostream>
using namespace std;

#if 0
class  Person{
public:
	Person()
	{	
		cout << "默认构造函数" << endl;
	}
	Person(int age,int H)
	{
		this->age = age;
		this->m_Height = new int(H);
		cout << "有参构造函数" << endl;
	}
	Person(const Person &other)
	{
		this->age = other.age;
		this->m_Height = new int(*other.m_Height);
		cout << "拷贝构造函数" << endl;
	}
	~Person()
	{
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "析构函数" << endl;
	}
	int age;
	int *m_Height;// 浅拷贝  堆上的内存被重复释放
};

void test01()
{
	Person p1(18,160);

	cout << "p1的年龄:" << p1.age<< endl;
	cout << "p1的年龄:" << *p1.m_Height << endl;
	Person p2(p1);
	cout << "p2的年龄:" << p2.age << endl;
	cout << "p2的年龄:" << *p2.m_Height << endl;

}

void  main()
{
	test01();
	system("pause");
}
#endif