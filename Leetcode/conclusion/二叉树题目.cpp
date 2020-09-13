#include<iostream>
#include<queue>
#include<deque>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};
/**********************************************************************************************************
1. 层序遍历二叉树
2. 二叉树最小深度 -- 到叶子节点
3. 二叉树最大深度
4. 求二叉树中的节点个数
5. 前序遍历递归解法：
6. 中序遍历递归解法
7. 后序遍历递归解法
8. 分层遍历二叉树，反转
9. z字遍历二叉树
10. path路径和
11. path路径和 -- 求具体的路径
12. 给定中序和后序遍历重建二叉树
13. 给定前序和中序遍历重建二叉树
**********************************************************************************************************/
/**********************************************************************************************************
1. 手动创建一颗二叉树，根据数组
**********************************************************************************************************/
TreeNode* createBinaryTree(vector<int> &nums)
{
    vector<TreeNode*> Tnode;
    for(int i =0;i < nums.size(); i++)
    {
         Tnode.push_back(new TreeNode(nums[i]));
    }
    for(int i = 0;i < nums.size(); i++)
    {
        cout<<Tnode[i]->val<<" ";
    }
    cout << endl << "createBinaryTree sucess"<<endl;
    Tnode[0]->left =  Tnode[1];
    Tnode[0]->right = Tnode[2];
    Tnode[1]->left =  Tnode[3];
    Tnode[1]->right = Tnode[4];
    //Tnode[2]->left =  Tnode[5];
    //Tnode[2]->right = Tnode[6];
    return Tnode[0];
}
/**********************************************************************************************************
2. 打印二维矩阵
**********************************************************************************************************/
void printMatrix(vector<vector<int>> &display)
{
    for(int i = 0; i < display.size();i++){
        for(int j = 0;j < display[i].size();j++){
            cout << display[i][j] ;
        }
        cout << endl;
    }
}

/**********************************************************************************************************
1.层序遍历二叉树
**********************************************************************************************************/
vector<vector<int> > levelOrder(TreeNode * root){
    vector<vector<int>> result;
    if(root == nullptr){
        return result;
    }
    queue<TreeNode*> current, next;
    vector<int> level;
    current.push(root);
    while(!current.empty()){          // 这一层主要是为了最后一层叶子节点做判断
        while(!current.empty()){  // 如果current为空表示下一层已经处理完了，都已经入队了
            TreeNode * node = current.front();
            current.pop();
            level.push_back(node->val);
            if(node->left != nullptr)   next.push(node->left);
            if(node->right != nullptr)  next.push(node->right);
        }
        result.push_back(level);
        level.clear();
        swap(next,current);  // 将next赋值为空
    }
    return result;
}
/**********************************************************************************************************
2.二叉树最小深度 -- 到叶子节点
    1.首先判断根节点是否为空，若为空，返回0
    2.判断左子树，当左子树为空返回右子树+1
    3.判断右子树，当右子树为空返回左子树+1
    4.当左右子树不为空时，返回左右子树中较小的
最小深度需要考虑到是否某个子树深度为0，如果有个节点某个子树为0，就要返回左右子树中深度的最大值，而不是最小值。
注意：
1. 求深度的时候，返回的是分支中较大的，这么做没问题
2. 求最小深度时，需要返回两者中较小的，但是当左右子树其中一个为空的时候，就会出现问题，如果按照常规条件返回
   此处返回的节点并不是叶子节点，即没有到达叶子节点不算二叉树的最小深度，不符合概念
**********************************************************************************************************/
int minDepth(TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL  && root->right != NULL) 
        return 1 + minDepth(root->right);  //遍历到叶子节点 返回1
    if (root->right == NULL && root->left != NULL)
        return 1 + minDepth(root->left);  //遍历到叶子节点 返回1
    return  min(minDepth(root->left), minDepth(root->right)) + 1;
}
/**********************************************************************************************************
3. 二叉树最大深度
   分治
2.3使用BFS遍历最方便
**********************************************************************************************************/
int maxDepth(TreeNode *root){
    if(root == NULL)  //边界点
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left,right) + 1; // 问题分解
}
/**************************************************************************************************
4. 求二叉树中的节点个数
递归解法：
（1）如果二叉树为空，节点个数为0
（2）如果二叉树不为空，二叉树节点个数 = 左子树节点个数 + 右子树节点个数 + 1
 * ************************************************************************************************/
int GetNodeNum(TreeNode * pRoot) 
{ 
    if(pRoot == NULL)  // 递归出口 
        return 0; 
    int left = GetNodeNum(pRoot->left);
    int right = GetNodeNum(pRoot->right);
    return  left + right + 1; 
}
/**************************************************************************************************
5. 前序遍历递归解法：
（1）如果二叉树为空，空操作
（2）如果二叉树不为空，访问根节点，前序遍历左子树，前序遍历右子树
 *************************************************************************************************/
void PreOrderTraverse(TreeNode * pRoot) 
{ 
    if(pRoot == NULL) 
        return;
    cout << pRoot->val << " "; 
    PreOrderTraverse(pRoot->left); // 前序遍历左子树 
    PreOrderTraverse(pRoot->right); // 前序遍历右子树 
} 

/**************************************************************************************************
6.中序遍历递归解法
（1）如果二叉树为空，空操作。
（2）如果二叉树不为空，中序遍历左子树，访问根节点，中序遍历右子树
 *************************************************************************************************/
void InOrderTraverse(TreeNode * pRoot) 
{ 
    if(pRoot == NULL) 
        return; 
    InOrderTraverse(pRoot->left); // 中序遍历左子树 
    cout << pRoot->val << " "; 
    InOrderTraverse(pRoot->right); // 中序遍历右子树 
}
/**************************************************************************************************
7.后序遍历递归解法
（1）如果二叉树为空，空操作
（2）如果二叉树不为空，后序遍历左子树，后序遍历右子树，访问根节点
 *************************************************************************************************/
void PostOrderTraverse(TreeNode * pRoot) 
{ 
    if(pRoot == NULL) 
        return; 
    PostOrderTraverse(pRoot->left); // 后序遍历左子树 
    PostOrderTraverse(pRoot->right); // 后序遍历右子树 
    cout << pRoot->val << " ";     
}
/**********************************************************************************************************
8.分层遍历二叉树，反转
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
vector<vector<int> > relevelOrder(TreeNode * root){
    cout << "relevelOrder" << endl;
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
            level.push_back(node->val);
            if(node->left != nullptr) next.push(node->left);
            if(node->right != nullptr) next.push(node->right);
        }
        result.push_back(level);
        level.clear();
        swap(next,current);
    }
    reverse(result.begin(),result.end());
    return result;
}
/**********************************************************************************************************
9.z字遍历二叉树
     3    true
    / \
    9 20  true
    / \
    15 7  true
return its zigzag level order traversal as:
    [
    [3],     true
    [20,9],  true
    [15,7]   true
    ]
**********************************************************************************************************/
//广度优先遍历，用一个 bool 记录是从左到右还是从右到左，每一层结束就翻转一下   
vector<vector<int> > ziglevelOrder(TreeNode * root){
    cout << "ziglevelOrder" << endl;
    vector<vector<int>> result;
    if(root == nullptr) return result;
    queue<TreeNode*> q;
    bool left_to_right = true;
    vector<int> level;
    q.push(root);
    q.push(nullptr);            // 用来分割层
    while(!q.empty()){
        TreeNode * cur = q.front();
        q.pop();
        if(cur){                // 当前层还没处理完
            level.push_back(cur->val);
            if(cur->left)  q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }else{
            if(left_to_right){   //当cur为空时，当前层结束处理，要调整顺序了
                result.push_back(level);
            }else{
                reverse(level.begin(),level.end());
                result.push_back(level);
            }
            level.clear();
            left_to_right = !left_to_right;
            if(q.size() > 0) q.push(nullptr); //如果此时队列中还有元素，那么加分隔符
        }    
    }
    return result;
}
/**********************************************************************************************************
10.path路径和
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the
values along the path equals the given sum.
For example: Given the below binary tree and sum = 22,
     5
    / \
    4 8
   / / \
  11 13 4
  / \ \
  7 2  1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
**********************************************************************************************************/
bool hasPath(TreeNode *root, int sum){
    if(!root) return false;
    if(root->left == nullptr && root->right == nullptr)   
        return sum == root->val;//结束条件，叶子节点   只有到了叶子节点才会去判断结果
    return hasPath(root->left, sum - root->val) || hasPath(root->right, sum - root->val);
}

/**********************************************************************************************************
11.path路径和 -- 求具体的路径
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
    vector<vector<int>> pathSum(TreeNode *root,int sum){
        vector<vector<int>>result;
        vector<int> cur;
        pathSum(root, sum ,cur, result);
        return result;
    }
private:
    void pathSum(TreeNode*root, int target, vector<int>&cur, vector<vector<int>>&result){
        if(!root) return ;
        cur.push_back(root->val);   // 记录路径
        if(root->left == nullptr && root->right == nullptr){
            if(target == root->val)  //当结果满足条件，将路径存储起来
                result.push_back(cur);
        }
        // 当遍历到叶子节点时，下面两个函数都直接返回，然后处理存储状态即可
        pathSum(root->left , target - root->val, cur ,result);
        pathSum(root->right, target - root->val, cur ,result);
        cur.pop_back();
    }

};

/**********************************************************************************************************
12. 给定中序和后序遍历重建二叉树
    vector<int> preorder = {5,9,67,32};
    vector<int> inorder = {9,5,32,67};
    vector<int> postorder = {9,32,67,5};
**********************************************************************************************************/
class SolutionBuildTreeA {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) 
    {
        if(inorder.empty() || postorder.empty())
            return NULL;
        return buildTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode *buildTree(vector<int> &inorder,int iLeft,int iRight, vector<int> &postorder,int pLeft,int pRight)
    {
        if(iLeft > iRight || pLeft > pRight)
            return NULL;

        TreeNode* root = new TreeNode(postorder[pRight]);
        int i = 0;
        for(i = iLeft;i < inorder.size(); i++)
        {
            if(inorder[i] == root->val)
                break;
        }
        root->left = buildTree(inorder, iLeft, i-1, postorder, pLeft, pLeft+i-iLeft-1);
        root->right = buildTree(inorder, i+1, iRight, postorder, pLeft+i-iLeft, pRight-1);
        return root;
    }
};
/**********************************************************************************************************
13. 给定前序和中序遍历重建二叉树
    vector<int> preorder = {5,9,67,32};
    vector<int> inorder = {9,5,32,67};
    vector<int> postorder = {9,32,67,5};
**********************************************************************************************************/
class SolutionBuildTreeBB {
public:
    TreeNode* buildTree(vector<int>& preorder,  int preleft, int preright,vector<int>& inorder, int inleft, int inright)
    {
        if (preleft > preright || inleft > inright)
            return nullptr;
        vector<int>::iterator iter = find(inorder.begin(),inorder.end(),preorder[preleft]);
        int index = iter - inorder.begin();
        TreeNode* root = new TreeNode(preorder[preleft]);//根节点
        root->left = buildTree(preorder, preleft+1, preleft+index-inleft, inorder, inleft,index-1);
        root->right = buildTree(preorder, preright-inright+index+1 ,preright , inorder, index + 1, inright);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty() || inorder.empty())
            return NULL;
        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1,  inorder, 0, inorder.size() - 1);
        return root;
    }
};
#if 0
class SolutionBuildTreeB {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree_t(preorder,inorder,0,inorder.size()-1,0);
    }
    /*其中
    inorder_start是中序历遍序列的左端点
    i是中序历遍中根节点的位置
    inorder_end是中序历遍的序列的右端点
    */
    TreeNode* buildTree_t(vector<int>& preorder,vector<int>& inorder, int inorder_start, int inorder_end, int pre_root_index)
    {
        if(inorder_start == inorder_end) 
            return new TreeNode(preorder[pre_root_index]);
        if(inorder_start > inorder_end)
            return NULL;
        int root_value = preorder[pre_root_index];
        TreeNode* root = new TreeNode(root_value);
        int i = 0;
        for( ;i < inorder.size(); ++i)
        {
            if(inorder[i] == root_value)
                break;
        }
        root->left = buildTree_t(preorder, inorder, inorder_start, i-1, pre_root_index+1);
        root->right = buildTree_t(preorder, inorder, i+1, inorder_end, pre_root_index+i-inorder_start+1);
        return root;
    }
};
#endif
int main()
{
    vector<vector<int>> result;
    vector<int> nums = {1,2,3,4,5,6,7};
    TreeNode * pNode = createBinaryTree(nums);
    cout << "PreOrderTraverse "<<endl;
    PreOrderTraverse(pNode);
    cout << endl;
    cout << "InOrderTraverse  "<<endl;
    InOrderTraverse(pNode);
    cout << endl;
    cout << "PostOrderTraverse  "<<endl;
    PostOrderTraverse(pNode);
    cout << endl;

    cout << "hasPath  "<<endl;
    cout << hasPath(pNode,7) << endl;
    cout << "hasPath  "<<endl;

    result = relevelOrder(pNode);
    printMatrix(result);
    result = ziglevelOrder(pNode);
    printMatrix(result);
    cout << "minDepth = " << minDepth(pNode) <<endl;
    cout << "maxDepth = " << maxDepth(pNode) <<endl;
    cout << "GetNodeNum = " << GetNodeNum(pNode) <<endl;
    result =  levelOrder(pNode);
    printMatrix(result);

    Solution calpath;
    cout << "hasPath  "<<endl;
    result = calpath.pathSum(pNode,4);
    printMatrix(result);
    
    vector<int> preorder = {5,9,67,32};
    vector<int> inorder = {9,5,32,67};
    vector<int> postorder = {9,32,67,5};

    //12. 给定中序和后序遍历重建二叉树
    cout << "Build Tree in post" << endl;
    SolutionBuildTreeA buildA;
    TreeNode * TreeNodeRootA = buildA.buildTree(inorder,postorder);
    //前
    cout << "PreOrderTraverse  :";   PreOrderTraverse(TreeNodeRootA);  cout << endl;
    //中
    cout << "InOrderTraverse   :";    InOrderTraverse(TreeNodeRootA);  cout << endl;
    //后   
    cout << "PostOrderTraverse :";  PostOrderTraverse(TreeNodeRootA);  cout << endl;

    // 13. 给定前序和中序遍历重建二叉树
    cout << "Build Tree pre in" << endl;
    SolutionBuildTreeBB buildB;
    TreeNode * TreeNodeRootB = buildB.buildTree(preorder,inorder);
    //前
    cout << "PreOrderTraverse  :";  PreOrderTraverse(TreeNodeRootB);  cout << endl; 
    //中
    cout << "InOrderTraverse   :";   InOrderTraverse(TreeNodeRootB);  cout << endl;
    //后   
    cout << "PostOrderTraverse :"; PostOrderTraverse(TreeNodeRootB);  cout << endl;
    cout << endl;
    return 0;
}