#include<iostream>
#include<string>
#if 0
using namespace std;
//全局函数做友元
//类做友元
//类的成员函数做友元
class Building {
	friend void vister2(Building&bulid);
public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_bedroom = "卧室";
	}
	string m_SittingRoom;
private:
	string m_bedroom;
};
void vister1(Building&bulid)
{
	cout << "好基友正在访问：" << bulid.m_SittingRoom << endl;
}
void vister2(Building&bulid)
{
	cout << "好基友正在访问：" << bulid.m_bedroom << endl;
}
void test02()
{
	Building build;
	vister1(build);
	vister2(build);
}
void main()
{
	test02();
	system("pause");
}
#endif


