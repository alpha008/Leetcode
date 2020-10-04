#include<iostream>
#include<string>
using namespace std;
//对象成员
#if 0
class Phone{
public:
	Phone(string p_name){
		this->p_name = p_name;
		cout << "手机构造" << endl;
	}
	~Phone()
	{
		cout << "手机析构" << endl;
	}
	string p_name;
};
class  Person{         //先有属性在有外围方法
public:
	Person(string name, string phone) :m_phone(phone){
		this->name = name;
		cout << "人构造" << endl;
	}
	~Person(){
		cout << "人析构" << endl;
	}
	string name;
	Phone m_phone; //先构造成员
};

void test01()
{
	Person p("alpha","apple");
	cout << p.name << "  has  " << p.m_phone.p_name << endl;

}

void  main()
{
	test01();
	system("pause");
}
#endif
