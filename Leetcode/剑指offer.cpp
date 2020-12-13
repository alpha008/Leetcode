#include<iostream>
#include<stack>
#include<vector>
#include<map>
using namespace std;
#if 0

剑指 Offer 03. 数组中重复的数字 LCOF
#endif

//剑指 Offer 03. 数组中重复的数字
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        map<int, int> map1;
        for(int i = 0; i< nums.size(); i++){
            if(map1.count(nums[i]) > 0){
                return nums[i];
            }
            map1[nums[i]] = i;
        } 
        return 0;
    }
};
//剑指 Offer 04. 二维数组中的查找
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int m = matrix.size();
        int n = matrix.front().size();
        int row = m -1;
        int col = 0;
        while(row >=0 && col < n){
            if(matrix[row][col] < target){
                col++;
            }else if (matrix[row][col] > target){
                row--;
            }else{
                return true;
            }
        }
        return false;
    }
};

// 从前往后全是有序的
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix.front().size();
        int first = 0;
        int last = m*n;
        while(first < last){
            int mid = first + (last - first ) /2;
            int value = matrix[mid /n][mid % n];
            if(value == target){
                return true;
            }else if(value < target ){
                first = mid +1;
            }else{
                last = mid;
            }
        }
        return false;
    }
};
//剑指 Offer 05. 替换空格
class Solution {
public:
    string replaceSpace(string s) {
        string res = "";
        for(int i = 0; i< s.size(); i++){
            if(s[i] == ' ')
                res += "%20";
            else
                res +=s[i];
        }
        return res;
    }
};
// c语言风格
class Solution{
public:
    void replaceSpace(char *str, int length){
        if(str == NULL)  return;
        int countspace = 0;
        int oriLength = 0;
        int len = 0;
        for(int i = 0; str[i] !='\0';i++ ){
            oriLength ++;
            if(str[i] == ' ')
                countspace ++;
        }
        len  =  oriLength + 2*countspace;
        if(len + 1 > length)
            return;
        char * pstr1 = str + oriLength;
        char * pstr2 = str + len;
        while(pstr1 != pstr2){
            if(*pstr1 == ' ')
            {
                *pstr2--='0';
                *pstr2--='2';
                *pstr2--='%';
            }else{
                --pstr1;
            }

        }
    }
}; 
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
//剑指 Offer 06. 从尾到头打印链表
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        ListNode * p = head;
        stack<int> sk;
        if(head == NULL)  return res;
        while(p){
            sk.push(p->val);
            p = p->next;
        }
        while(!sk.empty()){
            res.push_back(sk.top());
            sk.pop();
        }
        return res;
    }
};
//剑指 Offer 09. 用两个栈实现队列
/*
两个栈实现队列，一个栈A放元素，一个栈B用来弹出
栈B为空，A的都弹过来到B；B不为空，就可以直接弹出来了*/
class CQueue {
public:
    CQueue() {
    }
    void appendTail(int value) {
        one.push(value);
    }
    
    int deleteHead() {
        if (two.empty()) {
            while(!one.empty()) {
                two.push(one.top());
                one.pop();
            }
        }
        if (two.empty())
            return -1;
        int res = two.top();
        two.pop();
        return res;       
    }
    stack<int> one;
    stack<int> two;
};
// 剑指 Offer 10- I. 斐波那契数列
class Solution {
public:
    int fib(int n) {
        if(n == 0)  return 0;
        if(n == 1)  return 1;
        int prev = 0;
        int cur = 1;
        for(int i = 1 ;i < n;i++){
            int temp = cur;
            cur = (prev + cur) % 1000000007;
            prev = temp;
        }    
        return cur;
    }
};

//剑指 Offer 10- II. 青蛙跳台阶问题
class Solution {
public:
    int numWays(int n) {
        int prev = 0;
        int cur = 1;
        for(int i = 1; i <= n ; ++i){
            int tmp = cur;
            cur = (prev + cur)%1000000007;
            prev = tmp;
        }
        return cur;
    }
};

//剑指 Offer 11. 旋转数组的最小数字

/*
初始化两个指针left，right分别指向数组首尾；
开始二分搜索，求mid，然后和right位置的数字进行比较；
若 nums[mid] 大于 nums[right]，则说明最小值在mid右侧，那么左边界left = mid + 1;
若 nums[mid] 小于 nums[right]，则说明最小值在mid左侧，那么右边界right = mid;
若 nums[mid] 等于 nums[right]，那么右边界左移，right --;*/
class Solution {
public:
     int minArray(vector<int> numbers) {
        int left = 0;
        int right = numbers.size() - 1;
        int mid;
        
        while(left < right){
            mid = left + (right - left)/2;
            if(numbers[mid] > numbers[right]){
                left = mid + 1;
            }else if(numbers[mid] > numbers[right]){
                right = mid;
            }else{
                right --;
            }
        }
        return numbers[left];
    }
};
// 剑指 Offer 12. 矩阵中的路径






















class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
         vector<int>B;
        for(int i = 0;i<A.size();i++){
            int sum = 1;
            for(int j = 0; j < i;j++){
                sum = sum *A[j];
            }
            for(int j = i + 1; j < A.size();j++){
                sum  = sum *A[j];
            }
            B.push_back(sum);
        }
        return B;
    }
};




void  main()
{

    system("pause");
}
