#include<iostream>
using namespace std;
class BaseA{
public:
    BaseA(){
        function();
    }
    virtual void function()
    {
        cout << "BaseA:function()" << endl;
    }
};
class A :public BaseA{
public:
    A(){ function();}
    virtual void function()
    {
        cout << "A: function()" << endl;
    }
};
class BaseB{
public:
    virtual void show()
    {
        cout << "in BaseB"<<endl;
    }
    ~BaseB()
    {
        show();
    }
};
class B:public BaseB{
public:
    virtual void show()
    {
        cout << "in B" <<endl;
    }
};
int main()
{
    A a;
    BaseB base;
    B b;
    return 0;
}
// 基类与派生类 创建过程中构造函数的调用关系以及虚函数调用关系
// 在释放时，析构函数的调用关系  以及为什么
// new  delete   malloc  free 关系
// int 32 :  8 
// 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
//  16  = NumInt
//  3亿  = 16 * NumInt
     int *p  =  new int(sizeof(int)*(3000000000/16)); // 715M
//715M可表示3亿个数字