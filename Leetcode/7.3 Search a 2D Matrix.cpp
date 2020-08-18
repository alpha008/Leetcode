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




