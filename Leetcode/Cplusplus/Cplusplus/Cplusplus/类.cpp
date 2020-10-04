#include<iostream>
#include<string>
using namespace std;
#if 0
const double PI = 3.14;
// 设置属性   获取属性
class Student{
public:
	Student(string name, int id){
		this->name = name;
		this->id = id;
	}
	Student(const Student&stu){

	}
	Student & operator = (Student & stu){
		
	}
	void setName(string name){
		this->name = name;
	}
	void setId(int id){
		this->id = id;
	}
	void showInfo()
	{
		cout << "name: " << name << "  Id " << id << endl;
	}
private:
	string name;
	int id;
};
class Circe{
public:
	Circe(int r)
	{
		this->m_r = r;
	}
	double calculateZC()
	{
		return 2 * PI * m_r;
	}
private:
	int m_r;
};
void main()
{
	Student s1("alpha",10);
	Student s2("spider", 100);
	s1.showInfo();
	s1.setName("alpha1");
	s1.showInfo();
	s2.showInfo();
	Circe c1(10);
	cout << "周长为：" << c1.calculateZC()<<endl;
	system("pause");
}
#endif