/*
给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]
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
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root){
        if(root==NULL){
            return ;
        }
        ans.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
};
//方法二：迭代
/*
先访问的后压栈
我们需要一个标志区分每个递归调用栈，这里使用nullptr来表示。
*/
class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*>stack;
        if(root!=nullptr) stack.push(root);
        while(!stack.empty()){
            TreeNode* t = stack.top();
            stack.pop();//访问过的节点弹出
            if(t!=nullptr){
                if(t->right!=nullptr) stack.push(t->right);//右节点先压栈，最后处理
                if(t->left!=nullptr) stack.push(t->left);
                stack.push(t);//当前节点重新压栈（留着以后处理），因为先序遍历所以最后压栈
                stack.push(nullptr);//在当前节点之前加入一个空节点表示已经访问过了
            }
            else{
                ans.push_back(stack.top()->val);//call.top()是nullptr之前压栈的一个节点，也就是上面call.push(t)中的那个t
                stack.pop();//处理完了，第二次弹出节点（彻底从栈中移除）
            }
            
        }
        return ans;
    }

};
