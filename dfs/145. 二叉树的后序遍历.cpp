/*
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

*/
//递归

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
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root){
        if(root==NULL){
            return ;
        }
        dfs(root->left);
        dfs(root->right);
        ans.push_back(root->val);
    }
};

//迭代
class Solution {
public:
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*>stk;
        if(root!=nullptr) stk.push(root);
        while(!stk.empty()){
            TreeNode* t = stk.top();
            stk.pop();
            if(t!=nullptr){
                //根节点 后序遍历 最后访问先入栈
                stk.push(t);//在右节点之前重新插入该节点，以便在最后处理（访问值）
                stk.push(nullptr);//nullptr跟随t插入，标识已经访问过，还没有被处理
                //右节点
                if(t->right) stk.push(t->right);
                //左结点
                if(t->left) stk.push(t->left);
            }
            else{ //当前要访问的结点
                ans.push_back(stk.top()->val);
                stk.pop();
            }
        }
        return ans;
    }

};
