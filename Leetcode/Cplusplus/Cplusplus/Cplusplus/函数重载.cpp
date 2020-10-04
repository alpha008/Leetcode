#include<iostream>
using namespace std;
#if 0
// 函数重载 函数名字相同，函数参数类型不同或者个数或者顺序不同
// 挺高代码的复用性
void func(int a, int b, int  c)
{
	cout << "func:a+b+c" << endl;
}
void func(int a,int b)
{
	cout <<"func:a+b" << endl;
}
//1.引用作为函数重载条件
void funcd(int& a )  //可读可写的引用
{
	cout << "funcd：int& a " << endl;
}
void funcd(const int& a)// 限制只读
{
	cout << "funcd：const int& a " << endl;
}
//2.函数重载碰到函数重载  函数默认参数不参与函数重载
void funce(int a, int b = 100)
{
	cout << "funce： " << endl;
}
void funce(int a)
{
	cout << "funce： " << endl;
}
void  main()
{
	//funce(10);
	func(1,2,3);
	func(1,2);
	int a = 10;
	//int &c = 10;//引用必须引用一个合法的地址，堆或栈 10在常量区
	//cont int &c = 10;//会存在中间变量
	const int b = 100;
	funcd(a);
	funcd(b);
	system("pause");
}
#endif