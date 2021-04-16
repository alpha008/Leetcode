#include<iostream>
#include<vector>
#include<stack>
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
#if 0
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
#endif

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        /*快速排序
        int start = 0, end = nums.size() - 1;
        quick(nums, start , end);
        return nums;**/
        /*2. 归并排序*/
        vector<int>temp(nums.size(), 0);
        merge_sort(nums, temp, 0, nums.size()-1);
        return nums;
    }
    void merge_sort(vector<int>&nums, vector<int>& temp, int start, int end){
        int middle;
        if(start >= end)
            return ;
        middle = start + (end - start ) /2;
        merge_sort(nums, temp, start ,middle);
        merge_sort(nums, temp , middle+1, end);
        merge(nums, temp, start, middle, end);
        
    }
    void merge(vector<int>&nums, vector<int>& temp, int start, int middle, int end){
        int i = start , j = middle + 1, k = start;
        while(i <= middle && j <= end){
            if(nums[i] > nums[j]){
                temp[k++] = nums[j++];
            }else{
                temp[k++] = nums[i++];
            }
        }
        while(i <= middle ){
            temp[k++] = nums[i++];
        }
        while(j <= end){
            temp[k++] = nums[j++];
        }
        for(i = start; i <= end; i++){
            nums[i] = temp[i];
        }
    }
};  
#if 0
void test01(){
    //calBitPc();
    stack<int>s1;
    cout << "1" << s1.empty() <<endl;
    s1.push(1);
    cout << "2" << s1.empty() <<endl;
    int i = 1;
    cout << "i++ = " << i++ << endl;
    cout << "i = " << i << endl;
    Solution aa;
    cout << "result:" << aa.myAtoi("1234");
    cout << "sizeof(ListNode) = " << sizeof(ListNode) << endl;

}
#endif
int main()
{
    Solution aa;
    vector<int> nums = {4,8,9,5,6};
    aa.sortArray(nums);
    cout << "aa"<<endl;
    for (int i = 1;i < 5;i++ ){

        cout << "i =  " << i <<endl;
    }
    return 0;
}