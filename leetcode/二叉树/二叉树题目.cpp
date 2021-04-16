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
#include<stack>
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
// 二叉树层序遍历
class Solution {
public:
   vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr)  return result;
        queue<TreeNode *> current;
        vector<int>level;
        current.push(root);
        current.push(nullptr);
        while(!current.empty()){
            TreeNode * temp = current.front();
            current.pop();
            if(temp){
                level.push_back(temp->val);
                if(temp->left != nullptr) current.push(temp->left);
                if(temp->right!=nullptr) current.push(temp->right);
            }else{
                result.push_back(level);
                level.clear();
                if(current.size() > 0) current.push(nullptr);
            }         
        }
        return result;
    }
};
/**********************************************************************************************************
2.二叉树最小深度 -- 到叶子节点
**********************************************************************************************************/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(root->left == NULL && root->right !=NULL) return 1 + minDepth(root->right);
        if(root->left != NULL && root->right == NULL) return 1 + minDepth(root->left); 
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
/**********************************************************************************************************
3. 二叉树最大深度
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

**********************************************************************************************************/
//广度优先遍历，用一个 bool 记录是从左到右还是从右到左，每一层结束就翻转一下   
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr)  return result;
        queue<TreeNode *> current;
        bool left_to_right = true;
        vector<int>level;
        current.push(root);
        current.push(nullptr);
        while(!current.empty()){
            TreeNode * temp = current.front();
            current.pop();
            if(temp){
                level.push_back(temp->val);
                if(temp->left != nullptr) current.push(temp->left);
                if(temp->right!=nullptr) current.push(temp->right);
            }else{
                if(left_to_right){
                    result.push_back(level);
                }
                else{
                    reverse(level.begin(),level.end());
                    result.push_back(level);
                }
                level.clear();
                left_to_right = !left_to_right;
                if(current.size() > 0) current.push(nullptr);
            }
            
        }
        return result;
    }
};
// 单队列加标记翻转位置
/**********************************************************************************************************
10.path路径和
**********************************************************************************************************/
bool hasPath(TreeNode *root, int sum){
    if(!root) return false;
    if(root->left == nullptr && root->right == nullptr)   
        return sum == root->val;//结束条件，叶子节点   只有到了叶子节点才会去判断结果
    return hasPath(root->left, sum - root->val) || hasPath(root->right, sum - root->val);
}
/**********************************************************************************************************
11.path路径和 -- 求具体的路径
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

    TreeNode *buildTree(vector<int> &inorder,int inleft,int inright, vector<int> &postorder,int pLeft,int pRight)
    {
        if(inleft > inright || pLeft > pRight)
            return NULL;
        vector<int>::iterator iter = find(inorder.begin(),inorder.end(),postorder[pRight]);
        int index = iter - inorder.begin();  // 返回的是距离开始结点的位置，并不是个数
        TreeNode* root = new TreeNode(postorder[pRight]);                       //-1去掉中间个数
        root->left = buildTree(inorder, inleft, index-1, postorder, pLeft, pLeft+index-inleft-1);
        root->right = buildTree(inorder, index+1, inright, postorder, pLeft+index-inleft, pRight-1);
        return root;
    }
};
/**********************************************************************************************************
13. 给定前序和中序遍历重建二叉树
**********************************************************************************************************/
class SolutionBuildTreeBB {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty() || inorder.empty())
            return NULL;
        TreeNode* root = buildTree(preorder, 0, preorder.size() - 1,  inorder, 0, inorder.size() - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder,  int preleft, int preright,vector<int>& inorder, int inleft, int inright)
    {
        if (preleft > preright || inleft > inright)
            return nullptr;
        vector<int>::iterator iter = find(inorder.begin(),inorder.end(),preorder[preleft]);
        int index = iter - inorder.begin();  // 返回的是距离开始结点的位置，并不是个数
        TreeNode* root = new TreeNode(preorder[preleft]);//根节点
        root->left = buildTree(preorder, preleft+1, preleft+index-inleft, inorder, inleft,index-1);
        root->right = buildTree(preorder, preright-inright+index+1 ,preright , inorder, index + 1, inright);
        return root;
    }

};
//14 二叉树层序遍历  递归
class Level{
public:
    vector<vector<int>> levelOrder(TreeNode *root){
        vector<vector<int>> result;
        traverse(root,1,result);
        return result;
    }
    void traverse(TreeNode* root,int level, vector<vector<int>>&result){
        if(!root) return ;
        if(level > result.size()){
             result.push_back(vector<int>());   
        }
        result[level-1].push_back(root->val);
        traverse(root->left ,level++,result);
        traverse(root->right ,level++,result);
    }

};
//94. Binary Tree Inorder Traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        inorderTraversal(root->left);
        result.push_back(root->val);
        inorderTraversal(root->right);
        return result;
    }
    vector<int> result;
};
//112. Path Sum
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)  return false;
        if(root->left == NULL && root->right == NULL)
            return root->val == sum ;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
//113. Path Sum II
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        pathsum(root, sum , result, path);
        return result;
    }
    void pathsum(TreeNode *root, int sum ,vector<vector<int>>&result,vector<int>&path){
        if(!root) return ;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(root->val == sum )
                result.push_back(path);
        }
        pathsum(root->left, sum - root->val , result, path);
        pathsum(root->right, sum - root->val , result, path);
        path.pop_back();
    }
};
//104. Maximum Depth of Binary Tree
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;   
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
//100. Same Tree
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q )  return true;
        if((p &&! q) || (!p && q) || (p->val != q->val)) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};
bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> st;
        st.push(p); st.push(q);
        while (!st.empty()) {
            p = st.top(); st.pop();
            q = st.top(); st.pop();
            if (!p && !q) continue;
            if ((p && !q) || (!p && q) || (p->val != q->val)) return false;
            st.push(p->right); st.push(q->right);
            st.push(p->left); st.push(q->left);
        }
        return true;
    }
//101. Symmetric Tree
class Solution {
public:
    bool isSymmetric(TreeNode* root) {       
        if(root->left->val == root->right->val) {
             return true;
        }else{
            return false;
        } 
        return isSymmetric(root->left) && isSymmetric(root->right);
    }
};
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> result;
        if (root) 
            binaryTreePaths(root, "", result);
        return result;
    }
    void binaryTreePaths(TreeNode *root, string path, vector<string> &result) {
        path += to_string(root->val);
        if (!root->left && !root->right) result.push_back(path);
        else {
            if (root->left) binaryTreePaths(root->left, path + "->", result);
            if (root->right) binaryTreePaths(root->right, path + "->", result);
        }
    }
};
//129. Sum Root to Leaf Numbers   // 递归深度搜索
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int result = dfs(root, 0);
        return result;    
    }
    int dfs(TreeNode* root, int sum ){
         if(!root)  return 0;
         if(root->left == NULL && root->right == NULL)
             return sum * 10 + root->val;             
         return dfs(root->left,sum * 10 + root->val) + dfs(root->right, sum * 10 + root->val);    
    }
};
//124. Binary Tree Maximum Path Sum
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        //注意，最后 return 的时候，只返回一个方向上的值，为什么？这是因为在递归中，只能向父节
        //点返回，不可能存在 L->root->R 的路径，只可能是 L->root 或 R->root。
        max_sum = INT32_MIN;
        if(!root) return 0;
        dfs(root);
        return max_sum;
    }
    int dfs(const TreeNode* root){
        if(!root) return 0;      
        int l = dfs(root->left);
        int r = dfs(root->right);
        int sum = root->val;
        if(l > 0) sum = sum + l;
        if(r > 0) sum = sum + r;
        max_sum = max(max_sum , sum);  // L->root->R 
        return max(l, r) > 0 ? max(l ,r) + root->val : root->val;
    }
public:
    int max_sum;
};
// 二叉树前序遍历
//144. Binary Tree Preorder Traversal                            // 前序遍历
class Solution {
public:
    vector<int> prevTraversal(TreeNode* root) {      
        if(!root)  return {};
        stack<TreeNode *> sk;
        sk.push(root);
        while(!sk.empty()){
            TreeNode * temp = sk.top();   
            sk.pop();
            result.push_back(temp->val);      
            if(temp->right!= NULL)
                sk.push(temp->right);
            if(temp->left != NULL)
                sk.push(temp->left);
        }
        return result;
    }
//94. Binary Tree Inorder Traversal           //二叉树中序遍历
// 中序遍历
    vector<int> inorderTraversal(TreeNode* root) {     
        if(!root)  return {};            
        stack <TreeNode*> stack;
        while (!stack.empty() || root != NULL) {
            if (root != NULL) {
                stack.push(root);
                root = root->left;
            } else {
                root = stack.top();
                stack.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }
//145. Binary Tree Postorder Traversal                           // 后序遍历
    // 后续遍历
    vector<int> postorderTraversal(TreeNode*root) {
        if (root == NULL) 
            return;
        stack<TreeNode*> s1 ;
        stack<TreeNode*> s2 ;
        s1.push(root);

        while (!s1.empty()) {
            root = s1.top();
            s1.pop();
            s2.push(root);
            if (root->left != NULL) {
                s1.push(root->left);
            }
            if (root->right != NULL) {
                s1.push(root->right);
            }
        }
        while (!s2.empty()) {
            TreeNode *temp  = s2.top();
            s2.pop();
            result.push_back(temp->val);
        }
        return result;
    }
    vector<int> result;
};

//429 convert binary tree to double list 
class Solution {
public:
    TreeNode * Convert(TreeNode * root){
            if(root == NULL) return ;
            if(root->left == NULL && root->right == NULL)
                return root;
            TreeNode * left = Convert(root->left);
            TreeNode * cur = left;
            while(cur!= NULL && cur->right !=NULL){
                cur = cur->right;
            }
            if(left != NULL){
                cur->right = root;
                root->left = cur;
            }
            TreeNode * right = Convert(root->right);
            if(right!=NULL){
                root->right = right;
                right->left = root;
            }
            return left != NULL ? left : root;
    }
};
// 110. Balanced Binary Tree
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return balancedHeight(root) >=0;
    }
    int balancedHeight(TreeNode* root){
        if(root == NULL) return 0;
        int left = balancedHeight(root->left);
        int right = balancedHeight(root->right);
        if(left < 0 || right < 0 || abs(left - right) > 1)
            return -1;  // left 、right <0 是因为剪纸造成的
        return max(left , right ) + 1;
    }
};
// 如果没有那么就变成求树的最大深度了
// 114. Flatten Binary Tree to Linked List
class Solution {
public:
// 迭代版  前序遍历刚好符合这种性质
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto p = s.top();
            s.pop();
            if (p->right)
                s.push(p->right);
            if (p->left)
                s.push(p->left);
            p->left = nullptr;
            if (!s.empty())
                p->right = s.top();
        }
    }
// 递归版本
    void flatten(TreeNode* root) {
        if(root == NULL) return ;
        flatten(root->left);
        flatten(root->right);
        if(root->left == NULL) return ;

        TreeNode * p = root->left;
        while(p->right!= NULL)
            p = p->right;   //左边链表最后一个节点与根节点的右节点相对接
        p->right = root->right;
        root->right = root->left;
        root->left = NULL;
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