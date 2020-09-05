/**********************************************************************************************************
3.1 Valid Palindrome

描述
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring
cases.
For example,
”A man, a plan, a canal: Panama” is a palindrome.
”race a car” is not a palindrome.
Note: Have you consider that the string might be empty? is is a good question to ask during an
interview.
For the purpose of this problem, we define empty string as valid palindrome   
**********************************************************************************************************/
class Solution{
public:
    bool isPalindrome(string s){
        tranform(s.begin(),s.end(),s.begin(),::tolower);
        auto left = s.begin(), right = prev(s.end());
        while(left < right){
            if(!::isalnum(*left)) ++left;
            else if(!::isalnum(*right)) ++right;
            else if(*left != *right) return false;
        }
        return true;
    }
};