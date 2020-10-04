#include<iostream>
using namespace std;
#if 0
class  Person{
public:
	Person()
	{
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
	Person(int age, int H) :age(age), m_Height(new int(H))
	{
		cout << "�вι��캯��" << endl;
	}
	Person(const Person &other)
	{
		this->age = other.age;
		this->m_Height = new int(*other.m_Height);
		cout << "�������캯��" << endl;
	}
	~Person()
	{
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "��������" << endl;
	}
	int age;
	int *m_Height;// ǳ����  ���ϵ��ڴ汻�ظ��ͷ�
};

void test01()
{
	Person p1(18, 160);

	cout << "p1������:" << p1.age << endl;
	cout << "p1������:" << *p1.m_Height << endl;
	Person p2(p1);
	cout << "p2������:" << p2.age << endl;
	cout << "p2������:" << *p2.m_Height << endl;

}

void  main()
{
	test01();
	system("pause");
}
#endif
