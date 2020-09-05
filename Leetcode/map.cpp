#include <map>  
#include <string>  
#include <iostream>  
using namespace std;
int testMap01()
{
	map<int, string> mapStudent;
	mapStudent.insert(pair<int, string>(1, "student_one"));
	mapStudent.insert(pair<int, string>(2, "student_two"));
	mapStudent.insert(pair<int, string>(3, "student_three"));
	for (map<int, string>::iterator iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first << ' ' << iter->second << endl;
	return 0;
}
//第二种：用insert函数插入value_type数据，下面举例说明  
int testMap02()
{
	map<int, string> mapStudent;
	mapStudent.insert(map<int, string>::value_type(1, "student_one"));
	mapStudent.insert(map<int, string>::value_type(2, "student_two"));
	mapStudent.insert(map<int, string>::value_type(3, "student_three"));
	map<int, string>::iterator iter;
	for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first << ' ' << iter->second << endl;
	return 0;
}
//第三种：用数组方式插入数据，下面举例说明  
int testMap03()
{
	map<int, string> mapStudent;
	mapStudent[1] = "student_one";
	mapStudent[2] = "student_two";
	mapStudent[3] = "student_three";
	for (map<int, string>::iterator  iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first << ' ' << iter->second << endl;
	return 0;
}
//验证插入函数的作用效果  
int testMapInsert04()
{
	map<int, string> mapStudent;
	pair<map<int, string>::iterator, bool> Insert_Pair;
	Insert_Pair = mapStudent.insert(pair<int, string>(1, "student_one"));//插入数据后会返回一个Insert_Pair迭代器
	if (Insert_Pair.second == true)
		cout << "Insert Successfully" << endl;
	else
		cout << "Insert Failure" << endl;
	Insert_Pair = mapStudent.insert(pair<int, string>(1, "student_two"));
	if (Insert_Pair.second == true)
		cout << "Insert Successfully" << endl;
	else
		cout << "Insert Failure" << endl;
	map<int, string>::iterator iter;
	for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first << ' ' << iter->second << endl;
	return 0;
}
//验证数组形式插入数据的效果  
int testInserArray05()
{
	map<int, string> mapStudent;
	mapStudent[1] = "student_one";
	mapStudent[1] = "student_two";
	mapStudent[2] = "student_three";  //会覆盖之前的数据
	for (map<int, string>::iterator iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first << ' ' << iter->second << endl;
	int nSize = mapStudent.size();
	cout << "nSize = " << nSize << endl;
	return 0;
}
//第二种，利用反向迭代器  
int testMap06()
{
	map<int, string> mapStudent;
	mapStudent.insert(pair<int, string>(1, "student_one"));
	mapStudent.insert(pair<int, string>(2, "student_two"));
	mapStudent.insert(pair<int, string>(3, "student_three"));
	for (map<int, string>::reverse_iterator iter = mapStudent.rbegin(); iter != mapStudent.rend(); iter++)
		cout << iter->first << "  " << iter->second << endl;
	return 0;
}
int testMap07()
{
	map<int, string> mapStudent;
	mapStudent.insert(pair<int, string>(1, "student_one"));
	mapStudent.insert(pair<int, string>(2, "student_two"));
	mapStudent.insert(pair<int, string>(3, "student_three"));
	int nSize = mapStudent.size();
	//此处应注意，应该是 for(int nindex = 1; nindex <= nSize; nindex++)  
	//而不是 for(int nindex = 0; nindex < nSize; nindex++)  
	for (int nindex = 1; nindex <= nSize; nindex++)
		cout << mapStudent[nindex] << endl;
	return 0;
}
int testMapFind08()
{
	map<int, string> mapStudent;
	mapStudent.insert(pair<int, string>(1, "student_one"));
	mapStudent.insert(pair<int, string>(2, "student_two"));
	mapStudent.insert(pair<int, string>(3, "student_three"));
    map<int, string>::iterator iter = mapStudent.find(1);
	if (iter != mapStudent.end())
		cout << "Find, the value is " << iter->second << endl;
	else
		cout << "Do not Find" << endl;
	return 0;
}
int testMapbound09()
{
	map<int, string> mapStudent;
	mapStudent[1] = "student_one";
    mapStudent[3] = "student_three";
	mapStudent[5] = "student_five";
	map<int, string>::iterator iter;
	iter = mapStudent.lower_bound(1);
	//返回的是下界1的迭代器  
	cout << iter->second << endl;
	iter = mapStudent.lower_bound(2);
	//返回的是下界3的迭代器  
	cout << iter->second << endl;
	iter = mapStudent.lower_bound(3);
	//返回的是下界3的迭代器  
	cout << iter->second << endl;
	iter = mapStudent.upper_bound(2);
	//返回的是上界3的迭代器  
	cout << iter->second << endl;
	iter = mapStudent.upper_bound(3);
	//返回的是上界5的迭代器  
	cout << iter->second << endl;
	pair<map<int, string>::iterator, map<int, string>::iterator> mappair;
	mappair = mapStudent.equal_range(2);
	if (mappair.first == mappair.second)
		cout << "Do not Find" << endl;
	else
		cout << "Find" << endl;
	mappair = mapStudent.equal_range(3);
	if (mappair.first == mappair.second)
		cout << "Do not Find" << endl;
	else
		cout << "Find" << endl;
	return 0;
}
int testEraseMap10()
{
	map<int, string> mapStudent;
	mapStudent.insert(pair<int, string>(1, "student_one"));
	mapStudent.insert(pair<int, string>(2, "student_two"));
	mapStudent.insert(pair<int, string>(3, "student_three"));
	//如果你要演示输出效果，请选择以下的一种，你看到的效果会比较好  
	//如果要删除1,用迭代器删除  
	map<int, string>::iterator iter;
	iter = mapStudent.find(1);
	mapStudent.erase(iter);
	//如果要删除1，用关键字删除  
	int n = mapStudent.erase(1);//如果删除了会返回1，否则返回0  
	//用迭代器，成片的删除  
	//一下代码把整个map清空  
    mapStudent.erase(mapStudent.begin(), mapStudent.end());
	return 0;
}
typedef struct tagStudentinfo
{
	int      niD;
	string   strName;
	bool operator < (tagStudentinfo const& _A) const
	{     //这个函数指定排序策略，按niD排序，如果niD相等的话，按strName排序  
		if (niD < _A.niD) return true;
		if (niD == _A.niD)
			return strName.compare(_A.strName) < 0;
		return false;
	}
}Studentinfo, *PStudentinfo; //学生信息  
int testMapSort11()
{
	int nSize;   //用学生信息映射分数  
	map<Studentinfo, int>mapStudent;
	map<Studentinfo, int>::iterator iter;
	Studentinfo studentinfo;
	studentinfo.niD = 1;
	studentinfo.strName = "student_one";
	mapStudent.insert(pair<Studentinfo, int>(studentinfo, 90));
	studentinfo.niD = 2;
	studentinfo.strName = "student_two";
	mapStudent.insert(pair<Studentinfo, int>(studentinfo, 80));
	for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first.niD << ' ' << iter->first.strName << ' ' << iter->second << endl;
	return 0;
}
class sort
{
public:
	bool operator() (Studentinfo const &_A, Studentinfo const &_B) const
	{
		if (_A.niD < _B.niD)
			return true;
		if (_A.niD == _B.niD)
			return _A.strName.compare(_B.strName) < 0;
		return false;
	}
};
int testFunction12()
{   //用学生信息映射分数  
	map<Studentinfo, int, sort>mapStudent;
	map<Studentinfo, int>::iterator iter;
	Studentinfo studentinfo;
	studentinfo.niD = 1;
	studentinfo.strName = "student_one";
	mapStudent.insert(pair<Studentinfo, int>(studentinfo, 90));
	studentinfo.niD = 2;
	studentinfo.strName = "student_two";
	mapStudent.insert(pair<Studentinfo, int>(studentinfo, 80));
	for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first.niD << ' ' << iter->first.strName << ' ' << iter->second << endl;
	return 0;
}
#if 0
	begin()         返回指向map头部的迭代器
	clear(）        删除所有元素
	count()         返回指定元素出现的次数
	empty()         如果map为空则返回true
	end()           返回指向map末尾的迭代器
	equal_range()   返回特殊条目的迭代器对
	erase()         删除一个元素
	find()          查找一个元素
	get_allocator() 返回map的配置器
	insert()        插入元素
	key_comp()      返回比较元素key的函数
	lower_bound()   返回键值 >= 给定元素的第一个位置
	max_size()      返回可以容纳的最大元素个数
	rbegin()        返回一个指向map尾部的逆向迭代器
	rend()          返回一个指向map头部的逆向迭代器
	size()          返回map中元素的个数
	swap()           交换两个map
	upper_bound()    返回键值>给定元素的第一个位置
	value_comp()     返回比较元素value的函数
#endif
int main06(){
	cout << "插入数据01" << endl;
	testMap01();
	cout << "插入数据02" << endl;
	testMap02();
	cout << "插入数据03" << endl;
	testMap03();
	cout << "验证插入数据是否成功" << endl;
	testMapInsert04();
	cout << "验证数组插入数据效果" << endl;
	testInserArray05();
	cout << "验证迭代器遍历map" << endl;
	testMap06();
	cout << "验证数组遍历map" << endl;
	testMap07();
	cout << "验证map查找" << endl;
	testMapFind08();
	cout << "验证map Bound" << endl;
	testMapbound09();
	cout << "验证map erase" << endl;
	testEraseMap10();
	cout << "验证map sort" << endl;
	testMapSort11();
	cout << "验证map 仿函数 sort" << endl;
	testFunction12();
	return 0;
}