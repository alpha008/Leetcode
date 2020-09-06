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
    [1,3,5,6], 2 → 1
    [1,3,5,6], 7 → 4
    [1,3,5,6], 0 → 0
分析
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





















