#include<iostream>
#include<string>
using namespace std;
#if 0
//  成员变量 成员函数   分开存储
//  只有非静态的成员变量  才属于类的对象的
//c++编译器会给每个空对象分配一个字节空间 每个对象都应该有一个独一无二的地址
class PersonA{
};
class Person
{
public:
	Person(int  age) :age(age){}
	int  age;
	int  bb;            //类的对象上只存储数据
    int show1(){}
	static int show(){}   //成员函数不占用空间
};

void main()
{
	Person p(10);
	cout << "sizeof(PersonA) = " << sizeof(PersonA) << endl;
	cout << "sizeof(Person) = " << sizeof(Person) << endl;
	system("pause");
}
#endif