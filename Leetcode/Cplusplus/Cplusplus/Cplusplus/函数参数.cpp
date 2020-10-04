#include<iostream>
using namespace std;
#if 0
//函数的默认参数
//调用时，不显示使用就使用默认 函数开始位置后面都必须加上默认参数
int  func(int a,int b,int c = 10)
{
	return a + b + c;
}
//如果函数的声明有了默认参数，那么实现就不能有默认参数了
int funcd(int a, int b, int c = 100);
int funcd(int a,int b)
{
	return 0;
}
void main()
{
	cout << "func:" << func(1, 2) << endl;  // 传少了，会有默认的
	cout << "func:" << func(1,2,3) << endl;

	system("pause");
}
#endif