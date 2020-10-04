#include<iostream>
#include<string>
#include<string>
using namespace std;
#if 0
class MyPrint{
public:
	void operator()(string test){
		cout << "string test" << endl;
	}
};
class Myadd{
public:
	int operator()(int num1,int num2){
		return num1 + num2;
	}
};
void main()
{
	MyPrint my;
	my("hello");  //使用起来非常像函数，仿函数
	Myadd a1;
	cout << "求和为:"<< a1(11, 22)<<endl;
	cout << "求和为:" << Myadd()(22, 33) << endl; //匿名对象
	system("pause");
}
#endif