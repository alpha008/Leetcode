
/**********************************************************************************************************
Given a binary tree, find its minimum depth.
e minimum depth is the number of nodes along the shortest path from the root node down to the
nearest leaf node.
**********************************************************************************************************/


#include<iostream>
#include<unordered_map>
using namespace std;
//广度优先遍历，用一个 bool 记录是从左到右还是从右到左，每一层结束就翻转一下   
Class Solution{
public:
    int minDepth(const TreeNode *root){
        return minDepth(root, false);
    }
private:
    static int minDepth(TreeNode*root, bool hashbrother){
        if(!root)
            return hashbrother ? INT_MAX : 0;
        retrun 1 + min(minDepth(root->left, root->right !=NULL),
            minDepth(root->right, root->left !=NULL));
    }
    
};

/**********************************************************************************************************
1.首先判断根节点是否为空，若为空，返回0
2.判断左子树，当左子树为空返回左子树+1
3.判断右子树，当右子树为空返回右子树+1
4.当左右子树不为空时，返回左右子树中较小的

** 需要遍历到叶子节点
**********************************************************************************************************/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left) return 1 + minDepth(root->right);
        if (!root->right) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};


