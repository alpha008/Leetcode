

/**********************************************************************************************************
13.2 Maximum Subarray
描述
Find the contiguous subarray within an array (containing at least one number) which has the largest
sum.
For example, given the array [−2,1,−3,4,−1,2,1,−5,4], the contiguous subarray [4,−1,2,1] has
the largest sum = 6.   
**********************************************************************************************************/

class Solution{
public:
    int maxSubArray(int A[], int n){
        int result = INT_MIN, f = 0;
        for(int i = 0;i < n ; i++){
            f = max(f + A[i], A[i]); //连续和 ? 当前值
            result = max(result, f); //更新结果
        }
        return result;
    }
    
};


/**********************************************************************************************************
描述
Given a triangle, find the minimum path sum from top to boom. Each step you may move to adjacent
numbers on the row below.
For example, given the following triangle
[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]
e minimum path sum from top to boom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note: Bonus point if you are able to do this using only O(n) extra space, where n is the total number
of rows in the triangle.      
**********************************************************************************************************/



class Solution{
public:
    int minimum(vector<vector<int>> & triangle){
        for(int i = triangle.size() - 2; i >=0; i--){
            for(int j = 0;j < triangle[i].size(); j++){
                triangle[i][j] = min(triangle[i + 1][j] , triangle[i + 1][j + 1]);
            }
        } 
        return triangle[0][0];
    }

};
















