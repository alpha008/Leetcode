/**************************************************************************************************

 *************************************************************************************************/

/**********************************************************************************************************
描述
Given a set of distinct integers, S, return all possible subsets.
Note:
• Elements in a subset must be in non-descending order.
• e solution set must not contain duplicate subsets.
For example, If S = [1,2,3], a solution is:
[
    [3],
    [1],
    [2],
    [1,2,3],
    [1,3],
    [2,3],
    [1,2],
    []
]
**********************************************************************************************************/

class Solution{
public:
    vector<vector<int>> subsets(vector<int>&S){
        sort(S.begin(), S.end());
        vecotr<vector<int>> result;
        vector<int> path;
        subsets(S,path , 0 ,result);
        return result;
    }
private:
    static void subsets(const vector<int>&S, vector<int>&path, int step, vector<vector<int>>&result){
        if(step == S.size()){
            result.push_back(path);
            return ;
        }
        subsets(S, path , step + 1,  result);
        path.push_back(S[step]);
        subsets(S, path , step + 1,  result);
        path.pop_back();
    }
};

/**********************************************************************************************************
描述
Given a collection of integers that might contain duplicates, S, return all possible subsets.
Note:
Elements in a subset must be in non-descending order. e solution set must not contain duplicate
subsets. For example, If S = [1,2,2], a solution is:
[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]
分析
这题有重复元素，但本质上，跟上一题很类似，上一题中元素没有重复，相当于每个元素
选 0 或 1 次，这里扩充到了每个元素可以选 0 到若干次而已。


**********************************************************************************************************/

class Solution{
public:
    vecotr<vector<int>> subsetWithDup(vector<int>&S){
        sort(S.begin(),S.end());

        vector<vector<int>> result;
        vector<int>path;
        dfs(S, S.begin(), path, result);
        return result;
    }
private:
    static void dfs(const vector<int>&S, vector<int>::iterator start,
        vector<int>&path, vector<vector<int>>&result){
        result.push_back(path);
        for(auto i = atart;i < S.end(); i++){
            if(i != start && *i == *(i-1)) continue;          
            path.push_back(*i);
            dfs(S, i + 1,path ,result);
            path.pop_back();           
        }
    }
};

void dfs(vector<int>& nums, int pos, vector<int>& path, vector<vector<int>>& result)
{
    if(pos == nums.size())    return;
    for(int i = pos; i < nums.size(); i ++)
    {
        path.push_back(nums[i]);
        result.push_back(path);
        dfs(nums, i + 1, path, result);
        path.pop_back();
    }
}

vector<vector<int>> subsets2(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    result.push_back(path);
    if(nums.empty())    return result;
    dfs(nums, 0, path, result);
    return result;
}
