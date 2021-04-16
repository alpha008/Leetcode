/**************************************************************************************************

 *************************************************************************************************/

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

void printvector(vector<int>&nums)
{
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
    printvector(result);
	result = findtwoSum(nums, 9);
    printvector(result);
    //2. 
	return 0;
}




















