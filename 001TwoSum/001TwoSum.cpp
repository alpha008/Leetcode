/**********************************************************************************************************
1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
**********************************************************************************************************/
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution1 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> indices;
		for (int i = 0; i < nums.size(); i++) 
		{
			if (indices.find(target - nums[i]) != indices.end()) 
			{
				return{ indices[target - nums[i]], i };
			}
			indices[nums[i]] = i;
		}
		return{};
	}
};
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
int main()
{
	vector<int>nums = { 2, 7, 11, 15 };
	int target = 9;
	Solution1 a;
	vector<int>nums1=a.twoSum(nums, target);
	for (auto i : nums1)
	{
		cout << i;
	}
	return 0;
}




























