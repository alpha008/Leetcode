#include<iostream>
#include<string>
#if 0
//find -type f | xargs enca -L zh_CN -x UTF-8
using namespace std;
// 纯虚函数 抽象类
// 子类必须重写父类的纯虚函数，否则也为抽象类
class Animal{
public:
	virtual void speak() = 0;
	virtual ~ Animal() = 0;
};
Animal:: ~Animal(){
	cout << "纯虚函数调用" << endl;
}
class Cat : public Animal{
public:
	Cat(string name){
		m_Name = new string(name);
		cout << "构造函数调用" << endl;
	}
	// 子类的虚析构调用不到的问题
	virtual~Cat(){ // 虚析构解决释放基类指针释放不干净的问题
		if (m_Name != NULL)
		{
			delete m_Name;
			m_Name = NULL;
		}
		cout << "虚析构函数调用" << endl;
	}
	virtual void speak() {
		cout << *m_Name <<  " Cat:speak" << endl;
	}
	string *m_Name;
};
void main()
{
	Animal *ab = new  Cat("tom"); // 父类的指针在析构时，不会调用子类中的析构函数
	ab->speak();
	delete ab;
	system("pause");
}
#endif