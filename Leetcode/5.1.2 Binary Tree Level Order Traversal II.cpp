/**********************************************************************************************************
Given a binary tree, return the boom-up level order traversal of its nodes’ values. (ie, from le to
right, level by level from leaf to root).
For example: Given binary tree {3,9,20,#,#,15,7},
    3
    / \
    9 20
    / \
    15 7
return its boom-up level order traversal as:
    [
    [15,7]
    [9,20],
    [3],
]

**********************************************************************************************************/
#include<iostream>
#include<unordered_map>
using namespace std;

Class Solution{
public:
        vector<vector<int> > levelOrder(TreeNode * root){
            vector<vector<int>> result;
            if(root == nullptr){
                return result;
            }
            queue<TreeNode*> current, next;
            vector<int> level;
            current.push(root);
            while(!current.empty()){
                while(!current.empty()){
                    TreeNode * node = current.front();
                    current.pop();
                    level.push_back(node);
                    if(node->left != nullptr) next.push(node->left);
                    if(node->right != nullptr) next.push(node->right);
                }
                result.push_back(level->val);
                level.clear();
                swap(next,current);
            }
            reverse(result.begin(),result.end());
            return result;
        }
};





