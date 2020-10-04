#include<iostream>
#include<string>
#if 0
using namespace std;
// <<   左移运算符

class Person{
public:
	Person(){}
	// 成员函数重载
	Person operator+(Person &other){
		Person temp;
		temp.m_a = this->m_a + other.m_a;
		temp.m_b = this->m_b + other.m_b;
		return temp;
	}
	bool operator< (Person &other){
		return this->m_a < other.m_a;
	}

	int m_a;
	int m_b;
};
//无法使用成员函数在左侧，只能利用全局函数重载<<左移运算符
//标准输出流  全局函数搞为友元函数
ostream& operator<<(ostream &os, Person &p){
	os << "m_a = " << p.m_a << " m_b = " << p.m_b ;
	return os;
}

class MyInteger
{
	friend ostream& operator<<(ostream &os, MyInteger myint);
public:
	MyInteger()
	{
		m_Num = 0;
	}
	//前置递增
	MyInteger& operator++(){
		m_Num++;
		return *this;
	}
	//后置递增
	MyInteger operator++(int ){ //占位符号
		// 先记录当时的结果
		MyInteger temp = *this;
		//后递增
		m_Num++;
		//最后将记录的结果返回
		return temp;
	}
private:
	int m_Num;
};
ostream& operator<<(ostream &os, MyInteger myint){
	os << "a = " << myint.m_Num;
	return os;
}
//前置++是合法的，后置连续++不合法
void test02()
{
	MyInteger myint;
	int a = 0;
	cout << ++(++a) << endl;  //表达式先加  后自增
	cout << ++myint << endl;
	cout << myint << endl;
	cout << myint++<< endl;
	cout << myint << endl;
}
void test01()
{
	Person p1;
	p1.m_a = 10;
	p1.m_b = 100;
	Person p2;
	p2.m_a = 22;
	p2.m_b = 100;
	bool b1 = p1 < p2;
	cout << p1 << endl;
	cout << "做差:" << b1 << endl;
}

void main()
{
	test02();
	system("pause");
}

#endif