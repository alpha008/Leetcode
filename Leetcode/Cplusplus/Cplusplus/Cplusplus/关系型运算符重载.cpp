#include<iostream>
#include<string>
using namespace std;
#if 0
class Person{
public:
	Person(string name, int age) :name(name), age(age){}
	string name;
	int age;
	bool operator==(const Person&other){
		if (this->age == other.age && this->name == other.name)
			return true;
		return false;
	}
	bool operator!=(const Person&other){
		if (this->age == other.age && this->name == other.name)
			return false;
		return true;
	}
};

void main()
{
	Person p1("Tom",18);
	Person p2("Tom",19);
	if (p1 == p2){
		cout << "p1 = p2" << endl;
	}
	else{
		cout << "p1 != p2" << endl;
	}
	system("pause");

}
#endif

