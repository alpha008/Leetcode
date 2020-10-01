#include<iostream>
#include<vector>
#include<string.h>

int main()
{

    return 0;
}


//一个字符类型的对象的各种函数
//主要是关系到内存的申请拷贝比较关键
class String{
public:
    String(const char *str = NULL);//普通构造函数
    String(const String &other);//拷贝构造函数 + 重载=运算符
    ~String();
    String &operator= (const String &other);
private:
    char *m_data;
};
String::String(const char *str = NULL)
{
    if(str == NULL){
        m_data = new char[1];
        *m_data = '\0';//c风格的字符串，需要结束符号
    }
    else{
        int len = strlen(str);
        m_data = new char[len+1];
        strcpy(m_data,str);
    }
}
String::String(const String &other){
    int len = strlen(other.m_data);
    m_data = new char[len+1];
    strcpy(m_data,other.m_data);
}
String::~String(){
    delete []m_data;
}
String& String::operator=(const String &other){
    if(&other == this){
        return *this;
    }
    delete []m_data;
    int len = strlen(other.m_data);
    m_data = new char[len+1];
    strcpy(m_data,other.m_data);
    return *this;
}