#include<iostream>
#include<string>
using namespace std;
#if 0
class Base{
public:
	Base(){
		cout << "Base构造函数" << endl;
	}
	~Base(){
		cout << "Base析构函数" << endl;
	}

};
class Derived :public Base{
public:
	Derived(){	
		cout << "Derived构造函数" << endl;
	}
	~Derived(){
		cout << "Derived析构函数" << endl;
	}

};
//构造函数，析构函数  顺序相反
void main()
{
	//Base b;
	Derived d;
	system("pause");
}
#endif