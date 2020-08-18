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



