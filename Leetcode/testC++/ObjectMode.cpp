#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
/*
c++虚函数主要实现了多态的机制： 关于多态，简言之就是父类型别的指针指向其子类的实例，然后通过父类的指针调用实际子类的成员函数
试图使用不变的代码来实现可变的算法，这种技术可以让父类的指针具有多种形态，要么在编译时决议，要么在运行时决议
*/
/***********************************************************************************************
1.基类中虚函数，虚函数表，维护一个虚函数表
************************************************************************************************/
class Base{
public:
	virtual void f(){ cout << "Base::f" << endl; }
	virtual void g(){ cout << "Base::g" << endl; }
	virtual void h(){ cout << "Base::h" << endl; }
private:
	int a;
};
/***********************************************************************************************
2.多态
Base *b = new Derive();  父类中被重写的指针地址已经被修改为重写以后的地址了
b->f(); 
由b所指的内存中的虚函数表的f()的位置已经被Derive::f()函数地址所取代，于是在实际调用发生时，
是Derive::f()被调用了。这就实现了多态。
************************************************************************************************/
class Derive : public Base{
public:
	virtual void f(){ cout << "Derive1::f1" << endl; }
	virtual void gb1(){ cout << "Derive1::g1" << endl; }
	virtual void hc1(){ cout << "Derive1::h1" << endl; }
};

/***********************************************************************************************
3.多重继承中
无虚函数覆盖：各自保存自己的虚表
有虚函数覆盖：父类中的被重写的函数被覆盖 
************************************************************************************************/
class Base1{
public:
	virtual void f(){ cout << "Base1::f" << endl; }
	virtual void g(){ cout << "Base1::g" << endl; }
	virtual void h(){ cout << "Base1::h" << endl; }
private:
	int a;
};
class Base2{
public:
	virtual void f(){ cout << "Base2::f" << endl; }
	virtual void g(){ cout << "Base2::g" << endl; }
	virtual void h(){ cout << "Base2::h" << endl; }
private:
	int a;
};
class Base3{
public:
	virtual void f(){ cout << "Base3::f" << endl; }
	virtual void g(){ cout << "Base3::g" << endl; }
	virtual void h(){ cout << "Base3::h" << endl; }
private:
	int a;
};
class Derive1 :public Base1, public Base2, public Base3{
public:
	virtual void f() { cout << "Derive1::f" << endl; }
	virtual void g1() { cout << "Derive1::g1" << endl; }
};

/***********************************************************************************************
4. 通过父类型的指针访问子类自己的虚函数
************************************************************************************************/
int main()
{
	//1.2  父子类   父类表   子类不存储子类的虚表，存储与父类相关联的
	Base base;
	Derive derive;
	//3. 多重继承
	Derive1 derive1;
#if 0
	Base b;
	Fun pFun = NULL;
	cout << "虚函数表地址：" << (int*)(&b) << endl;
	cout << "虚函数表第一个函数地址" << (int*)*(int*)(&b) << endl;
	pFun = (Fun)*(int*)*(int*)(&b);
	pFun();
	pFun = (Fun)*((int*)*(int*)(&b) + 0);  // Base::f()
	pFun();
	pFun = (Fun)*((int*)*(int*)(&b) + 1);  // Base::g()
	pFun();
	pFun = (Fun)*((int*)*(int*)(&b) + 2);  // Base::h()
	pFun();
#endif
	return 0;
}



