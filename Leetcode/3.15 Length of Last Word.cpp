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






