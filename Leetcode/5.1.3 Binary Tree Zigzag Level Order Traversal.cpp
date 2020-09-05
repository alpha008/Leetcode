/**********************************************************************************************************
Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from le to right,
then right to le for the next level and alternate between).
For example: Given binary tree 3,9,20,#,#,15,7,
    3
    / \
    9 20
    / \
    15 7
return its zigzag level order traversal as:
    [
    [3],
    [20,9],
    [15,7]
    ]
**********************************************************************************************************/
#include<iostream>
#include<unordered_map>
using namespace std;
//广度优先遍历，用一个 bool 记录是从左到右还是从右到左，每一层结束就翻转一下   
Class Solution{
public:
        vector<vector<int> > levelOrder(TreeNode * root){
            vector<vector<int>> reulst;
            if(root == nullptr) return result;
            queue<TreeNode*> q;
            bool left_to_right = true;
            vector<int> level;
            q.push(root);
            q.push(nullptr);//用来分割层
            while(!q.empty()){
                TreeNode * cur = q.front();
                q.pop();
                if(cur){
                    level.push_back(cur->val);
                    if(node->left) q.push(cur->left);
                    if(node->right) q.push(cur->right);
                }else{
                    if(left_to_right){
                        result.push_back(level);
                    }else{
                        reverse(level.begin(),level,end());
                        result.push_back(level);
                    }
                    level.clear();
                    left_to_right = !left_to_right;
                    if(q.size() > 0) q.push(nullptr);
                }    
            }
            return result;
        }
};

