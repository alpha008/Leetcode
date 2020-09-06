#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>
using namespace std;

#if 0



/**********************************************************************************************************
3Sum Closest
描述
Given an array S of n integers, find three integers in S such that the sum is closest to a given number,
target. Return the sum of the three integers. You may assume that each input would have exactly one
solution.
For example, given array S = {-1 2 1 -4}, and target = 1.
e sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
分析
先排序，然后左右夹逼，复杂度 O(n2)。

**********************************************************************************************************/


class Solution{
public:
       int threeSumCloest(vector<int>& num,int target){
            int result = 0;
            int min_gap = INT_MAX;
            sort(num.begin(),num.end());
            for(auto a = num.begin();a !=prev(num.end(),2); a = upper_bound(a,prev(num.end()),*a){
                auto b = next(a);
                auto c = prev(num.end());
                while(b < c){
                    const int sum = *a + *b + *c;
                    const int gap = abs(sum - target);
                    if(gap < min_gap ) {
                        result = sum ;
                        min_gap = gap;
                    }
                    if(sum < target){
                        b = upper_bound(b, c, *b);
                    }
                    else{
                        c = prev(lower_bound(b, c, *c));
                    }       
                }
            }
            return result;
    


/**********************************************************************************************************
描述
Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm’s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
For example, Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].
分析
已经排好了序，用二分查找

**********************************************************************************************************/

class Solution{
public:
    vector<int> searchRange(int A[], int n, int target){
        const int l = distance(A, lower_bound(A, A + n ,target));
        const int u = distance(A, prev(upper_bound(A, A +n, target)));
        if (A[l] != target)
            return vector<int>{-1, -1};
        else
            return vector<int>{l, u };
    }
};



/**********************************************************************************************************
7.2 Search Insert Position
描述
Given a sorted array and a target value, return the index if the target is found. If not, return the index
where it would be if it were inserted in order.
You may assume no duplicates in the array.
Here are few examples.
    [1,3,5,6], 5 → 2
    [1,3,5,6], 2 → 1
    [1,3,5,6], 7 → 4
    [1,3,5,6], 0 → 0
分析
即 std::lower_bound()
**********************************************************************************************************/
class Solution{
public:
    int searchInsert(int A[],int n ,int target){
        return lower_bound(A,A + n,target) - A;
    }
};


/**********************************************************************************************************
7.3 Search a 2D Matrix
描述
Write an efficient algorithm that searches for a value in an m×n matrix. is matrix has the following
properties:
• Integers in each row are sorted from le to right.
• e first integer of each row is greater than the last integer of the previous row.
For example, Consider the following matrix:7.3 Search a 2D Matrix 117
[
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
]
Given target = 3, return true.
**********************************************************************************************************/



class Solution{
public:
    bool searchMatrix(const vecotr<vector<int>>& matrix ,int target){
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
};




/**********************************************************************************************************
3Sum Closest
描述
Given an array S of n integers, find three integers in S such that the sum is closest to a given number,
target. Return the sum of the three integers. You may assume that each input would have exactly one
solution.
For example, given array S = {-1 2 1 -4}, and target = 1.
e sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
分析
先排序，然后左右夹逼，复杂度 O(n2)。

**********************************************************************************************************/
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution{
public:
       int threeSumCloest(vector<int>& num,int target){
            int result = 0;
            int min_gap = INT_MAX;
            sort(num.begin(),num.end());
            for(auto a = num.begin();a !=prev(num.end(),2); a = upper_bound(a,prev(num.end()),*a){
                auto b = next(a);
                auto c = prev(num.end());
                while(b < c){
                    const int sum = *a + *b + *c;
                    const int gap = abs(sum - target);
                    if(gap < min_gap ) {
                        result = sum ;
                        min_gap = gap;
                    }
                    if(sum < target){
                        b = upper_bound(b, c, *b);
                    }
                    else{
                        c = prev(lower_bound(b, c, *c));
                    }       
                }
            }
            return result;
       }
};




/**********************************************************************************************************
Given an unsorted integer array, find the first missing positive integer.
For example, Given [1,2,0] return 3, and [3,4,-1,1] return 2

本质上是桶排序 (bucket sort)，每当 A[i]!= i+1 的时候，将 A[i] 与 A[A[i]-1] 交换，直到无法
交换为止，终止条件是 A[i]== A[A[i]-1]。


**********************************************************************************************************/
class Solution{
public:
    int firstMissingPositive(int A[],int n){
        bucker_sort(A, n);
        for(int i = 0;i < n; i++){
            if(A[i] != (i + 1))
                return i + 1;
            return n + 1；
        }
    }
private:
    static void bucket_sort(int A[], int n){
        for(int i = 0; i < n; i++){
            while(A[i] != i + 1){
                if(A[i] <=0 || A[i] > n || A[i] == A[A[i] - 1])
                    break;
                swap(A[i], A[A[i] - 1]);
            }
        }
    }
};





#endif
/**********************************************************************************************************
1. Two Sum
2. 删除数组中为target的元素
3. 删除数组中重复的元素，允许重复k次
4. 一个数字出现奇数次，其他出现偶数次
5. single element,appearce k  others
**********************************************************************************************************/
/**********************************************************************************************************
1. Two Sum
假设解唯一，并且元素没有重复
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
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
void printvector(vector<int>&nums)
{
    cout<< "printvector: " ;
    for (auto i : nums)
	{
		cout << i << " " ;
	}
    cout << endl;
}
int main()
{  
    vector<int> result;
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
    


	return 0;
}





















