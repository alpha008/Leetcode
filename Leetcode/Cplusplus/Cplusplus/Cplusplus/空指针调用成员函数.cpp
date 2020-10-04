#include<iostream>
#include<string>
using namespace std;
#if 0
class Person{
public:
	void showclassname()//并没有访问this指针
	{
		cout << "this is Person" << endl;
	}
	void showage()
	{
		if (this == NULL)
			return;
		cout << "age is " << age << endl; //默认会增加一个this指针
	}
	int age;
};

void test()
{
	Person  *p = NULL;
	p->showage();
	p->showclassname();
}
void main()
{
	test();
	system("pause");
}
#endif