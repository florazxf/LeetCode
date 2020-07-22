/*
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例: 
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。


*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //方法一：2020/7/22 重新整理二叉树路径总和 题解的方法
 /*
 因为是【根节点】到【叶子结点】
 我们dfs的时候可以把问题转化成 是否存在从【当前节点的子节点】到叶子结点的路径，满足路径和为sum-val
 到最后叶子结点的时候 其值等于sum即满足条件
 */
 class Solution {
public:
    //bool has=false;
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return false;
        }
        if(root->left==NULL && root->right==NULL){ //是叶节点 sum已经减过他前面路径的值了
            return root->val==sum;
        }
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
    }



};
 //方法一： 这种方法以后就不要用了
class Solution {
public:
    bool has=false;
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return false;
        }
        dfs(root,sum,0);
        return has;
    }
    void dfs(TreeNode* root, int sum,int res){
        if(root->left==NULL && root->right==NULL){
            
            if((res+root->val)==sum){//只要有一条路的值等于sum就是true
                has=true;
            }
        }
        if(root->left){
            dfs(root->left,sum,res+root->val);

        }
        if(root->right){
            dfs(root->right,sum,res+root->val);
        }
        
    }
};

//方法二：
//把root是否为空放到dfs里面，就不用判断左右结点是否为空了
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool has=false;
    bool hasPathSum(TreeNode* root, int sum) {

        dfs(root,sum,0);
        return has;
    }
    void dfs(TreeNode* root, int sum,int res){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            
            if((res+root->val)==sum){//只要有一条路的值等于sum就是true
                has=true;
            }
        }
      
        dfs(root->left,sum,res+root->val);
        dfs(root->right,sum,res+root->val);
        
    }
};
