#include<iostream>
#include<string>
#if 0
using namespace std;
class cube{
public:
	cube(int l,int w,int h);
	int calcubeS();
	int calcubeV();
private:
	int m_l;
	int m_w;
	int m_h;
};
cube::cube(int l, int w, int h)
{
	this ->m_l = l;
	this->m_w = w;
	this->m_h = h;
}
int cube::calcubeS(){
	return m_l*m_w*m_h * 6;
}

int cube::calcubeV(){
	return m_l*m_w*m_h;
}

void main()
{
	cube c1(1,2,3);
	cout << "表面积为：" << c1.calcubeS() << endl;
	cout << "体积为：   "<< c1.calcubeV() <<endl;


	system("pause");
}
#endif



