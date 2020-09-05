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