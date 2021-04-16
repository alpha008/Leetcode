
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<deque>
using namespace std;
/**********************************************************************************************************
1. 最长公共子序列
2. 最长公共子串
3. 最大连续子数组
4. 最长递增子序列
5. 最短路径和
6. Triangle
**********************************************************************************************************/

/**********************************************************************************************************
1. 最长公共子序列
动态规划
L C S ( m , n ) LCS(m ,n)LCS(m,n)表示S 1 [ 0... m ] S1[0...m]S1[0...m]和S 2 [ 0... n ] S2[0...n]S2[0...n]的最长公共子序列的长度
S 1 [ m ] = = S 2 [ n ] : L C S ( m , n ) = 1 + L C S ( m − 1 , n − 1 ) S1[m] == S2[n]: LCS(m, n) = 1 + LCS(m - 1, n - 1)S1[m]==S2[n]:LCS(m,n)=1+LCS(m−1,n−1)
S 1 [ m ] ! = S 2 [ n ] : L C S ( m , n ) = m a x ( L C S ( m − 1 , n ) , L C S ( m , n − 1 ) ) S1[m] != S2[n]: LCS(m, n) = max(LCS(m - 1, n), LCS(m, n - 1))S1[m]!=S2[n]:LCS(m,n)=max(LCS(m−1,n),LCS(m,n−1))
恢复路径：
dp[i-1,j-1]  dp[i-1,j]
dp[i,  j-1]  dp[i,  j]

dp[i,j] >  dp[i-1,j] && dp[i,j] >  dp[i,  j-1] ----> 向左上方移动
dp[i,j] =  dp[i,  j-1] 向上移动
dp[i,j] =  dp[i-1,j]   向左移动
dp[i,j] =  dp[i,  j-1] = dp[i-1,j]   哪个方向都可以

2. 最大公共子串

**********************************************************************************************************/
class Solution{
public:
//1. 最长公共子序列
    int lengthOflongestCommonSequence(string& str1, string& str2){
        int m = str1.length(), n = str2.length();
        if(m == 0 || n == 0)
            return 0;
        dp = vector<vector<int> >(m+1, vector<int>(n+1, 0));
        // 多申请了一行
        for(int i = 1; i < m+1; ++i){
            for(int j = 1; j < n+1; ++j){
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    // 找出所有的LCS的序列
    // 这里形参lcs_str不可以为引用，这里需要每次调用lcs_str都重新生成一个对象
    void PrintAllLCS(string& str1, string& str2, int i, int j, string lcs_str){
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                lcs_str = str1[i-1] + lcs_str;
                --i;
                --j;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1])  //向左走
                    --i;
                else if(dp[i-1][j] < dp[i][j-1])  //向上走
                    --j;
                //此时向上向右均为LCS的元素
                else{
                    PrintAllLCS(str1, str2, i-1, j, lcs_str);
                    PrintAllLCS(str1, str2, i, j-1, lcs_str);
                    return;
                }
            }
        }
        all_lcs.insert(lcs_str);
    }
    vector<vector<int>> dp;
    set<string> all_lcs;
// 2. 最大公共子串
    int lengthOflongestCommonSubstring(string& str1, string& str2){
    	int m = str1.size(), n = str2.size();
    	int res = 0;
    	vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
    	for(int i = 1; i <= m; ++i){
        	for(int j = 1; j <= n; ++j){
            	if(str1[i-1] == str2[j-1])
                	dp[i][j] = dp[i-1][j-1] + 1;
            	else
                	dp[i][j] = 0;
            	if(res < dp[i][j])
                	res = dp[i][j];
        	}
    	}
    	return res;
	}
};

/**********************************************************************************************************
3. 最大连续子数组
描述
Find the contiguous subarray within an array (containing at least one number) which has the largest
sum.
For example, given the array [−2,1,−3,4,−1,2,1,−5,4], the contiguous subarray [4,−1,2,1] has
the largest sum = 6.   
**********************************************************************************************************/
int maxSubArray(vector<int>nums){
    int result = INT32_MIN, f = 0;
    for(int i = 0;i < nums.size() ; i++){
        f = max(f + nums[i], nums[i]); //连续和 ? 当前值
        result = max(result, f); //更新结果
    }
    return result;
}
/**********************************************************************************************************
4. 最长递增子序列
**********************************************************************************************************/
vector<int> getdp1(vector<int> &arr){
    vector<int> dp(arr.size(), 0);
    for(int i = 0; i < arr.size(); i++){
        dp[i] = 1;
        for (int j = 0; j < i; j++){
            if (arr[j] < arr[i]){
                dp[i] = max(dp[j]+ 1, dp[i]);
            }
        }
    }
    return dp;
}

vector<int> getdp2(vector<int> &arr){
    vector<int> dp(arr.size(), 0);
    vector<int> ends(arr.size(), 0);
    ends[0] = arr[0]; dp[0] = 1;
    int right = 0; int l = 0; int r = 0; int m = 0;
    for (int i = 1; i < arr.size(); i++) {
        l = 0;
        r = right;
        while(l <= r) {      //二分法
            m = (l + r) / 2;
            if (arr[i] > ends[m]){
                l = m + 1;
            }else {
                r = m - 1;
            }
        }
        right = max(right, l);
        ends[l] = arr[i];
        dp[i] = l + 1;
    }
    return dp;
}
 
vector<int> generateLIS(vector<int> &arr, vector<int> &dp){
    int len = 0; int index = 0;
    for (int i = 0; i < dp.size(); i++) { //寻最长递增子序列末尾的位置和值
        if (dp[i] > len) {
            len = dp[i];
            index = i;
        }
    }
    vector<int> lis(len, 0);
    lis[--len] = arr[index];
    for (int i = index; i >= 0; i--){
        if (arr[i] < arr[index] && dp[i] == dp[index] - 1){  //从后往前找子序列
            lis[--len] = arr[i];
            index = i;
        }
    }
    return lis;
}
/**********************************************************************************************************
5. 最短路径和
   只能往右或者往下，那么上面那个位置
**********************************************************************************************************/
int minPathSum(vector<vector<int> > &grid) {
    if (grid.size() == 0) 
        return 0;
    const int m = grid.size();
    const int n = grid[0].size();
    int f[m][n];
    f[0][0] = grid[0][0];
    for (int i = 1; i < m; i++) {
        f[i][0] = f[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < n; i++) {
        f[0][i] = f[0][i - 1] + grid[0][i];
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
        }
    }

    return f[m - 1][n - 1];
}
/**********************************************************************************************************
6. Triangle
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
minimum path sum from top to boom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note: Bonus point if you are able to do this using only O(n) extra space, where n is the total number
of rows in the triangle.      
**********************************************************************************************************/
int minimum(vector<vector<int>> & triangle){
    for(int i = triangle.size() - 2; i >=0; i--){
        for(int j = 0;j < triangle[i].size(); j++){
            triangle[i][j] = min(triangle[i + 1][j] , triangle[i + 1][j + 1]);
        }
    } 
    // 从下往上走，下面一层选较小的值，往上走
    return triangle[0][0];
}

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
int main()
{
    //1.2 1. 最长公共子序列 2. 最长公共子串
    string s1 = "abcfbc";
    string s2 = "abfcab";
    Solution fir;
    string lcs_str;
    int res = fir.lengthOflongestCommonSequence(s1, s2);
    cout << res << endl;
    fir.PrintAllLCS(s1, s2, s1.length(), s2.length(), lcs_str);
    set<string>::iterator iter = fir.all_lcs.begin();
	while (iter != fir.all_lcs.end()) {
		cout << *iter++ << endl;
	}
    //3. 最大连续子数组
    vector<int>nums= {-2,1,-3,4,-1,2,1,-5,4};
    cout << "maxSubArray:" << maxSubArray(nums) << endl;
    //4. 最长递增子序列
    vector<int>numsla= {2,1,5,3,6,4,8,9,7};
    vector<int>resultla = getdp1(numsla);
    vector<int>resultlb ;
    resultlb = generateLIS(numsla,resultla);
    cout << "generateLIS:"<< endl;
    printvector(resultlb);
    /*
    vector<vector<int>> dp(m, vector<int> (n));
    初始化一个mxn的二维数组，初始值为1；
    vector<vector<int>> dp(m, vector<int> (n, 1))
    */
    //5. 最短路径和
    vector<vector<int>> numsa = {{1,3,1},{1,5,1},{4,2,1}};
    cout << "minPathSum: " <<  minPathSum(numsa) << endl;
    //6. Triangle
    vector<vector<int>> numsb = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << "minimum: " <<  minimum(numsb) << endl;
    return 0;

}















