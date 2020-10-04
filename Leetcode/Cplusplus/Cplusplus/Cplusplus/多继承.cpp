#include<iostream>
#include<string>
#if 0
using namespace std;
class Base1{
public:
	Base1(){
	
	}
};
class Base2{
public:
	Base2(){

	}
};
class Derived:public Base1,public Base2{
public:
	Derived(){
	
	}
};
// 多继承 非静态成员变量均会继承下去，占有内存空间
void main()
{

	system("pause");
}

#endif
