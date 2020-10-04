#include<iostream>
#include<string>
#if 0
using namespace std;
//静态多态   编译时确定   函数重载 运算符重载 
//动态多态   运行时确定   
class Animal{
public:
	virtual void speak(){
		cout << "动物在说话" << endl;
	}
};
class Cat:public Animal{
public:
	void speak(){
		cout << "小猫在说话" << endl;
	}
};
void doSpeak(Animal &animal){   // 传递来的谁，就去谁的虚函数表中去找，找到了谁的虚函数表
	animal.speak();
}
void test()
{
	Cat cat;//地址早绑定  在运行阶段绑定
	doSpeak(cat);
}
//  虚函数表地址：      虚拟函数表
//  子类中的虚函数重写发生了  虚函数表覆盖
void main()
{
	test();
	system("pause");
}
#endif