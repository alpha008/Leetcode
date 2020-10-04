#include<iostream>
using namespace std;
// 传值   传址  传引用
// 引用在定义时，必须初始化，且后续不可更改
void function1()
{
	int a = 10;
	int &b = a; // int * const b = &a;  b指针的指向不可更改
	b = 20;
	int &c = b;
	cout << " b = " << b << endl;
	cout << " a = " << a << endl;
	cout << " c = " << c << endl;
}
void main001()
{
	function1();
	
	system("pause");
}