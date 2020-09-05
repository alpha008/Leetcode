

/*
1. 求二叉树中的节点个数
2. 求二叉树的深度
3. 前序遍历，中序遍历，后序遍历
4.分层遍历二叉树（按层次从上往下，从左往右）
5. 将二叉查找树变为有序的双向链表
6. 求二叉树第K层的节点个数
7. 求二叉树中叶子节点的个数
8. 判断两棵二叉树是否结构相同
9. 判断二叉树是不是平衡二叉树
10. 求二叉树的镜像
*/
#include<iostream>
#include<queue>
#include<deque>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
using namespace std;
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};
void Visit(BinaryTreeNode * pRoot);
/**************************************************************************************************
1. 求二叉树中的节点个数
递归解法：
（1）如果二叉树为空，节点个数为0
（2）如果二叉树不为空，二叉树节点个数 = 左子树节点个数 + 右子树节点个数 + 1
 * ************************************************************************************************/
int GetNodeNum(BinaryTreeNode * pRoot) 
{ 
    if(pRoot == NULL) // 递归出口 
        return 0; 
    return GetNodeNum(pRoot->m_pLeft) + GetNodeNum(pRoot->m_pRight) + 1; 
}
/**************************************************************************************************
2. 求二叉树的深度
递归解法：
（1）如果二叉树为空，二叉树的深度为0
（2）如果二叉树不为空，二叉树的深度 = max(左子树深度， 右子树深度) + 1
 *************************************************************************************************/
int GetDepth(BinaryTreeNode * pRoot) 
{ 
    if(pRoot == NULL) // 递归出口 
        return 0; 
    int depthLeft = GetDepth(pRoot->m_pLeft); 
    int depthRight = GetDepth(pRoot->m_pRight); 
    return depthLeft > depthRight ? (depthLeft + 1) : (depthRight + 1);  
} 
/**************************************************************************************************
前序遍历递归解法：
（1）如果二叉树为空，空操作
（2）如果二叉树不为空，访问根节点，前序遍历左子树，前序遍历右子树
 *************************************************************************************************/
void PreOrderTraverse(BinaryTreeNode * pRoot) 
{ 
    if(pRoot == NULL) 
        return; 
    Visit(pRoot); // 访问根节点 
    PreOrderTraverse(pRoot->m_pLeft); // 前序遍历左子树 
    PreOrderTraverse(pRoot->m_pRight); // 前序遍历右子树 
} 

/**************************************************************************************************
中序遍历递归解法
（1）如果二叉树为空，空操作。
（2）如果二叉树不为空，中序遍历左子树，访问根节点，中序遍历右子树
 *************************************************************************************************/
void InOrderTraverse(BinaryTreeNode * pRoot) 
{ 
    if(pRoot == NULL) 
        return; 
    InOrderTraverse(pRoot->m_pLeft); // 中序遍历左子树 
    Visit(pRoot); // 访问根节点 
    InOrderTraverse(pRoot->m_pRight); // 中序遍历右子树 
}

/**************************************************************************************************
后序遍历递归解法
（1）如果二叉树为空，空操作
（2）如果二叉树不为空，后序遍历左子树，后序遍历右子树，访问根节点
 *************************************************************************************************/
void PostOrderTraverse(BinaryTreeNode * pRoot) 
{ 
    if(pRoot == NULL) 
        return; 
    PostOrderTraverse(pRoot->m_pLeft); // 后序遍历左子树 
    PostOrderTraverse(pRoot->m_pRight); // 后序遍历右子树 
    Visit(pRoot); // 访问根节点 
}
/**************************************************************************************************
4.分层遍历二叉树（按层次从上往下，从左往右）
 *************************************************************************************************/
void LevelTraverse(BinaryTreeNode * pRoot) 
{ 
    if(pRoot == NULL) 
        return; 
    queue<BinaryTreeNode *> q; 
    q.push(pRoot); 
    while(!q.empty()) 
    { 
        BinaryTreeNode * pNode = q.front(); 
        q.pop(); 
        Visit(pNode); // 访问节点 
        if(pNode->m_pLeft != NULL) 
            q.push(pNode->m_pLeft); 
        if(pNode->m_pRight != NULL) 
            q.push(pNode->m_pRight); 
    } 
    return; 
}
/**************************************************************************************************

 *************************************************************************************************/


/**************************************************************************************************

 *************************************************************************************************/


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




/**********************************************************************************************************
Given a binary tree, find its maximum depth.
e maximum depth is the number of nodes along the longest path from the root node down to the
farthest leaf node.

**********************************************************************************************************/


class Solution{
public:
    int maxDepth(TreeNode *root){
        if(!root) return 0;
        
        return max(maxDepth(root->left),maxDepth(root->right)) + 1;
    }
};

/**********************************************************************************************************
Given a binary tree, return the level order traversal of its nodes’ values. (ie, from le to right, level by
level).
For example: Given binary tree {3,9,20,#,#,15,7},
    3
    / \
    9 20
    / \
    15 7
return its level order traversal as:
    [
    [3],
    [9,20],
    [15,7]
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
            return result;
        }
};




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




