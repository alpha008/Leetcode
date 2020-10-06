#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;
/**********************************************************************************************************
1. 判断是否是回文串
**********************************************************************************************************/
bool isPalindrome(string s){
    transform(s.begin(),s.end(),s.begin(),::tolower);  // 先将所有数字，转换为小写
    auto left = s.begin(),  right = prev(s.end());  //s.end()  是后面的那个位置
    while(left < right){
        if(!::isalnum(*left))  //如果是数字就跳过
            ++left;
        else if(!::isalnum(*right)) 
            --right;
        else if(*(left++) != *(right--)) 
            return false;
    }
    return true;
}
//2. 判断两个字符串是否互为变形词
bool isDeformation(string str1,string str2)
{
    map<int,int> mapcount ;
    for(int i = 0 ;i < str1.length();i++)
    {
        mapcount[str1[i]] ++;
    }
    for(int j = 0; j < str2.length(); j++)
    {
        if(--mapcount[str2[j]] < 0)
            return false;
    }
    return true;
}
//3. 58. Length of Last Word
#include<algorithm>
class Solution {
public:
    int lengthOfLastWord(string s) {
        #if 0
        auto first = find_if(s.rend(),s.rbegin(),::isalpha);
        auto last = find_if_not(first , s.rend(), ::isalpha);
        return distance(first,last);
        #endif
        int count = 0;
        for(int index = 0; index < s.size(); index ++){
            if(s[index] != ' '){
                count++;
            }
            else{
                count = 0;
            }
        }
        return count ;
    }
};
//4. 67. Add Binary
class Solution {
public:
    string addBinary(string a, string b) {

        int carry = 0;
        string result;     
        int indexa  = a.size() -1;
        int indexb  = b.size() -1;
        for(;indexa >=0 || indexb >=0 ;indexa--,indexb--)
        {
            int ai = indexa >= 0 ? a[indexa] - '0' : 0;
            int bi = indexb >= 0 ? b[indexb] - '0' : 0;    
            const int val = (ai + bi + carry) % 2;
            carry = (ai + bi + carry  ) / 2;
            result.insert(result.begin(),val + '0');
        }
        if(carry > 0)
            result.insert(result.begin(), '1');
        return result;
    }
};
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        int result = 0;
        if (s.length() == 0) return 0;

        //Discard whitespaces in the beginning
        while (i < s.length() && s[i] == ' ')
            i++;

        // Check if optional sign if it exists
        if (i < s.length() && (s[i] == '+' || s[i] == '-'))
            sign = (s[i++] == '-') ? -1 : 1;

        // Build the result and check for overflow/underflow condition
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            if (result > INT32_MAX / 10 ||   (result == INT32_MAX / 10 && s[i] - '0' > INT32_MAX % 10)) {
                return (sign == 1) ? INT32_MAX : INT32_MIN;
            }
            result = result * 10 + (s[i++] - '0');
        }
        return result * sign;
    }
};
//8. String to Integer (atoi)
class Solution {
public:
    int myAtoi(string s) {
        int num = 0;
        int sign = 1;
        const int n = s.size();
        int i = 0;
        while(s[i] == ' ' && i < n) i++;   // 首先排除空格
        if(s[i] == '+')  i++;
        if(s[i] == '-') {
            sign = -1;
            i++;
        }
        for(; i < n ; i++){
            if(s[i] < '0' || s[i] > '9')
                break;
                //# define INT32_MAX		(2147483647)
            // 判断是否存在进位，当出现高位和进位两种情况同时进位越界，那么就返回结果
            if(num > INT32_MAX / 10  || (num = INT32_MAX / 10  && (s[i] - '0') > INT32_MAX %10)){
                return sign = -1 ? INT32_MIN :INT32_MAX;
            }
            
            num = num * 10 + s[i] - '0';
        }
        return num*sign;
    }
};

char *Strcpy(char *des, char *src)
{
    if (des == NULL || src == NULL)
        return NULL;
    char *tem = des;//定义一个指针tem保存字符串首元素地址
    while (*src != '\0')//复制字符串有效字符，遇到\0结束
    {
        *des= *src;//把arr的值给sub
        des++;//每复制一次sub往后移一个
        src++;//arr也往后移一个
    }
    *des = '\0';//循环过程没有复制\0,所以循环结束后给sub所指的字符串赋\0
    return tem;//返回字符串地址
}
void* my_memcpy(void* dst,const void*src,size_t count)
{
    if(src == NULL || src == NULL)
        return NULL;
    char *pdst = (char*)dst;
    char *psrc = (char*)src;
    size_t i;
    if((dst > src)&&(dst < src + count))  //内存重叠，从高地址拷贝
    {
        for(i = count-1 ;i!=-1;--i)
        {
            pdst[i] = psrc[i];
        }
    }
    else//内存不重叠
    {
        for(i = 0; i < count; i++)
        {
            pdst[i] = psrc[i];
        }
        return dst;
    }
}

int main()
{
    //1. 判断一个字符串是否是回文串，标点符号不算
    string  str1 = "A man, a plan, a canal: Panama";
    cout << "isPalindrome result = " << isPalindrome(str1) << endl;
    //2.  判断两个字符串是否互为变形词
    string str2 = "123";
    string str3 = "3221";
    cout << "isDeformation: " << isDeformation(str2,str3)<< endl;
    return 0;
}

