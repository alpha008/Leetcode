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