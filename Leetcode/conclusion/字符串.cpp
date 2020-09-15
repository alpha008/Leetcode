#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <deque>
using namespace std;

/**********************************************************************************************************

**********************************************************************************************************/

#if 0
/**********************************************************************************************************
Given a string S, find the longest palindromic substring in S. You may assume that the maximum
length of S is 1000, and there exists one unique longest palindromic substring

**********************************************************************************************************/
class Solution{
public:
    string longestPalindrome(string s){
        const int n = s.size();
        boot f[n][n];
        fill_n(&f[0][0], n *n ,false);
        size_t max_len = 1, start = 0;
        for(size_t i = 0; i < s.size(); i++){
            f[i][i] = true;
            for(int j = 0;j < i;j++){
                f[j][i] = (s[j] == s[i] &&(i - j < 2 || f[j + 1][i - 1]));
                if(f[j][i] && max_len < (i - j + 1)){
                    max_len = i - j + 1;
                    start = j;
                }
            }
        }
        return s.substr(start , max_len);
    }
};

/**********************************************************************************************************
描述
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the
length of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.
For example, Given s = "Hello World", return 5.
**********************************************************************************************************/



class Solution{
public:
        int lengthOfLastWord(const char *s){
            const string str(s);
            auto first = first_if(str.rbegin(), str.rend(); ::isalpha);
            auto last = first_if_not(first , str.rend(), ::isalpha);
            return distance(first, last);
        }
};

class Solution{
public:
    int LengthofLastWorld(string str)
    {
        int res = 0;
        int length = str.size();
        int i = 0;
        int lastspaceindex = 0;
        while (i<length)
        {
            if (str[i] == ' ')
                lastspaceindex = i;
            i++;
        }
        return length - lastspaceindex - 1;
    }
};




class Solution{
public:
    int lengthOfLastWord(const char * s){
        int len = 0;
        while(*s){
            if(*s++!=' ')
                 ++len;
            else if(*s && *s !=' ')
                 len = 0;
        }
        return len;
    }
};

#endif
/**********************************************************************************************************
1. 判断是否是回文串
描述
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
For example,
”A man, a plan, a canal: Panama” is a palindrome.
”race a car” is not a palindrome.
 void isalnum(int c) 检查所传的字符是否是字母和数字。  如果是返回真   如果不是返回0
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
/**********************************************************************************************************
2. 判断两个字符串是否互为变形词
   两个字符串出现的字母及次数一样
**********************************************************************************************************/
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

