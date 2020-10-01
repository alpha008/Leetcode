#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std; 

string del_space(string *str) {
    string::iterator it = (*str).begin();
    while ((it = find(it, (*str).end(), ' ')) != (*str).end())
    {
        (*str).erase(it);
        if (it == (*str).end())
            break;
    }
    return *str;
}
int main()
{
	char*src = "hello,world"; 
	int len = strlen(src); 
	char* dest = (char*)malloc((len+1)*sizeof(char));    //要为\0分配一个空间
	char* d = dest; 
	char* s = &src[len-1];     //指向最后一个字符
	while(len--!=0) 
	{
		*d++ = *s--;
	}
	*d = '\0';     //尾部要加\0     
	printf("%s\n",dest);           
	free(dest);
	return 0; 
} 