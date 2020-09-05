#include<tree.h>

/**********************************************************************************************************
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the
values along the path equals the given sum.
For example: Given the below binary tree and sum = 22,
5
/ \
4 8
/ / \
11 13 4
/ \ \
7 2 1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
分析
题目只要求返回 true 或者 false，因此不需要记录路径。
由于只需要求出一个结果，因此，当左、右任意一棵子树求到了满意结果，都可以及时 
return。
由于题目没有说节点的数据一定是正整数，必须要走到叶子节点才能判断，因此中途没法剪枝
只能进行朴素深搜

**********************************************************************************************************/
class Solution{
pubic:
        bool hasPath(TreeNode *root, int sum){

            if(!root) return false;
            if(root->left == nullptr && root->right == nullptr)
                return sum == root->val;//结束条件，叶子节点 == 最后差值
        
            return hasPath(root->left, sum - root->val)
                || hasPath(root->right, sum - root>val);
        }

};
/**********************************************************************************************************
5.4.4 Path Sum II
描述
Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.
For example: Given the below binary tree and sum = 22,
5
/ \
4 8
/ / \
11 13 4
/ \ / \
7 2 5 1
return
[
[5,4,11,2],
[5,8,4,5]
]
**********************************************************************************************************/
class Solution{
public:
    vector<vector<int>> pathSum(TreeNode *root.int sum){
        vector<vector<int>>result;
        vector<int> cur;
        pathSum(root, sum ,cur, result);
    }
pivate:
    void pathSum(TreeNode*root,int gap,vector<int>&cur,vector<vector<int>>&result){
        if(!root) return ;
        cur.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(gap == root->val)
                result.push_back(cur);
        }
        pathSum(root->left, gap - root->val, cur ,result);
        pathSum(root->right,gap - root->val, cur ,result);
    }

};




