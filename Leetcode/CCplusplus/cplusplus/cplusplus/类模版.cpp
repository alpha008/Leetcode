#include<iostream>
#include<string>
#include<vector>
//#pragma once 只编译一次 
using namespace std;
#if 0
template<typename T>
class Person{
public:
	Person(T id, T age) :m_id(m_id), m_age(age){}
	void show(){
		cout << "m_id = " << m_id << " ," << " m_age = " << m_age << endl;
	}
	T m_id;
	T m_age;
};
// 具体类集成模版时需要将其显示类型初始化  --- 具体化不可产生歧义
class SubPerson :public Person<int>{
	
};
template<typename T>
class Women :public Person<T>{
public:
	

};



void test01(){
	Person<int> p1(10, 20);
	p1.show();
}

void main()
{
	//test01();
	system("pause");
}
#elif 1
class Solution {
public:
	string addBinary(string a, string b) {
		int carry = 0;
		string result;
		const int n = a.size() >  b.size() ? a.size() : b.size();

		for (int index = n - 1; index >= 0; index--)
		{
			int ai = index < a.size() ? a[index] - '0' : 0;
			int bi = index < b.size() ? b[index] - '0' : 0;
			const int val = (ai + bi + carry) % 2;
			 carry = (ai + bi + carry) / 2;
			result.insert(result.begin(), val + '0');
		}
		if (carry > 0)
			result.insert(result.begin(), '1');
		return result;
	}
};

void main()
{
	Solution bb;
	string s1("11");
	string s2("1");
	bb.addBinary(s1, s2);
	system("pause");
}
#endif