/*
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]

*/

//方法一：递归
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
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* root){
        if(root==NULL){
            return ;
        }
        
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }
};

//方法二：迭代
class Solution {
public:
   
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*>stk;
        if(root!=nullptr) stk.push(root);
        while(!stk.empty()){
            TreeNode* t = stk.top();
            stk.pop();
            if(t!=nullptr){
                //右节点 最后访问 先压栈
                if(t->right) stk.push(t->right);
                //根节点
                stk.push(t);
                stk.push(nullptr);
                //左结点
                if(t->left) stk.push(t->left);
            }
            else{
                ans.push_back(stk.top()->val);
                stk.pop();
            }
        }
        return ans;
    }

};
