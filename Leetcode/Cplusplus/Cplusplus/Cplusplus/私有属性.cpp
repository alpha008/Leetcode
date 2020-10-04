#include<iostream>
#include<string>
using namespace std;
#if 0
// 成员设置为私有可控制读写，写可检测数据有效性
class Person{
public:
	//姓名可读可写
	Person(string name ,int age,string lover){
		this->m_age = age;
		this->name = name;
		this->m_Lover = lover;
	}
	void setname(string name )
	{
		 this->name = name;
	}
	string getname()
	{
		return this->name;
	}
	void  setage(int age)
	{
		if (age > 101){
			cout << "please input correct age" << endl;
			return;
		}
		this->m_age = age;
	}
	int getage()
	{
		return this->m_age ;
	}
	string SetLover(string Lover)
	{
		return this->m_Lover = Lover;
	}
private:
	string name;
	int m_age;
	string m_Lover;
};

int main()
{
	Person  p1("alpha", 100, "spider");
	cout << "get name = " << p1.getname() << endl;
	cout << "get age = " << p1.getage() << endl;

	p1.setage(200);
	p1.setname("alpha008");
	cout << "get name = " << p1.getname() << endl;
	cout << "get age = " << p1.getage() << endl;

	system("pause");
}
#endif