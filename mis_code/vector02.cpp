#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
//vector是将元素置于一个动态数组中加以管理的容器，支持下标索引[],at()方法
//元素是按照值拷贝的方式进行的，所以要提供拷贝构造函数

void printVector(vector<int>vectorPrint){
	for (int c : vectorPrint){
		cout << c << " ";
	}
	cout << endl;
}
int mainvector02()
{
	//1.带参数的构造函数
	cout << "1.带参数的构造函数" << endl;
	int a[] = { 0, 1, 2, 3, 4 };
	int b[] = { 5, 6, 7, 8, 9 ,10 };
	vector<int>vectorA(a, a + 5);//可以将相对应的内存地址连续的赋值给容器，区间是左闭右开的原则
	vector<int>vectorB(vectorA.begin(), vectorA.end());//本质上还是两个地址区间的内容进行赋值
	vector<int>vectorC(3, 9);//构造函数将3个9进行拷贝赋值
	vector<int>vectorD(vectorA);//两个类型相同的容器进行拷贝赋值
	printVector(vectorA);
	printVector(vectorB);
	printVector(vectorC);
	printVector(vectorD);
	cout << "vector.szie =  " << vectorA.size() << "vector.capacity = " << vectorA.capacity() << endl;
	//2.赋值操作
	cout << "2.赋值操作" << endl;
	vectorA.assign(a, a + 5);//重新分配，不使用拷贝构造函数
	printVector(vectorA);
	vectorB.assign(vectorA.begin(), vectorA.end());
	printVector(vectorB);
	vectorD = vectorB;
	printVector(vectorD);
	vectorB.assign(b, b + 5);//重新分配赋值
	printVector(vectorB);
	vectorD.swap(vectorB);// 同类型容器值交换，只覆盖vectorD.size()个位置
	printVector(vectorD);

	//3.容器大小操作
	cout << "3.容器大小操作" << endl;
	cout<< vectorD.size()<< endl;//求容器的大小
	bool dempty = vectorD.empty();//判断容器是否为空，是空的话为1
	cout << "dempty = " << dempty << endl;
	vectorD.resize(6);//重新设置容器大小，默认使用0填充
	printVector(vectorD);
	vectorD.resize(8, 3); //重新设置容器大小，显示调用3填充
	printVector(vectorD);
	vectorD.resize(2);    //重写设置大小，截断后面多余部分
	printVector(vectorD);
	//4.容器末尾添加和删除元素
	cout << "4.容器末尾添加和删除元素" << endl;
	vector<int>vectorE;
	vectorE.push_back(1);//从末尾插入元素
	vectorE.push_back(3);
	vectorE.push_back(5);
	vectorE.push_back(7);
	vectorE.push_back(9);
	printVector(vectorE);
	vectorE.pop_back();//从末尾弹出元素
	vectorE.pop_back();
	printVector(vectorE);
	//5.vector数据元素的存取
	cout << "5.vector数据元素的存取" << endl;

	cout << vectorE[0]<< endl;//根据下标求容器对应位置的值
	cout << vectorE.at(1) << endl;
	cout << vectorE.front() << endl;  //返回开始位置元素
	cout << vectorE.back() << endl;   //返回末尾元素
	for (vector<int>::iterator it = vectorE.begin(); it != vectorE.end(); ++it) //it++前面++返回引用，后者++返回值
		cout << *it << " ";                                                     //正向遍历，而且是可以修改的
	cout << endl;
	for (vector<int>::reverse_iterator it = vectorE.rbegin(); it != vectorE.rend(); ++it)
		cout << *it << " ";                                                         //反向遍历 ，而且是可以修改的
	cout << endl;
	for (vector<int>::const_iterator it = vectorE.begin(); it != vectorE.end(); ++it)//it++前面++返回引用，后者++返回值
		cout << *it << " ";                                                     //正向遍历,不可以修改的，是常指针
	cout << endl;
	for (vector<int>::const_reverse_iterator it = vectorE.rbegin(); it != vectorE.rend(); ++it)
		cout << *it << " ";                                                     //反向遍历 ，不可以修改的，是常指针*/
	cout << endl;
	//6.插入操作
	cout << "6.插入操作" << endl;
	vector<int>vectorF(1);    //填入设置的大小，默认为0
	vector<int>vectorG(2);    //填入设置的大小，默认为0
	cout << "vectorF" << endl;
	printVector(vectorF);
	cout << "vectorG" << endl;
	printVector(vectorG);
	vectorF.insert(vectorF.begin(), 11);        //从vectorF.begin()开始插入此元素
	cout << "vectorF insert1" << endl;
	printVector(vectorF);
	vectorF.insert(vectorF.begin() + 1, 2, 22); //从vectorF.begin()开始插入n个此元素
	cout << "vectorF insert2" << endl;
	printVector(vectorF);
	vectorF.insert(vectorF.begin(), vectorG.begin(), vectorG.end());//从vectorF.begin()开始将整个区间的元素插入此位置
	//7.删除和清除操作
	cout << "7.删除和清除操作" << endl;
	printVector(vectorF);
	vectorF.clear();//删除此容器内的所有元素
	printVector(vectorF);
	vector<int>::const_iterator it = vectorF.begin(); //常指针，删除会报错
	vectorF.erase(it);           //删除位置上的元素，但是参数是迭代器
	vectorF.erase(it, it + 3);   //删除迭代器所指向的区间的元素

	return 0;
}
