#include<iostream>
#include<string>
#if 0
using namespace std;
// 构造函数  有参数 无参数  
// 普通构造函数   拷贝构造函数
// 显示调用  隐式调用
class Person
{
public:
	Person(){                     //无参构造函数
		cout << "无参数构造函数 " << endl;
	}
	Person(string name,int age){  // 有参构造函数
		this->name = name;
		this->age = age;
		cout << "有参构造函数 "<< endl;
	}
	~Person()
	{
		cout << "析构造函数 " << endl;
	}
	Person(const Person &other){             //拷贝构造函数    属性的拷贝 不可改变原内容
		if (this == &other) //防止自身循环拷贝
			return;
		this->name = other.name;
		this->age = other.age;
		cout << "拷贝构造函数 " << endl;
	}
	Person& operator=(const Person &other){  //拷贝构造函数
		cout << "=构造函数 " << endl;
	}
	string name;
	int age;

};
//注意：  在调用默认构造不要填写小括号
void test01()
{
	//1.括号法
	// Person p1();   编译器会认为这个是函数声明
	// void func();
	Person p1;
	Person p2("alpha", 100);
	Person p3(p2);

	Person p4 = Person("spider", 100); //右边这个属于匿名对象，执行完后匿名对象就有了新的名字p4，马上会被释放掉
	//Person(p3); 不要用拷贝构造函数初始化匿名对象
	//2.显示调用
	
	//3.隐式转换   仅仅针对单个参数的类会存在这种问题
	//Person p5 = 10;
}
void main()
{
	test01();


	system("pause");
}
#endif
