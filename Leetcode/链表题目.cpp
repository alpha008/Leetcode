

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




