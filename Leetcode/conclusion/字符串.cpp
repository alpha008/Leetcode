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

