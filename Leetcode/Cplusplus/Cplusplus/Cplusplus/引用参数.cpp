#include<iostream>
using namespace std;

void functionyy(int &a, int &b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}
void functionz(int a, int b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

void main1106()
{
	int a = 10 , b = 100;
	cout << "a = " << a << " b = " << b << endl;
	functionz(a, b);
	cout << "a = " << a << " b = " << b << endl;

	cout << "a = " << a << " b = " << b << endl;
	functionyy(a,b);
	cout << "a = " << a << " b = " << b << endl;
	system("pause");
}