#include<iostream>
#include<string>
using namespace std;
#if 0
class Animal{
public:
	int m_age;
};
class Sheep:virtual public Animal{
public:

};
class Tuo :virtual public Animal{
public:

};
class SheepTuo :public Sheep, public Tuo{
public:

};
//利用虚继承可以解决资源浪费问题
void test01(){
	SheepTuo st;
	st.Sheep::m_age = 19;
	st.Tuo::m_age = 20;             //菱形继承产生了两份数据，资源浪费
	cout << " st.Sheep::m_age"<< st.Sheep::m_age << endl;
	cout << " st.Tuo::m_age  "<< st.Tuo::m_age << endl;
	cout << " st.m_age  " << st.m_age << endl;
}
void main()
{
	test01();
	system("pause");
}
#endif