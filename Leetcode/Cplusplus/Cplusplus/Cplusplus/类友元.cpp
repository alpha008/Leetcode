#include<iostream>
#include<string>
using namespace std;
#if 0
class Building;
// 声明友元类   成员函数做友元
class GoodGay{
public:
	GoodGay();
	void vist();
private:
	Building *building;
};
class Building{
	//friend class GoodGay;  // 声明友元类
	friend void GoodGay::vist();  // 声明 成员函数做友元
public:
	Building();
	string sittingroom;
private:
	string beddingroom;
};
Building::Building(){
	sittingroom = "客厅";
	beddingroom = "卧室";
}
GoodGay::GoodGay(){
	building = new Building;
}

void GoodGay::vist()
{
	cout << "goodgay is visting " << building->sittingroom << endl;
	cout << "goodgay is visting " << building->beddingroom << endl;
}


void main()
{
	GoodGay G1;
	G1.vist();

	system("pause");
}
#endif