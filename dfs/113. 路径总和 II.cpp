给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

//方法三：2020/7/22 整理的题解
class Solution {
public:
    vector<vector<int>> res;
    vector<int>path;
    void dfs(TreeNode* root,int sum){
        if(root==NULL){
            return;
        }
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL && root->val==sum){//满足条件的叶节点
            res.push_back(path);
        }
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
        path.pop_back();//回溯，把刚刚加入的状态移除
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root){
            dfs(root,sum);
        }
        return res;    
    }
};
//方法一：递归 自己的方法
//这个题就是在路径总和1的基础上，加了个返回给定目标的路径，所以我就设了个全局变量res来存储满足条件的路径
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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> ans;
        dfs(root,0,ans,sum);
        return res;    
    }
    void dfs(TreeNode* root, int cnt,vector<int>ans,int sum){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
                cnt+=root->val;
                ans.push_back(root->val);
                if(cnt==sum){
                    res.push_back(ans);
                }
            return ;
        }
        ans.push_back(root->val);
        cnt+=root->val;
        dfs(root->left,cnt,ans,sum);
        dfs(root->right,cnt,ans,sum);
    }
};

//方法二： 回溯法  对方法一的改进

/*
我们不用为每条路径path都创建一个新的vector，这样会很浪费空间和时间
我们在递归时可以传递的引用，再通过回溯的方法来确保path的正确性，即每次访问完一条路径后，回溯，即删除list的最后一个元素，让path恢复到正确的状态，再接着另一条路径的访问。

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
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> ans;
        int cnt=0;
        dfs(root,cnt,ans,sum);
        return res;    
    }
    void dfs(TreeNode* root, int& cnt,vector<int>&ans,int sum){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        cnt+=root->val;
        if(root->left==NULL && root->right==NULL&&cnt==sum){
            res.push_back(ans);     
            //这里不能加return，这样递归到这里的时候满足条件的值就不会继续下面的，也是就2就不会被删除，一直会在ans里
        }
        dfs(root->left,cnt,ans,sum);
        dfs(root->right,cnt,ans,sum);
        //不满足条件，就回溯，
        cnt-=root->val;
        ans.pop_back();
    }
};
