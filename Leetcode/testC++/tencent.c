#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int reversestring()
{
    char *src = "hello,word"; // 栈指针  指向  字符串常量区
    int len = strlen(src);
    printf("strlen = %d\n",strlen(src));
    char * dest = (char *)malloc(sizeof(char) *(len+1));
    char *d = dest;
    char *s = &src[len-1];
    while(len--)
    {
        *d++ = *s--;
    }
    *d = '\0';
    printf("dest = %s\n",dest);
    free(dest); //malloc申请的空间，需要手动释放
}
// 栈空间   字符常量区   堆区  栈区    strlen 计算字符长度没有计算末尾的'\0'  在拷贝过程中，需要多申请一个字节大小空间补上'\0'
// 堆往高地址生长    栈往低地址生长
int main()
{
    //reversestring();
    return 0;
}

