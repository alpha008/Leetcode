#include<stdio.h>
#include<string.h>

#include<time.h>
#include<sys/time.h>
typedef struct redisObject{
    char type :2; //两个bit位置只能存储到0-3
    char encoding :2;
    char lru:5;
}robj;
// 把单个结构体占用的内存用到了极致

void test01()
{
    robj obj;
    memset(&obj, 0, sizeof(robj));
    obj.type = 0;
    printf("obj.type = %d\n",obj.type);
    printf("sizeof(obj) = %d\n",sizeof(robj));
}
void test02()
{
    struct timeval tv;
    struct tm *ptm;
    char time_str[128];
    gettimeofday(&tv, NULL);
    ptm = localtime(&tv.tv_sec);//把从1970-1-1零点零分到当前时间系统所偏移的秒数时间转换为本地时间
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", ptm);
    printf("time_str = %s\n",time_str);
}
int  main()
{
    test02();
    return 0;
}