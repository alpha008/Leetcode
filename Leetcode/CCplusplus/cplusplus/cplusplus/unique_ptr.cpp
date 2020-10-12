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
#include<memory>
using namespace std;
// 用来动态管理对象的
#if 0
struct Person
{
public:
	~Person(){
		cout << "析造函数" << endl;
	}
	string name;
};
//将栈与智能指针的值绑定在一起
unique_ptr<Person> test()
{
	return  unique_ptr<Person>(new Person);
}
void test01()
{
	//string * str(new string("hello"));
	//delete str;
	unique_ptr<Person> pointer = test();
	pointer->name = "alpha";
	cout << pointer->name << endl;
	unique_ptr<Person>p2 = move(pointer);
	if (p2){
		cout << "p2拥有对象所有权" << endl;
	}
	if (!pointer)
	{
		cout << "pointer is null" << endl;
	}
	p2.reset(new Person);//管理新的对象，释放上一次管理的对象
}
//智能有一个指针拥有该对象的所有权
void test02()
{
	auto ptr = make_unique<Person>();
	ptr->name = "word";
}
template<typename T>
struct Node
{
	T data;
	unique_ptr<Node<T>> next;
	~Node(){
		cout << "Node析构函数" << endl;
	}
};
template <typename T>
class Link{
public:
	void front(const T &data){
		auto node = make_unique<Node<T>>();
		node->data = data;
		node->next = move(head_.next);
		head_.next = move(node);
	}
	void print(){
		Node<T>*node = head_.next.get(); //获取智能指针
		while (node){
			cout << node->data << ' ' ;
			node = node->next.get();
		}
	}
private:
	Node<T> head_;
};
void test03()
{
	Link<int>lk;
	for (int val : {1, 2, 3, 4, 5})
	{
		lk.front(val);
	}
	lk.print();
}
void test04()
{
	shared_ptr<string > p1(new string("shared_ptr"));
	cout << "p1引用计数;" << p1.use_count() << endl;
	shared_ptr<string > p2 = p1;
	cout << "p2引用计数;" << p2.use_count() << endl;

}

void main()
{

	//test01();
	//test02();
	test04();
	system("pause");
}
#elif 0
struct Task {
	int mId;
	Task(int id) :mId(id) {
		std::cout << "Task::Constructor" << std::endl;
	}
	~Task() {
		std::cout << "Task::Destructor" << std::endl;
	}
};

int main()
{
	// 空对象 unique_ptr
	std::unique_ptr<int> ptr1;

	// 检查 ptr1 是否为空
	if (!ptr1)
		std::cout << "ptr1 is empty" << std::endl;

	// 检查 ptr1 是否为空
	if (ptr1 == nullptr)
		std::cout << "ptr1 is empty" << std::endl;

	// 不能通过赋值初始化unique_ptr
	// std::unique_ptr<Task> taskPtr2 = new Task(); // Compile Error

	// 通过原始指针创建 unique_ptr
	std::unique_ptr<Task> taskPtr(new Task(23));

	// 检查 taskPtr 是否为空
	if (taskPtr != nullptr)
		std::cout << "taskPtr is  not empty" << std::endl;

	// 访问 unique_ptr关联指针的成员
	std::cout << taskPtr->mId << std::endl;

	std::cout << "Reset the taskPtr" << std::endl;
	// 重置 unique_ptr 为空，将删除关联的原始指针
	taskPtr.reset();

	// 检查是否为空 / 检查有没有关联的原始指针
	if (taskPtr == nullptr)
		std::cout << "taskPtr is  empty" << std::endl;

	// 通过原始指针创建 unique_ptr
	std::unique_ptr<Task> taskPtr2(new Task(55));

	if (taskPtr2 != nullptr)
		std::cout << "taskPtr2 is  not empty" << std::endl;

	// unique_ptr 对象不能复制
	//taskPtr = taskPtr2; //compile error
	//std::unique_ptr<Task> taskPtr3 = taskPtr2;

	{
		// 转移所有权（把unique_ptr中的指针转移到另一个unique_ptr中）
		std::unique_ptr<Task> taskPtr4 = std::move(taskPtr2);
		// 转移后为空
		if (taskPtr2 == nullptr)
			std::cout << "taskPtr2 is  empty" << std::endl;
		// 转进来后非空
		if (taskPtr4 != nullptr)
			std::cout << "taskPtr4 is not empty" << std::endl;

		std::cout << taskPtr4->mId << std::endl;

		//taskPtr4 超出下面这个括号的作用于将delete其关联的指针
	}

	std::unique_ptr<Task> taskPtr5(new Task(66));

	if (taskPtr5 != nullptr)
		std::cout << "taskPtr5 is not empty" << std::endl;

	// 释放所有权   释放该对象的所有权，将其返回给普通指针，普通指针将由用户自行释放
	Task * ptr = taskPtr5.release();

	if (taskPtr5 == nullptr)
		std::cout << "taskPtr5 is empty" << std::endl;

	std::cout << ptr->mId << std::endl;

	delete ptr;
	
	return 0;
}
#endif