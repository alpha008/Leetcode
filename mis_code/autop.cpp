#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;
#if 0
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
	//���캯��
	SmartPtr() { rp = nullptr; }
	SmartPtr(Point *ptr) :rp(new RefPtr(ptr)) {}
	SmartPtr(const SmartPtr &sp) :rp(sp.rp) {
		++rp->count;
		cout << "in copy constructor" << endl;
	}

	//���ظ�ֵ�����
	SmartPtr& operator=(const SmartPtr& rhs) {
		++rhs.rp->count;
		if (rp != nullptr && --rp->count == 0) {
			delete rp;
		}
		rp = rhs.rp;
		cout << "in assignment operator" << endl;
		return *this;
	}

	//����->������
	Point* operator->() {
		return rp->p;
	}

	//����*������
	Point& operator*() {
		return *(rp->p);
	}

	~SmartPtr() {
		if (--rp->count == 0) delete rp;
		else cout << "����" << rp->count << "��ָ��ָ���������" << endl;
	}

private:
	RefPtr* rp;
};

unique_ptr<string> demo(const char* s) {
	unique_ptr<string> temp(new string(s));
	return temp;
}



int main03() {

	unique_ptr<int[]> p(new int[3]{1, 2, 3});
	p[0] = 0;// ������operator[]


	//��ʽһ��
	vector<unique_ptr<string>> vs{ new string{ "admin" }, new string{ "adminadmin" } };

	//��ʽ����
	vector<unique_ptr<string>>v;
	unique_ptr<string> p1(new string("abc"));




	// �����д�����´��룺
	unique_ptr<string> ps;
	ps = demo("Uniquely special");

	unique_ptr<string> upt(new string("lvlv"));
	//unique_ptr<string> upt1(upt);	//��������ѽ�ֹ����
	//unique_ptr<string> upt1 = upt;	//��������ѽ�ֹ����
	unique_ptr<string> upt1 = std::move(upt);  //����Ȩ��ת��

	if (upt.get() != nullptr) {	// �п��Ƿ��в����˶����Ȩ��
		// do something
	}

	auto_ptr<string> apt(new string("lvlv"));
	auto_ptr<string> apt1(apt);	//����ͨ��
	auto_ptr<string> apt1 = apt;	//����ͨ��


	shared_ptr <string> films[5] = {
		shared_ptr <string>(new string("Fowl Balls")),
		shared_ptr <string>(new string("Duck Walks")),
		shared_ptr <string>(new string("Chicken Runs")),
		shared_ptr <string>(new string("Turkey Errors")),
		shared_ptr <string>(new string("Goose Eggs"))
	};
	shared_ptr <string> pwin;
	pwin = films[2]; // films[2] loses ownership. ������Ȩ��films[2]ת�ø�pwin����ʱfilms[2]�������ø��ַ����Ӷ���ɿ�ָ��

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
	//cout << (*ptrA).c_str() << endl;//��������

	//����ָ��Ĵ���
	unique_ptr<int> u_i; 	//����������ָ��
	u_i.reset(new int(3)); 	//�󶨶�̬����  
	cout << "u_i =  " << *u_i << endl;
	unique_ptr<int> u_i2(new int(4));//����ʱָ����̬����
	cout << "u_i2 =  " << *u_i2 << endl;
	//����Ȩ�ı仯  
	int *p_i = u_i2.release();	//��ʾ�ͷ�����Ȩ��������Ȩ����p_i  

	//cout << "u_i2 =  " << *u_i2 << endl;  �Ѿ�û�з���Ȩ����
	unique_ptr<string> u_s(new string("abc"));
	cout << "u_s =  " << (*u_s).c_str() << endl;
	unique_ptr<string> u_s2;//= std::move(u_s); //����Ȩת��(ͨ���ƶ�����)��u_s����Ȩת�ƺ󣬱�ɡ���ָ�롱
	//cout << "u_s =  " << (*u_s).c_str() << endl; ͬһʱ��ֻ����ָ��һ������Ȩ���ͷź���������Ч
	u_s2.reset(u_s.release());	//����Ȩת��,release���ص���ԭ����Ŀ���Ȩ
	cout << "u_s2 =  " << (*u_s2).c_str() << endl;
	u_s2 = nullptr;//��ʽ������ָ����ͬʱ����ָ���Ϊ��ָ�롣��u_s2.reset()�ȼ�
	return 0;
}
#endif