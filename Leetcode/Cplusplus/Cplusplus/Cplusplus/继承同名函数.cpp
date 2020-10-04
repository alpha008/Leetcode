#include<iostream>
#include<string>
#if 0
using namespace std;
class Base{
public:
	Base(){
		m_a = 200;
	}
	void func(){
		cout << "Base:func" << endl;
	}
	static void fund(){
		cout << "Base:fund" << endl;
	}
	int m_a;
};
class Derived :public Base{
public:
	Derived(){
		m_a = 100;
	}
	void func(){
		cout << "Derived:func" << endl;
	}
	static void fund(){
		cout << "Derived:fund" << endl;
	}
	int m_a;
};
void main()
{
	Derived d; // 子类对象会去子类中去寻址，然后获取其值
	cout << " Base : m_a " << d.Base::m_a << endl;
	cout << " Derived : m_a " << d.m_a << endl;
	d.func();
	d.Base::func();   // 出现同名的，this指针谁调用，就指向谁
	// 子类会覆盖掉父类的同名成员函数，需要加作用域才能访问
	d.Base::fund();
	d.fund();

	system("pause");
}
#endif




