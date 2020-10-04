#include<iostream>
#include<string>
using namespace std;
#if 0
class Java{
public:
	void header(){
		cout << "首页，公开课，登录，注册" << endl;
	}
	void footer(){
		cout << "帮助中心，交流合作，站内地图" << endl;
	}
	void left(){
		cout << "Java Python" << endl;
	}
	void contetn(){
		cout << "Java视频教学" << endl;
	}
};
class Cplus{
public:
	void header(){
		cout << "首页，公开课，登录，注册" << endl;
	}
	void footer(){
		cout << "帮助中心，交流合作，站内地图" << endl;
	}
	void left(){
		cout << "Cplus Python" << endl;
	}
	void contetn(){
		cout << "Cplus视频教学" << endl;
	}
};
void test01(){
	Java ja;
	ja.header();
	ja.contetn();
	ja.footer();
	ja.left();
	cout << ".........................................." << endl;
}
void test02(){
	Cplus c;
	c.header();
	c.contetn();
	c.footer();
	c.left();
	cout << ".........................................." << endl;
}
class Base{
public:
	Base(string name, string age) :name(name), age(age){
	
	}
	void showname()
	{
		cout << "名字：" << this->name << "   年龄" << this->age << endl;
	}
	string  name;
	string  age;
};
class Derived :public Base{
public:
	Derived(string name, string age) :Base(name, age){	
	}

};
void main()
{
	//test01();
	//test02();
	Derived d1("alpha","11");
	d1.showname();
	system("pause");
}
//继承来的是共性，自己添加的是个性
#endif

