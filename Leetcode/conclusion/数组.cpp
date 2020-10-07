#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;
/**********************************************************************************************************
1. Two Sum
2. 删除数组中为target的元素
3. 删除数组中重复的元素，允许重复k次
4. 一个数字出现奇数次，其他出现偶数次
5. single element,appearce k  others
6. Search a 2D Matrix
7. 在数组中查找target的下标的区间
8. Sum Closest
9. Search Insert Position
10. 乱序数组，找到第一个消失的正数
11. 删除数组中重复的数字
**********************************************************************************************************/
void printmatrix(const vector<vector<int>>& matrix)
{
    cout<< "printmatrix: " <<endl ;
    const size_t m = matrix.size();
    const size_t n = matrix.front().size();
    for (int i = 0;i < m ;i ++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << "  " ;
        }
        cout << endl;
    }
    cout << endl;
}
void printvector(vector<int>&nums)
{
    cout<< "printvector: " ;
    for (auto i : nums)
	{
		cout << i << " " ;
	}
    cout << endl;
}
/**********************************************************************************************************
1. Two Sum
假设解唯一，并且元素没有重复
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1    ] = 2 + 7 = 9,
return [0, 1]. 使用哈希表进行缓存，降低时间复杂度
**********************************************************************************************************/
vector<int> findtwoSum(vector<int>& nums, int target) {
    unordered_map<int, int> indices;        // 哈希表无序
    for (int index = 0; index < nums.size(); index++) 
    {
        if (indices.find(target - nums[index]) != indices.end()) 
        {
            return { indices[target - nums[index]], index };
        }
        indices[nums[index]] = index;// value + index  根据值找下标
    }
    return {}; // 最后没找到返回空
}
/**********************************************************************************************************
2. 删除数组中为target的元素
Given an array and a value, remove all instances of that value in place and return the new length.
order of elements can be changed. It doesn’t matter what you leave beyond the new length
删除元素后需要调整数组大小，或者允许后面的值不动，在打印时，打印前index个
**********************************************************************************************************/
int removeElement(vector<int> &nums,int elem){
    cout << "removeElement start" << endl;
    int index = 0;
    for(int i = 0 ;i < nums.size();i++){
        if(nums[i] != elem){
            nums[index++] = nums[i];
        }
    }
    nums.resize(index);
    return index;
}
/**********************************************************************************************************
3. 删除数组中重复的元素，允许重复k次    
    删除元素后需要调整数组大小，或者允许后面的值不动，在打印时，打印前index个
**********************************************************************************************************/
void removekElement(vector<int> &nums,int k){
    cout << "removeElement 允许重复k次" << "k = " << k <<  endl;
    int index = 0;
    int count = 1;
    for(int i = 1 ;i < nums.size();i++){
        if(nums[i] != nums[index]){
            count = 1;  // 原地赋值
            nums[++index] = nums[i];  //前置++表达式的值，先加完然后在使用；最后index = 加之后的值
        }
        else{
            if(count < k) // 判断的是已经统计到的，就算当前相等，那也得统计完在说
            {
                count++;
                nums[++index] = nums[i];
            }
        }
    }
    nums.resize(index+1);
}
/**********************************************************************************************************
4. 一个数字出现奇数次，其他出现偶数次
    完全是数学问题，异或剩下的最后一个元素
**********************************************************************************************************/
int singleNumber(vector<int> nums){
    int x = nums[0];
    for(int index = 1;index < nums.size();index++){
        x ^= nums[index];
    }
    return x;
}
/**********************************************************************************************************
5. single element,appearce k  others
**********************************************************************************************************/
int singleNumber(vector<int> &nums,int k){
    const int W = sizeof(int) * 8;
    int count[W];
    fill_n(&count[0], W, 0); // 将该数组所有bit位置填充为0
    for(int i = 0 ;i < nums.size(); i++){
        for(int j = 0;j < W; j++){
            count[j] += (nums[i] >> j) & 0x1;
            count[j] %= k; //假如出现k次，那么这个bit位将会变成0
        }
    }
    int result = 0;
    for(int i = 0;i < W;i++){
        result += (count[i] << i);
    }
    return result;
}

/**********************************************************************************************************
6. Search a 2D Matrix
For example, Consider the following matrix:7.3 Search a 2D Matrix 117
[
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
]
Given target = 3, return true.
把一个长度为n的一维数组转化为 m*n 的二维数组 (m*n = n)后，那么原一维数组中下标为i的元素将出现在二维数组中的 [i/n][i%n]
画图看一下就好看多了，第i个，分配给，下面是按照列来分组的，[] [] [] [] [] [] [] [] 所以除以列
**********************************************************************************************************/
bool searchMatrix(const vector<vector<int>>& matrix ,int target){
    cout << "查找的元素: " << target << endl;
    const size_t m = matrix.size();
    const size_t n = matrix.front().size();
    int first = 0;
    int last = m * n;
    while(first < last){
        int mid = first + (last - first )/2;
        int value = matrix[mid /n ][mid %n];
        if(value == target)
            return true;
        else if(value < target)
            first = mid + 1;
        else
            last = mid;
    }
    return false;
}

/**********************************************************************************************************
7. 在数组中查找target的下标的区间
Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm’s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
For example, Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].
**********************************************************************************************************/
vector<int> searchRange(vector<int>nums, int target){
    cout << "searchRange: "<< "target "<<target << endl;
    //distance 计算两个迭代器之间的距离
    //lower_bound(起始地址，结束地址，要查找的数值) 返回的是数值 第一个出现的位置。
    //upper_bound(起始地址，结束地址，要查找的数值) 返回的是 第一个大于待查找数值 出现的位置。
    const int l = distance(nums.begin(), lower_bound(nums.begin(),nums.end() ,target));
    const int u = distance(nums.begin(), prev(upper_bound(nums.begin(), nums.end(), target)));
    if (nums[l] != target) // 说明没找到
        return vector<int>{-1, -1};//匿名对象
    else
        return vector<int>{l, u };
}

/**********************************************************************************************************
8. Sum Closest
描述
Given an array S of n integers, find three integers in S such that the sum is closest to a given number,
target. Return the sum of the three integers. You may assume that each input would have exactly one
solution.
For example, given array S = {-1 2 1 -4}, and target = 2.
e sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
分析
先排序，然后左右夹逼，复杂度 O(n2)。
**********************************************************************************************************/
vector<vector<int> > threeSumCloest(vector<int>& nums,int target){
    cout << "threeSumCloest : "<< " target = " << target <<endl;
    vector<vector<int>> result;
    if(nums.size() < 3)
        return result;
    sort(nums.begin(),nums.end());
    
    for(int i = 0; i < nums.size() - 2; i++)
    {
        int j = i + 1;
        int k = nums.size() - 1;
        if(i > 0 && nums[i] == nums[i-1])
            continue;
        while(j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < target)
            {
                j++;
            }
            else if(sum > target)
            {
                k--;
            }
            else
            {
                vector<int> temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                temp.push_back(nums[k]);
                result.push_back(temp);
                j++;
                k--;
                while(nums[j] == nums[j-1]  && j < k)
                {
                    j++;
                }
                while(nums[k] == nums[k+1]  && j < k)
                {
                    k--;
                }
            }
        }
    }
    return result;
}
/**********************************************************************************************************
9 .Search Insert Position
描述 按顺序排好的数组，找到插入的位置
Here are few examples.
    [1,3,5,6], 5 → 2
即 std::lower_bound()
**********************************************************************************************************/
int searchInsert(vector<int>nums,int target){
    int index = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
    cout <<"searchInsert: insert " << target <<" is  "<< index <<  endl; 
    return index;
}
/**********************************************************************************************************
10. 乱序数组，找到第一个消失的正数
Given an unsorted integer array, find the first missing positive integer.
For example, Given [1,2,0]      return 3
                   [3,4,-1,1]   return 2
本质上是桶排序 (bucket sort)，每当 A[i]!= i+1 的时候，将 A[i] 与 A[A[i]-1] 交换，直到无法
交换为止，终止条件是 A[i]== A[A[i]-1]。
**********************************************************************************************************/
// 当所有的元素都遍历完成时，能保证在数组大小范围内的元素都已经放在了该放的位置上
static void bucket_sort(vector<int>&nums){
    for(int i = 0; i < nums.size(); i++){
        while(nums[i] != i + 1){
            if(nums[i] <=0 || nums[i] > nums.size() || nums[i] == nums[nums[i] - 1])
                break;
            swap(nums[i], nums[nums[i] - 1]);  // 将其与该放的那个位置交换(nums[i] - 1)
        }
    }
}

int firstMissingPositive(vector<int>&nums){
    bucket_sort(nums);
    for(int i = 0;i < nums.size(); i++){
        if(nums[i] != (i + 1))
            return i + 1;     
    }
    return nums.size() + 1;
}
/**********************************************************************************************************
11. 删除数组中重复的数字  --- 数组是有序的
**********************************************************************************************************/
int  removeDumplicates(int A[],int n){
    int index = 0;
    for(int i=1;i<n;i++)
    {
        if(A[index] !=A[i]){
            A[++index] = A[i];
        }
    }
    return index+1;
}
/**********************************************************************************************************
12. 统计空字符并返回  ---
**********************************************************************************************************/
int removnullsting(string s1)
{
    int index = 0; 
    int num = 0;
    for(int i = 0; i < s1.length();i ++)
    {
        if(s1[i] !=' ')
        {
            s1[index++] = s1[i];
        }else{
            num++;
        }
    }
    return num;
}
/**********************************************************************************************************
13. plus one
**********************************************************************************************************/
class PlusOne{
public:
    vector<int> mPlusOne(vector<int> &digits){       
        add(digits,1);
        return digits;
    }
    void add (vector<int> &digits, int digit){
        int carry = digit;
        for(auto it  = digits.rbegin();it != digits.rend();it++){
              *it = *it +carry;
              carry = *it /10;  
              *it %=10;
        }
        if(carry > 0) digits.insert(digits.begin(),1);
    }
};
/**********************************************************************************************************
14. 爬楼梯  f(n) = f(n-1) + f(n-2)
**********************************************************************************************************/
class ClimbStairs{
public:
    int climbStairs(int n){
        if(n = 0 )
            return 0;
        int prev = 0;
        int cur = 1;
        for(int i = 1; i < n; i++){
            int temp = cur;      
            cur = prev + cur;  
            prev = temp;
        }
        return cur;
    }
};
//1. Two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map1;
        for(int i = 0;i< nums.size(); i++){
            if(map1.count(target - nums[i]) > 0){
                return {map1[nums[i]], i };
            }
            else{
                map1[nums[i]] = i;
            }
        }
        return {};
    }
};
//66. Plus One
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 0)  return {};
        int c = 1;
        for(int i = digits.size()-1; i >=0; i--)
        {
            int a  = digits[i] + c;
            digits[i] = a%10;
            c = a/10;
        }
        if(c > 0) 
            digits.insert(digits.begin(), c);
        return digits;
    }
};
//27. Remove Element
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i = 0; i < nums.size(); i ++){
            if(nums[i]!=val){
                nums[index++] = nums[i];
            }
        }
        return index ;
    }
};
//34. Find First and Last Position of Element in Sorted Array
/*
题目要求找到开始的索引和结束索引，所以就是C++的lower_bound和upper_bound。代码我觉得应该是要背下来的，
这两个函数只有一点不同，就是nums[mid]与target的判断，lower_bound倾向于找左边的元素，所以只有nums[mid] >= target时才移动左指针；
而upper_bound倾向于找右边的元素，所以当nums[mid] <= target就向右移动左指针了。
lower_bound返回的是开始的第一个满足条件的位置，而upper_bound返回的是第一个不满足条件的位置。所以，当两个相等的时候代表没有找到，
如果找到了的话，需要返回的是[left, right - 1].
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = lower_bound(nums, target);
        int high = upper_bound(nums, target);
        if (low == high) 
            return {-1, -1};
        else
            return {low, high - 1};
    }
    int lower_bound(vector<int>& nums, int target) {
        const int N = nums.size();
        // [l, r)
        int l = 0, r = N;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid; //右边界一直往左边压
            } else  {
                l = mid + 1;
            }
        }
        return l;
    } // 同样的查找方法，结束条件一直，统一返回l，为啥差别会这么大，有意思
    // 假设查找的元素为连续且相等      
    // 上面那个会一直往左边收缩，直到 l = r , 返回满足target的下标  
    // 下面这个会一直往右边收缩，直到 l = r , 返回满足下标的l，记第一个大于target的元素
    int upper_bound(vector<int>& nums, int target) {
        const int N = nums.size();
        // [l, r)
        int l = 0, r = N;
        while (l < r) {   // 返回的是第一个大于target的位置的下标
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) {
                l = mid + 1; //左边界一直往右边压
            } else {
                r = mid;
            }
        }
        return l;
    }
}; // 二分查找
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto low = lower_bound(nums.begin(), nums.end(), target);
        auto high = upper_bound(nums.begin(), nums.end(), target);
        if (low == high) return {-1, -1};
        return {low - nums.begin(), high - nums.begin() - 1};
    }
};
int main()
{  
    vector<int> result;
    vector<vector<int> > douberesult;
    //1. 找到和为sum的两个数字
	vector<int>nums = { 2, 7, 11, 15 }; 
    printvector(nums);
	result = findtwoSum(nums, 9);
    printvector(result);
    //2. 删除数组中为target的元素
    vector<int>nums2 = { 2, 7, 7, 7, 11, 15 }; 
    printvector(nums2);
    removeElement(nums2,7);
    printvector(nums2);
    // 3. 删除数组中重复元素，允许重复k次
    vector<int>nums3 = { 2, 7, 7, 7, 8, 8, 8, 8, 11, 15 }; 
    printvector(nums3);
    removekElement(nums3,2);
    printvector(nums3);
    // 4. 一个数字出现奇数次，其他出现偶数次
    vector<int>nums4 = { 2, 7,  7, 8,  8, 11, 11 };
    printvector(nums4);
    cout << "singleNumber: " << singleNumber(nums4) << " " << endl;
    // 5. single element,appearce k  others
    vector<int>nums5 = { 2, 2, 2, 7, 8, 8, 8 , 11, 11, 11 };
    cout << "k singleNumber: " << singleNumber(nums5,3) << " " << endl;
    // 6. Search a 2D Matrix
    vector<vector<int>> matrix = {{1, 3, 5, 7},{10, 11, 16, 20},{23, 30, 34, 50}}; 
    printmatrix(matrix);
    cout << "searchMatrix: " << searchMatrix(matrix,20) << " " << endl;
    // 7. 在数组中查找target的下标的区间
    vector<int>range = { 5, 7, 7, 8, 8, 10 }; 
    printvector(range);
    result = searchRange(range,8);
    printvector(result);
    // 8. three sum
    vector<int>nums8 = {-1 ,1 ,1, 2 ,2,-4}; 
    printvector(nums8);
    douberesult = threeSumCloest(nums8,2);
    printmatrix(douberesult);
    // 9. Search Insert Position
    vector<int>nums9 = { 1,3,5,6 }; 
    printvector(nums9);
    searchInsert(nums9,5);
    // 10. 乱序数组，找到第一个消失的正数
    vector<int>nums10 = {1,2,0,10,3,5}; 
    printvector(nums10);
    cout << "first missing positive is "<< firstMissingPositive(nums10) << endl;
	return 0;
}





















