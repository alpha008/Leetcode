#include<iostream>
#include<string>
#if 0
using namespace std;
// 常对象  常成员函数
class Person{
public: // 隐含在每个成员中都存在一个this指针    指针常量 指针的指向是不可以修改的
	void showclassname() const//并没有访问this指针
	{// const Person *const this;
		cout << "this is Person" << endl;
	}
	void showage()    
	{
		if (this == NULL)
			return;
		cout << "age is " << age << endl; //默认会增加一个this指针
	}
	mutable int age;
};
void test02(){
	const Person p2;
	p2.age = 100;//mutable int age;加与不加的区别
}
// 常对象只能调用常函数
// this指针谁调用就指向调用该对象
void main()
{
	test02();
	system("pause");
}
#endif

