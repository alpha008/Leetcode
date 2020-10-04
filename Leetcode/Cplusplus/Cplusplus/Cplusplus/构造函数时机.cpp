#include<iostream>
using namespace std;
#if 0
//默认构造函数   无参数
//析构函数       
//拷贝构造函数   指拷贝
class Person
{
public:
	Person(){                               //无参构造函数
		cout << "无参数构造函数 " << endl;
	}
	Person(int age){                       // 有参构造函数
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
		cout << " =构造函数 " << endl;
	}
	int age;
};
void test01()
{
	Person p;
	p.age = 100;
	Person p2(p);
	cout << "p2的年龄：" << p2.age << endl;
}
void main()
{
	test01();
	system("pause");
}
#endif