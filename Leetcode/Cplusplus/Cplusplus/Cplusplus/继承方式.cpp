#include<iostream>
#include<string>
#if 0
class Base{
public:
	int a;
protected:
	int b;
private:
	int c;
};
class Derived1 :public Base{  //子类与父类
public:
	void func(){
		a = 10;       //父类中的公共权限成员依然是公共权限
		b = 100;      //父类中的保护成员在子类中依然是保护权限
		//c = 1000;   //父类私有不可访问
	}
};
void test01(){
	Derived1 d1;
	d1.a = 100;// 类外的一种关系
}
class Derived2 :protected Base{ // 子类全部都保护了
public:
	void func(){
		a = 10;     //父类中的公共权限成员依然是公共权限
		b = 100;    //父类中的保护成员在子类中依然是保护权限
		//c = 1000; //父类私有不可访问
	}
};
void test02(){
	Derived2 d2;
	//d2.a = 100;   // 类外的一种关系  只要保护了，在类外不可访问
}
class Derived3 :private Base{
public:
	void func(){
		a = 10;    
		b = 100;    
		//c = 1000; 
	}
};
void test03(){
	Derived3 d3;
	//d3.a = 100;   // 类外的一种关系  只要保护了，在类外不可访问
}
void main()
{
	// 继承改变的是父类在基类中的成员权限   
	
	system("pause");
}
#endif