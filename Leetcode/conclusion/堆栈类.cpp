/**********************************************************************************************************
描述
Given a string containing just the characters ’(’, ’)’, ’{’, ’}’, ’[’ and ’]’, determine if the
input string is valid.
e brackets must close in the correct order, ”()” and ”()[]” are all valid but ”(]” and ”([)]” are
not.

**********************************************************************************************************/
class Solution{
public:
        bool isValid(string const &s){
            string left = "([{";
            string right = ")]}";
            stack<char> stk;
            for(auto c : s){
                if(left.find(c) != string::npos){
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

};

/**********************************************************************************************************
Given a string containing just the characters ’(’ and ’)’, find the length of the longest valid (wellformed) 
parentheses substring.
For ”(()”, the longest valid parentheses substring is ”()”, which has length = 2.
Another example is ”)()())”, where the longest valid parentheses substring is ”()()”, which has
length = 4.

**********************************************************************************************************/


class Solution{
public:
    int longestValidParentheses(string s){
        int res = 0, start = 0, n = s.size();
        stack<int > st;
        for(int i = 0;i < n;i++){
            if(s[i] = '(')
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

};



/**********************************************************************************************************
Given n non-negative integers representing the histogram’s bar height where the width of each bar is
1, find the area of largest rectangle in the histogram.

图 4-1 Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3]

图 4-2 the largest rectangle is shown in the shaded area, which has area = 10 unit.
For example, Given height = [2,1,5,6,2,3], return 10


**********************************************************************************************************/
class Solution{
public:
    int largestRectangleArea(vector<int>& height){
        stack<int > s;
        height.push_back(0);
        int result = 0;
        for(int i = 0; i < height.size();){
            if(s.empty() || height[i] > height[s.top()])
                s.push(i++);
            else{
                int tmp = s.top();
                s.pop();
                result = max(result, height[tmp] * (s.empty() ? i : i - s.top() - -1));
            }
        }
        return result;
    }
};



