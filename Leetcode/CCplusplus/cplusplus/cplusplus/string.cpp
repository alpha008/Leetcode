#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;
#if 0
void test01()
{
	string s1("hello dadaa");
	cout << "s1.length = " << s1.length() << endl;
	cout << "s1.size = " << s1.size() << endl;
	cout << "s1.capacity = " << s1.capacity() << endl;

	string s2;

	string s3(10,'a');
	string s4(s3);    //拷贝构造
	s2 = "dasdasda";  //=号赋值
	cout << "s2 = " << s2 << endl;
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;
	s2.assign("d11111");           // 重新赋值
	cout << "s2 = " << s2 << endl;
	for (int i = 0; i < s2.size(); i++){
		cout << s2.at(i) << " ";
	}
	cout << "---------------"<< endl;
	for (int i = 0; i < s2.size(); i++){
		cout << s2[i] << " ";
	}
	//[]   访问越界会崩溃   at 访问越界会抛异常 out_of_range
	try{
		cout << s2.at(100) << " ";
	}
	catch(...){
		cout << "out_of_range" << endl;
	}

}
void test04(){
	string s1 = "abcd";
	s1 += "efge";
	cout << "s1 = " << s1 << endl;
	string s2 = "bbbb";
	s2.append(s1);
	cout << "s2 = " << s2  << endl;
	//查找第一次出现的位置
	int pos = s1.find("bc");
	cout << "pos = " << pos << endl;
	 pos = s1.rfind("fg");
	cout << "pos = " << pos << endl;
}
void test05()
{
	string s = "abcdefg";
	s.replace(0,1,"111");
	cout << "s = " << s << endl;


	string s1 = "abcde";
	string s2 = "abcde";// 相等返回0
	cout << "compare :" << s1.compare(s2) << endl;

	// 插入字符串
	s1.insert(0,"333");
	cout << "s1 = " << s1 << endl;

	string s4 = "abcdefg";
	cout << "s4 = " << s4.substr(1, 2) << endl;
	string s5 = "abcdefg";
	s5.erase(0, 2); //0位置开始，删除两个
	cout << "s5 = " << s5 << endl;
}
void main()
{
	//test01();
	//test04();
	test05();
	system("pause");
}

#endif