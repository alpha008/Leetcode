/**********************************************************************************************************
1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
如果有顺序的话，那么就可以两头指针往中间靠
**********************************************************************************************************/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> indices;
		for (int i = 0; i < nums.size(); i++) 
		{
			if (indices.find(target - nums[i]) != indices.end()) 
			{
				return { indices[target - nums[i]], i };
			}
			indices[nums[i]] = i;// value + index  根据值找下标
		}
		return {}; // 最后没找到返回空
	}
};
int main()
{
	vector<int>nums = { 2, 7, 11, 15 };
	int target = 9;
	Solution1 a;
	vector<int>nums1 = a.twoSum(nums, target);
	for (auto i : nums1)
	{
		cout << i;
	}
	return 0;
}







class Solution2 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i) {
			m[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); ++i) {
			int t = target - nums[i];
			if (m.count(t) && m[t] != i) {
				res.push_back(i);
				res.push_back(m[t]);
				break;
			}
		}
		return res;
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
#include<vector>
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
Given an array and a value, remove all instances of that value in place and return the new length.
e order of elements can be changed. It doesn’t matter what you leave beyond the new length.


**********************************************************************************************************/



#include<iostream>
#include<unordered_map>
using namespace std;

class Solution{
    int removeElement(int A[],int n,int elem){
        int index = 0;
        for(int i = 0 ;i < n;i++){
            if(A[i] != elem){
                A[index++] = A[i];
            }
        }
        return index;
    }

}












/**********************************************************************************************************
Given an array of integers, every element appears twice except for one. Find that single one.
Note: Your algorithm should have a linear runtime complexity. Could you implement it without using
extra memory? 
**********************************************************************************************************/
#include<iostream>
#include<algorithm>
using namespace std;

class Solution{
public:
    int singleNumber(int A[], int n ){
        int x = A[0];
        for(int i = 1;i < n;i ++){
            x ^= A[i];
        }
        return x;
    }

};


class Solution{
    int singleNumber(int A [ ], int n,int k){
        const int W = sizeof(int) * 8;
        int count[W];
        fill_n(&count[0], W, 0);
        for(int i = 0;i  < n; i++){
            for(int j = 0;j < W; j++){
                count[j] += (A[i] >> j) & 1;
                count[j] % = k;//统计出现k次的
            }
        }
        int result = 0;
        for(int i = 0;i < W;i++){
            result +=(count[i] << i);
        }
        return result;
    }

};

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
Given two sorted integer arrays A and B, merge B into A as one sorted array.
Note: You may assume that A has enough space to hold additional elements from B. e number of
elements initialized in A and B are m and n respectively

**********************************************************************************************************/

class Solution{
public:
    void merge(int A[],int m,int B[], int n){
        int ia = m - 1, ib = n - 1, icur = m + n - 1;
        while(ia >=0 && ib >=0){
            A[icur--] = A[ia] >= B[ib] ? A[ia--] : B[ib--];
        }
        while(ib >= 0){
            A[icur--] = B[ib--];
        }
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


















