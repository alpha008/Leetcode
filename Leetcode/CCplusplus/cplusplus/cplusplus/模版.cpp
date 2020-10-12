#include<iostream>
#include<string>
#include<vector>
using namespace std;
#if 0
void MySwap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}
void MySwap(double &a, double &b){
	int temp = a;
	a = b;
	b = temp;
}
#elif 0
//模板技术，类型参数化
//模板不允许类型自动转换  类型参数化
template<class T> //template<typename T>
void MySwap(T &a, T&b)
{ //类型会自动推导
	T temp = a;
	a = b;
	b = temp;
}
//普通函数可以对类型进行自动转换
int Myadd(int a,char b)
{
	return a + b;
}
//参数类型必须严格匹配
template <typename T> 
T Myadd(T a, T b)
{
	return a + b;
}
//参数类型必须严格匹配
template <typename T>
T Myadd(T a, T b，T c)
{
	return a + b + c;
}
void test02()
{
	int a = 10;
	int b = 100;
	char c = 'a';
	char d = 'b';
	Myadd(a,b);

}
void test01()
{
	int a = 1;
	int b = 2;
	MySwap<int>(a, b);
	cout << "a= " << a << "  b = " << b << endl;

	double d1 = 1.4;
	double d3 = 2.4;
	MySwap<double>(d1, d3);
	cout << "d1= " << d1 << "  d3 = " << d3 << endl;
	// 显示调用
	Myadd<int>(a,b);
	//模版有严格的类型匹配
}
// 函数模版可以像普通函数那样被重载
// 
void main()
{

	test02();
	system("pause");
}

#endif