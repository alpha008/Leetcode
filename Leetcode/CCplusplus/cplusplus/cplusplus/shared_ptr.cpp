#include<iostream>
#include<memory>
#include<string>
using namespace std;
#if 0
struct Person:enable_shared_from_this<Person>
{
public:
	~Person(){
		cout << "析构函数" << endl;
	}
	void show()
	{
		cout << str << endl;
	}
	shared_ptr<Person> getShare(){
		return shared_from_this(); //将本对象返回出去
	}
	string str;
};

void main()
{
	{
		shared_ptr<Person> ptr2;
		shared_ptr<Person> ptr(new Person);
		ptr->str = "hello";
		cout << ptr.use_count() << endl;
		ptr2 = ptr->getShare(); //ptr指向了该对象，然后赋值给ptr2,但是ptr2的计数没有+1
		ptr2->show();
	}

	system("pause");
}
#elif 0
struct Good : std::enable_shared_from_this<Good> // 注意：继承
{
public:
	std::shared_ptr<Good> getptr() {
		return shared_from_this();
	}
	~Good() { std::cout << "Good::~Good() called" << std::endl; }
};

int main()
{
	// 大括号用于限制作用域，这样智能指针就能在system("pause")之前析构
	{
		std::shared_ptr<Good> gp1(new Good());
		std::shared_ptr<Good> gp2 = gp1->getptr();
		// 打印gp1和gp2的引用计数
		std::cout << "gp1.use_count() = " << gp1.use_count() << std::endl;
		std::cout << "gp2.use_count() = " << gp2.use_count() << std::endl;
	}
	system("pause");
}
#elif 0
//声明周期的托管 给智能指针来实现
template <typename T>
class UniquePoint{
public:
	using Pointer = T*;
	using Reference = T&;
	UniquePoint() :ptr_ ( nullptr){}
	UniquePoint(Pointer ptr) :ptr_(ptr){}
	UniquePoint(UniquePoint && other)
		:ptr(other.ptr_){
		other.ptr_ = nullptr;
	}
	UniquePoint& operator=(UniquePoint &&other){
		ptr_ = other.ptr_;
		return *this;
	}
	UniquePoint(const UniquePoint&) = delete;
	UniquePoint& operator=(const UniquePoint&) = delete;
	operator bool(){
		return ptr_ != nullptr;
	}
	Pointer get(){
		return ptr_;
	}
	Reference operator*(){
		return *ptr_;
	}
	void reset(Pointer ptr = nullptr){
		if (ptr_ != nullptr){
			delete ptr_;
		}
		ptr_ = ptr;
	}
	~UniquePoint(){
		if (ptr_ != nullptr)
			delete ptr_;
	}

private:
	Pointer ptr_;
};
struct  Demo
{
	~Demo()
	{
		cout << "析构函数" << '\n';
	}
};
void main()
{

	UniquePoint<Demo> ptr;
	if (!ptr){
		cout << "ptr为空" << endl;
	}
	UniquePoint<string> ptr1(new string("hello"));
	cout << "返回该对象的引用  " <<ptr1.get()->c_str();



	system("pause");
}
#endif