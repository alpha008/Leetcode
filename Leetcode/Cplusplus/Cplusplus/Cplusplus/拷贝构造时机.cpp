#include<iostream>
#include<string>
using namespace std;
#if 0
/********************************************************
1   使用一个已经初始化完成的对象初始化另一个对象
2   值传递方式传给函数参数
3   值方式返回局部对象
*********************************************************/
class Person
{
public:
	Person(){                               //无参构造函数
		cout << "无参数构造函数 " << endl;
	}
	Person( int age){                       // 有参构造函数
		this->age = age;
		cout << "有参构造函数 " << endl;
	}
	~Person()
	{
		cout << "析构造函数 " << endl;
	}
	Person(const Person &other){             //  拷贝构造函数    属性的拷贝 不可改变原内容
		if (this == &other)                  //  防止自身循环拷贝
			return;
		this->age = other.age;
		cout << "拷贝构造函数 " << endl;
	}
	Person& operator=(const Person &other){  //拷贝构造函数
		cout << "=构造函数 " << endl;
	}
	int age;
};
void test01()
{
	Person p1(20); //有参数构造
	Person p2(p1); //拷贝构造
}

void do_work(Person p)   //副本拷贝 临时变量
{
	
}
void test02()
{
	Person p(10);
	do_work(p);       //2. 对象作为参数传递，会拷贝构造
}

Person do_work2()     //副本拷贝
{
	Person p2;
	cout << (int*)&p2 << endl;
	return p2;
}
void test03(){

	Person p3 = do_work2();
	cout << (int*)&p3 << endl;
}

void main()
{
	//test01();
	//test02();
	test03();
	system("pause");
}
#endif









