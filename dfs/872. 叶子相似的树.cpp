/*
请考虑一颗二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个叶值序列 。
举个例子，如上图所示，给定一颗叶值序列为 (6, 7, 4, 9, 8) 的树。
如果有两颗二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。
如果给定的两个头结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。

*/
//方法一：自己的方法，和题解一样
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
    ;
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        vector<int> leaf2;
        dfs(root1,leaf1);//得到root1的叶节点
        dfs(root2,leaf2);//得到root2的叶节点
        
        if(leaf1==leaf2){
            return true;
        }
        else{
            return false;
        }
    }
    void dfs(TreeNode* root,vector<int>&leaf){//注意加引用
        if(!root){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            leaf.push_back(root->val);//把叶节点的值push进去
            return ;
        }
        dfs(root->left,leaf);
        dfs(root->right,leaf);
    }
};
