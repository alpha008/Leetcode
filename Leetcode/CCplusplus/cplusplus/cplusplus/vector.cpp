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
//   vector 是单口容器   vector 实现了数组的动态增长，当空间不够时
//   会申请更大的一块内存空间，拷贝到新空间并释放旧空间的数据
//   插入元素，该元素会在容器的尾部，当超过其存储空间时，会重新分配新的空间并完成内容的拷贝
void test01()
{
	vector<int>vector1(10, 2);
	vector1.push_back(10);

	int arr[] = {1,2,3,4,5,6,7};
	vector<int>vector2(arr, arr+ sizeof(arr) / sizeof(int)); //使用某一地址空间的值来初始化
	vector<int>vector3(vector2.begin(), vector2.end());
	vector<int>vector4(vector3);
	vector<int>::iterator it = vector1.begin();
	vector1.insert(it, 20);   // 删除元素时，后面元素的迭代器会失效
	//迭代器失效
	it = vector1.begin();
	for (; it != vector1.end(); it++){
		cout << *it << " " ;
	}
}
void test02()
{
	vector<int>vector1(10, 2);
	vector<int>vector2(10, 3); //构造函数初始化
	vector1 = vector2;    //重载=号赋值
	swap(vector1,vector2);   // 交换
	vector2.assign(vector1.begin(),vector1.end());
}
int fun1(int num)
{
	cout << "num = " << num << endl;
	if (num <= 0)
		return 1;
	return fun1(num - 1) + fun1(num - 2);
}
//vector<int> 大小操作
//size()  返回容器中元素的个数
//empty() 判断容器是否为空
//resize() 重新指定容器的长度  如果变长 以默认值填冲   若变短  则尾部超出元素将会被删除
//capacity()  返回容器的容量
//reserve(len)   预留len个元素，不初始化不可访问
void test03() //容量的概念
{
	vector<int> vector1;
	vector1.push_back(10);
	cout << "vector1.size()" << vector1.size()<<endl;
	cout << "vector1.capacity()" << vector1.capacity() << endl;
	cout << "vector1.empty()" << vector1.empty() << endl;
	vector1.resize(10);
	vector1.reserve(2);	
}
void test04()
{
	//数据存取数据at安全
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	vector<int>vector2(arr, arr + sizeof(arr) / sizeof(int)); //使用某一地址空间的值来初始化
	for (int i = 0; i < vector2.size(); i++){
		cout << vector2[i] << " ";
	}
	cout << "---------------------" << endl;
	for (int i = 0; i < vector2.size(); i++){
		cout << vector2.at(i) << " ";
	}
	cout << "---------------------" << endl;
	cout << "vector2.front()" << vector2.front() << " vector.back()= " << vector2.back()<<endl;
	// 插入和删除  erase  迭代器删除
	vector2.pop_back();
	cout << "---------------------" << endl;
	for (int i = 0; i < vector2.size(); i++){
		cout << vector2.at(i) << " ";
	}
	cout << endl;
	vector2.insert(vector2.begin(),30);
	vector2.insert(vector2.begin()+2, 300);    //支持随机访问可以这样+2
	for (int i = 0; i < vector2.size(); i++){
		cout << vector2.at(i) << " ";
	}
	vector2.erase(vector2.begin()+1,vector2.end());//删除区间
	vector2.clear();//清空元素
	vector2.reserve(10);//预留空间

	vector<int> vectest;
	int num_test = 0;
	int *address = NULL;
	vectest.reserve(100000);// 提前申请保留多大的空间
	for (int i = 0; i < 100000; i++){
		vectest.push_back(i);
		if (address != &(vectest[0])){
			address = &(vectest[0]);
			num_test++;
		}
	}
	cout << "num_test = " << num_test << endl;
}

void main()
{
	//test01();
	//cout << fun1(1);
	//test02();
	//test03();
	test04();
	system("pause");
}


#endif