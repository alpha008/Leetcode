#include<iostream>
#include<string>
#if 0
using namespace std;
const double PI = 3.14;
// 父子关系   
//公共权限 public     类内可以访问  类外可以访问
//保护权限 protected  类内可以访问  类外不可以访问
//私有权限 private    类内可以访问  类外不可以访问
class Person{
public:      //类内和类外均可访问
	void func()
	{
		this->m_mame = "alpha";
		this->m_car = "拖拉机";
		this->m_passwd = 123456;
	}
	string m_mame;
protected:   // 类内可访问，类外不可访问不能通过对象.成员访问
	string m_car;
private:
	int m_passwd;
};

class Son{
public:
protected:
private:
};

void main()
{
	Person p1;
	p1.m_mame = "spider";   //类外可访问公共
	//p1.m_car = "baoshijie"; //类外不可访问 保护
	//p1.m_passwd = 1234;     //类外不可访问 私有
	
	
	
	system("pause");
}
#endif