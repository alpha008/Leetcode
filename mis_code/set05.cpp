#include<iostream>
#include<set>
#include<string>
#include<algorithm>
#include<functional>//仿函数
//set是一个集合，变量内容是唯一的，其中值的顺序是按照规则排列的
//在插入的时候要删除，要删除原有数据在插入。不支持直接存取操作，不能指定插入位置
using namespace std;
int testSet01()
{
	set<int>setA;
	setA.insert(1);
	setA.insert(3); setA.insert(5); setA.insert(7);//不能指定位置插入
	//set<int, less<int>>setA;//仿函数实现机制，重载了（）操作符号的普通类对象
	//1拷贝构造与赋值
	//set(const set &st)   set&operator=(const set &st)  set.swap(st)
	set<int>setB;
	setB.insert(2); setB.insert(4); setB.insert(6); setB.insert(8);
	set<int>setC(setB);
	set<int>setD;
	setD = setA;
	//2.set.size()    set.empty()  判断集合为空 和集合的大小
	//3.set的删除操作
	setD.clear();//清空所有的元素
	//setD.erase(pos);  删除迭代器指向的那个元素
	//setD.erase(elem);删除集合中的元素为elem的元素
	//setD.erase(begin,end);删除迭代器所指向的区间中的元素，然后返回下一个位置的迭代器
	//4set的查找
	setA.find(3);//查找值为3的元素，返回迭代器
	setA.count(3);//数值为3的元素的个数，在SET中要么为0要么为1
	/*set.find(elem);   //查找elem元素，返回指向elem元素的迭代器。
	set.count(elem);   //返回容器中值为elem的元素个数。对set来说，要么是0，要么是1。对multiset来说，值可能大于1。
	set.lower_bound(elem);//返回第一个>=elem元素的迭代器。
	set.upper_bound(elem);//返回第一个>elem元素的迭代器。这两个都是边界那么只是区分=号的问题
	set.equal_range(elem);//返回容器中与elem相等的上下限的两个迭代器。上限是闭区间，下限是开区间，如[beg,end)。
	以上函数返回两个迭代器，而这两个迭代器被封装在pair中。 set<int> setInt;
	setInt.insert(3);
	setInt.insert(1);
	setInt.insert(7);
	setInt.insert(5);//pair也是一个模版，带参数的对象
	setInt.insert(9);
	set<int>::iterator itA = setInt.find(5);
	int iA = *itA; //iA == 5
	int iCount = setInt.count(5); //iCount == 1
	set<int>::iterator itB = setInt.lower_bound(5);
	set<int>::iterator itC = setInt.upper_bound(5);
	int iB = *itB; //iB == 5
	int iC = *itC; //iC == 7//一组迭代器，有些时候删除是不能直接删除的，要先遍历操作，找到它的迭代器，然后使用迭代器删除
	pair< set<int>::iterator, set<int>::iterator > pairIt = setInt.equal_range(5);  //pair是什么？*/
	//pair是一个对象，对象中的first   和   second  是指针分别指向不同的位置的迭代器
	for (auto c : setA)
		cout << c << " ";
	system("pause");
	return 0;
}
//仿函数实现
class CStudent
{
public:
	CStudent(int ID, string name){
		this->ID = ID;
		this->name = name;
	}
public:
	string name;
	int ID;
};
struct StuFunctor
{
	bool operator()(const CStudent&stu1, const CStudent&stu2) {
		return (stu1.ID < stu2.ID);
	}
};
int testSet02()
{
	set<CStudent, StuFunctor>setStu;//这里好比一个函数指针，代表函数入口地址
	setStu.insert(CStudent(2, "小张"));
	setStu.insert(CStudent(1, "小李"));
	setStu.insert(CStudent(5, "小王"));
	setStu.insert(CStudent(4, "小刘"));
	//multiset与上面的操作类似
	return 0;
}

int main05(){
	testSet01();
	testSet02();
	return 0;
}