#include <iostream>
using namespace std; 
class Animal{
public:
    virtual void cry() {}
};
class Dog : public Animal {
public:
    virtual void cry()
    {
        cout << "旺旺" << endl;
    }
    void dohome()
    {   
        cout << "看家" << endl;
    }

};
class  Cat : public Animal{
public:
    virtual void cry()
    {
        cout << "喵喵" << endl;
    }
    void dohome(){
        cout << "抓老鼠" << endl;
    }
};
/*************************************************************************************
1. 静态变量转换
**************************************************************************************/
int main01()
{
    double dPi = 3.1415926;
    int num1 = (int)dPi;  // c风格的转换
    int num2 = dPi;   //隐式类型转换
    int num3 = static_cast<int>(dPi);
    cout << "num1:" << num1 << "num2:" << num2 << "num3:" << num3 << endl;
    return 0;
}
/*************************************************************************************
2. dynamic_cast 子类与父类之间的多态类型准换
**************************************************************************************/
int main02(){
    Animal *base = new Cat();
    base ->cry(); //标准多态
    Dog *pDog = dynamic_cast<Dog*>(base);
    if(pDog !=NULL){
        pDog->cry();
        pDog->dohome();
    }
    Cat *pCat = dynamic_cast<Cat*>(base); //动态类型转换，主要用于多态之间
       if(pCat !=NULL){
        pCat->cry();
        pCat->dohome();
    } 
    return 0;
}
/*************************************************************************************
3.const_cast 去掉const属性转换
const_cast<目标类型>（标识符）:目标类型只能是指针或者引用
**************************************************************************************/
class A {
public:
	int data;
};
int main03()
{
    const A a = { 200 };
	A a1; //= const_cast<A>(a);    //错误，const_cast 目标类型只能是引用或者指针
	a1.data = 100;  //对象赋值

	A& a2 = const_cast<A&>(a);       // 引用改变值
	a2.data = 100;
	std::cout << a.data << ' ' << a2.data << std::endl;

	A* a3 = const_cast<A*>(&a);     // 指针改变值
	a3->data = 100;
	std::cout << a.data << ' ' << a3->data << std::endl;

	const int x = 3;

	int& x1 = const_cast<int&>(x);    // 引用改变值
	x1 = 200;
	std::cout << x << ' ' << x1 << std::endl;

	int* x2 = const_cast<int*>(&x);   // 指针改变值
	*x2 = 300;
	std::cout << x << ' ' << *x2 << std::endl;

}
/*************************************************************************************
4.reinterpret_cast 重新解释类型转换
reinterpret_cast<目标类型>（标识符） ;数据的二进制重新解释，但是不改变其值。
**************************************************************************************/
class Book {
public:
	void look()
	{
		std::cout << "Book look " << std::endl;
	}
};
int main04()
{
	Animal* a = new Animal();
	a->cry();
	Book* b = reinterpret_cast<Book*>(a);  //强制类型的转换
	b->look();
	return 0;
}
int main()
{
    main01();
    main02();
    main03();
    main04();
    return 0;
}