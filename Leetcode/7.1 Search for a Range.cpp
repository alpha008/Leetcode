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




