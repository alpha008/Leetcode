#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int xVal = 0, int yVal = 0) :x(xVal), y(yVal) 
	{
		
	}
	int getX() const { return x; }
	int getY() const { return y; }
	void setX(int xVal) { x = xVal; }
	void setY(int yVal) { y = yVal; }
};
class RefPtr {
private:
	friend class SmartPtr;
	RefPtr(Point *ptr) :p(ptr), count(1){}
	~RefPtr(){ delete p; }

	int count;
	Point *p;
};

class SmartPtr {
public:
	//构造函数
	SmartPtr() { rp = nullptr; }
	SmartPtr(Point *ptr) :rp(new RefPtr(ptr)) {}
	SmartPtr(const SmartPtr &sp) :rp(sp.rp) {
		++rp->count;
		cout << "in copy constructor" << endl;
	}

	//重载赋值运算符
	SmartPtr& operator=(const SmartPtr& rhs) {
		++rhs.rp->count;
		if (rp != nullptr && --rp->count == 0) {
			delete rp;
		}
		rp = rhs.rp;
		cout << "in assignment operator" << endl;
		return *this;
	}

	//重载->操作符
	Point* operator->() {
		return rp->p;
	}

	//重载*操作符
	Point& operator*() {
		return *(rp->p);
	}

	~SmartPtr() {
		if (--rp->count == 0) delete rp;
		else cout << "还有" << rp->count << "个指针指向基础对象" << endl;
	}

private:
	RefPtr* rp;
};

unique_ptr<string> demo(const char* s) {
	unique_ptr<string> temp(new string(s));
	return temp;
}



int main() {

	unique_ptr<int[]> p(new int[3]{1, 2, 3});
	p[0] = 0;// 重载了operator[]


	//方式一：
	vector<unique_ptr<string>> vs{ new string{ "admin" }, new string{ "adminadmin" } };

	//方式二：
	vector<unique_ptr<string>>v;
	unique_ptr<string> p1(new string("abc"));




	// 假设编写了如下代码：
	unique_ptr<string> ps;
	ps = demo("Uniquely special");

	unique_ptr<string> upt(new string("lvlv"));
	//unique_ptr<string> upt1(upt);	//编译出错，已禁止拷贝
	//unique_ptr<string> upt1 = upt;	//编译出错，已禁止拷贝
	unique_ptr<string> upt1 = std::move(upt);  //控制权限转移

	if (upt.get() != nullptr) {	// 判空是否含有操作此对象的权限
		// do something
	}

	auto_ptr<string> apt(new string("lvlv"));
	auto_ptr<string> apt1(apt);	//编译通过
	auto_ptr<string> apt1 = apt;	//编译通过


	shared_ptr <string> films[5] = {
		shared_ptr <string>(new string("Fowl Balls")),
		shared_ptr <string>(new string("Duck Walks")),
		shared_ptr <string>(new string("Chicken Runs")),
		shared_ptr <string>(new string("Turkey Errors")),
		shared_ptr <string>(new string("Goose Eggs"))
	};
	shared_ptr <string> pwin;
	pwin = films[2]; // films[2] loses ownership. 将所有权从films[2]转让给pwin，此时films[2]不再引用该字符串从而变成空指针

	cout << "The nominees for best avian baseballl film are\n";
	for (int i = 0; i < 5; ++i)
	{
		cout << *films[i] << endl;
	}
	cout << "The winner is " << *pwin << endl;
	return 0;
}
int main01()
{
	auto ptrA = make_unique<string>("abcede");
	cout << (*ptrA).c_str()<< endl;
	auto ptrb = std::move(ptrA);

	cout << (*ptrb).c_str() << endl;
	//cout << (*ptrA).c_str() << endl;//错误做法

	//智能指针的创建
	unique_ptr<int> u_i; 	//创建空智能指针
	u_i.reset(new int(3)); 	//绑定动态对象  
	cout << "u_i =  " << *u_i << endl;
	unique_ptr<int> u_i2(new int(4));//创建时指定动态对象
	cout << "u_i2 =  " << *u_i2 << endl;
	//所有权的变化  
	int *p_i = u_i2.release();	//显示释放所有权，将所有权交给p_i  

	//cout << "u_i2 =  " << *u_i2 << endl;  已经没有访问权限了
	unique_ptr<string> u_s(new string("abc"));
	cout << "u_s =  " << (*u_s).c_str() << endl;
	unique_ptr<string> u_s2;//= std::move(u_s); //所有权转移(通过移动语义)，u_s所有权转移后，变成“空指针”
	//cout << "u_s =  " << (*u_s).c_str() << endl; 同一时刻只允许指向一个对象，权限释放后，在引用无效
	u_s2.reset(u_s.release());	//所有权转移,release返回的是原对象的控制权
	cout << "u_s2 =  " << (*u_s2).c_str() << endl;
	u_s2 = nullptr;//显式销毁所指对象，同时智能指针变为空指针。与u_s2.reset()等价
	return 0;
}