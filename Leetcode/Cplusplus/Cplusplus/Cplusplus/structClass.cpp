#include<iostream>
#include<string>
using namespace std;
/*
class 默认私有
struct 默认公有
*/
#if 0
class C1{
	string name;
};
struct C2{
	string name;
};
int main()
{
	C1 c1;
	//c1. 没有可访问内容
	C2 c2;
	c2.name = "alpha";
	cout << c2.name << endl;
	system("pause");
}
#endif