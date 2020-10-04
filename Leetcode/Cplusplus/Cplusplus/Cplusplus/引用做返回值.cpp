#include<iostream>
using namespace std;
#if 0
//不要返回局部变量的引用
//返回类型为引用可以作为左值
int &function_ref()
{
	static int a = 10; //静态变量 全局区
	return a;          // 使用的别名，访问该地址
}

void main()
{
	int & ref = function_ref() ;
	cout << "ref = " << ref <<  endl;
	function_ref() = 1000;
	cout << "ref = " << ref <<  endl;

	system("pause");
}
#elif 0
void showref(/*const*/ int &value)
{
	value = 100;
	cout << "value = " << value << endl;
}
void main()
{
	int a = 10;
	const int & ref = 10;//int temp 10. const int &ref  = temp;
	cout << "a = " << a << endl;
	showref(a);
	system("pause");
}
#endif