

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


