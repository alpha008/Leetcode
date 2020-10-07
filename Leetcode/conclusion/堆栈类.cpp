#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<deque>
#include<stack>
using namespace std;
/**********************************************************************************************************
1. 判断输入的括号是否有效
2. 最长有效括号
**********************************************************************************************************/
/**********************************************************************************************************
1. 判断输入的括号是否有效
Given a string containing just the characters ’(’, ’)’, ’{’, ’}’, ’[’ and ’]’, determine if the input string is valid.
 brackets must close in the correct order, ”()” and ”()[]” are all valid but ”(]” and ”([)]” are not.
**********************************************************************************************************/
bool isValid(string const &s){
    string left = "([{";
    string right = ")]}";
    stack<char> stk;// 栈    自动推导类型  auto
    for(auto c : s){
        if(left.find(c) != string::npos){ // string没找到是会返回string::npos
            stk.push(c);
        }else{
            if(stk.empty() || stk.top() != left[right.find(c)])
                return false;
            else
                stk.pop();   
        }
    }
    return stk.empty();
}
/**********************************************************************************************************
2. 最长有效括号
Given a string containing just the characters ’(’ and ’)’, find the length of the longest valid (wellformed) 
parentheses substring.
For ”(()”, the longest valid parentheses substring is ”()”, which has length = 2.
Another example is ”)()())”, where the longest valid parentheses substring is ”()()”, which has length = 4.
**********************************************************************************************************/
int longestValidParentheses(string s){
    int res = 0, start = 0, n = s.size();
    stack<int > st;
    for(int i = 0;i < n;i++){
        if(s[i] == '(')
            st.push(i);
        else if(s[i] == ')'){
            if(st.empty()){
                start = i + 1;
            }else{
                st.pop();
                res = st.empty() ? max(res , i - start + 1) : max(res, i - st.top());   
            }
        }
    }
    return res;
}
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, start = 0, n = s.size();
        stack<int> st;
        for(int i = 0;  i < n ;i ++){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                if(st.empty()){
                    start = i + 1;
                }else{
                    st.pop();
                    res = st.empty() ? max(res, i -start + 1) : max(res , i - st.top());
                }
            }
        }
        return res;
    }
};
int main()
{
    //1. 判断输入的括号是否有效
    string str1 = "()[]{}";
    cout << "判断输入的括号是否有效 = " << isValid(str1) << endl;
    //2. 最长有效括号
    string str2 = ")()())";
    cout << "最长有效括号 = " << longestValidParentheses(str2) << endl;
    return 0;
}

