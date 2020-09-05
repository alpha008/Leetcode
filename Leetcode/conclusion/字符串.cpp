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






