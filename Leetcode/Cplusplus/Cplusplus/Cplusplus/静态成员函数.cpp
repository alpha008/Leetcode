#include<iostream>
#include<string>
using namespace std;
//对象成员
#if 0
//所有对象共享一个静态成员函数
//静态成员函数只能访问静态成员变量
class Person
{
public:
	static void func()  //无法区分普通成员变量属于哪个具体的对象
	{
		cout << "静态成员函数" << endl;
	}
	static int a ;   //静态成员变量  类内声明  类外定义
private:
	static void fund()  //类外无法访问私有静态成员函数
	{
		cout << "静态成员函数" << endl;
	}
};
int Person::a = 100;
void test01()
{
	Person p1;
	p1.func(); // 通过对象访问
	Person::func();  //通过类名访问
	p1.a = 1000;
}
void  main()
{
	test01();
	system("pause");
}

#endif