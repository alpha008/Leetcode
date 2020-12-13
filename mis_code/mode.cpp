#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
/*
c++�麯����Ҫʵ���˶�̬�Ļ��ƣ� ���ڶ�̬������֮���Ǹ����ͱ��ָ��ָ���������ʵ����Ȼ��ͨ�������ָ�����ʵ������ĳ�Ա����
��ͼʹ�ò���Ĵ�����ʵ�ֿɱ���㷨�����ּ��������ø����ָ����ж�����̬��Ҫô�ڱ���ʱ���飬Ҫô������ʱ����
*/
/***********************************************************************************************
1.�������麯�����麯����ά��һ���麯����
************************************************************************************************/
class Base{
public:
	virtual void f(){ cout << "Base::f" << endl; }
	virtual void g(){ cout << "Base::g" << endl; }
	virtual void h(){ cout << "Base::h" << endl; }
private:
	int a;
};
/***********************************************************************************************
2.��̬
Base *b = new Derive();  �����б���д��ָ���ַ�Ѿ����޸�Ϊ��д�Ժ�ĵ�ַ��
b->f(); 
��b��ָ���ڴ��е��麯�����f()��λ���Ѿ���Derive::f()������ַ��ȡ����������ʵ�ʵ��÷���ʱ��
��Derive::f()�������ˡ����ʵ���˶�̬��
************************************************************************************************/
class Derive : public Base{
public:
	virtual void f(){ cout << "Derive1::f1" << endl; }
	virtual void gb1(){ cout << "Derive1::g1" << endl; }
	virtual void hc1(){ cout << "Derive1::h1" << endl; }
};

/***********************************************************************************************
3.���ؼ̳���
���麯�����ǣ����Ա����Լ������
���麯�����ǣ������еı���д�ĺ��������� 
************************************************************************************************/
class Base1{
public:
	virtual void f(){ cout << "Base1::f" << endl; }
	virtual void g(){ cout << "Base1::g" << endl; }
	virtual void h(){ cout << "Base1::h" << endl; }
private:
	int a;
};
class Base2{
public:
	virtual void f(){ cout << "Base2::f" << endl; }
	virtual void g(){ cout << "Base2::g" << endl; }
	virtual void h(){ cout << "Base2::h" << endl; }
private:
	int a;
};
class Base3{
public:
	virtual void f(){ cout << "Base3::f" << endl; }
	virtual void g(){ cout << "Base3::g" << endl; }
	virtual void h(){ cout << "Base3::h" << endl; }
private:
	int a;
};
class Derive1 :public Base1, public Base2, public Base3{
public:
	virtual void f() { cout << "Derive1::f" << endl; }
	virtual void g1() { cout << "Derive1::g1" << endl; }
};

/***********************************************************************************************
4. ͨ�������͵�ָ����������Լ����麯��
************************************************************************************************/
int main001()
{
	//1.2  ������   �����   ���಻�洢���������洢�븸���������
	Base base;
	Derive derive;
	//3. ���ؼ̳�
	Derive1 derive1;
#if 0
	Base b;
	Fun pFun = NULL;
	cout << "�麯�����ַ��" << (int*)(&b) << endl;
	cout << "�麯�����һ��������ַ" << (int*)*(int*)(&b) << endl;
	pFun = (Fun)*(int*)*(int*)(&b);
	pFun();
	pFun = (Fun)*((int*)*(int*)(&b) + 0);  // Base::f()
	pFun();
	pFun = (Fun)*((int*)*(int*)(&b) + 1);  // Base::g()
	pFun();
	pFun = (Fun)*((int*)*(int*)(&b) + 2);  // Base::h()
	pFun();
#endif
	return 0;
}



