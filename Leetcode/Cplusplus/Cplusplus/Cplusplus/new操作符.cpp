#include<iostream>
using namespace std;
void function()
{
	int * arr = new int[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << "arr = " << arr[i] << endl;
	}
	delete[] arr;
}
void mainnew()
{
	function();
	system("pause");
}