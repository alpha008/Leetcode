#include<iostream>
using namespace std;
#if 0
int g_a = 10;
int g_b = 100;
const int c_g_a = 10;
const int c_g_b = 10;
void  main01()
{
	// 全局区
	// 全局变量、静态变量、常量

	// 创建普通局部变量
	int a = 10;
	int b = 100;
	static int s_a = 10;
	static int s_b = 100;
	// 常量        字符串常量      const修饰的全局常量
	cout << "字符串的地址：" << &("string1") << endl;

	cout << "全局变量 g_a = " << &g_a << endl;
	cout << "全局变量 g_b = " << &g_b << endl;
	cout << "局部变量 a = " << &a << endl;
	cout << "局部变量 b = " << &b << endl;
	cout << "静态变量 s_a = " << &s_a << endl;
	cout << "静态变量 s_b = " << &s_b << endl;

	cout << "静态变量 c_g_a = " << &c_g_a << endl;
	cout << "静态变量 c_g_b = " << &c_g_b << endl;
	system("pause");
}
#elif 0
//不要反回栈上的地址
int *function() // 形参也是在栈上开辟空间
{
	int a = 10;
	return &a;
}
void main()
{
	//栈区，不要返回局部变量的地址
	int * p = function();
	cout << "p = " << *p << endl;
	cout << "p = " << *p << endl;
	system("pause");
}
#elif 0
int *function()
{
	int *p = new int(10);   //匿名整数类

	delete p;
	return p;
}
void main()
{
	int * p = function();
	cout << "p = " << *p << endl;
	cout << "p = " << *p << endl;

	system("pause");
}

#endif