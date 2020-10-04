#include<iostream>
#include<string>
using namespace std;
#if 0
class Base{
public:
	int m_a;
protected:
	int m_b;
private:
	int m_c;   //隐藏的数据被隐藏了，子类中确实存在的

};
class Derived :public Base{
public:
	int m_d;
};
// 对象模型   非静态成员都会被子类继承下去
void main()
{
	cout << "sizeof(Base)" << sizeof(Base) << endl;
	cout << "sizeof(Derived)" << sizeof(Derived) << endl;
	system("pause");
}
#endif