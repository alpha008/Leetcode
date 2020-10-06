#include<iostream>
using namespace std;

class ListNode {
public:
    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }
    int val;
    ListNode *next;
};
int calBitPc()
{
    int num = 0;
    int a = 0;
    printf("a = %d\n",a);
    #if 0
    if(a = )
    {
        printf("computer is %d\n",a);
    }
    #endif
    return num;
}
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
            if(num > INT32_MAX / 10  || (num == INT32_MAX / 10  && (s[i] - '0') > INT32_MAX %10)){
                return sign == -1 ? INT32_MIN :INT32_MAX;
            }       
            cout <<"1"  << num *10 << endl;
            cout <<"1"  <<s[i] - '0' << endl;    
            num = num * 10 + s[i] - '0';
        }
        return num*sign;
    }
};
int main()
{
    //calBitPc();
    int i = 1;
    cout << "i++ = " << i++ << endl;
    cout << "i = " << i << endl;
    Solution aa;
    cout << "result:" << aa.myAtoi("1234");
    cout << "sizeof(ListNode) = " << sizeof(ListNode) << endl;
    return 0;
}