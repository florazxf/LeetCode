/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
*/

//2.27 
class Solution {
    public boolean isValidBST(TreeNode root) {
        return isValidBST(root,Long.MIN_VALUE,Long.MAX_VALUE);
    }

    public boolean isValidBST(TreeNode root,long lower,long upper){
        if(root==null){
            return true;
        }
        if(root.val<=lower || root.val>=upper){
            return false;
        }
        return isValidBST(root.left,lower,root.val) && isValidBST(root.right,root.val,upper);
    }
}




//方法一：自己的方法
//做这道题就知道 二叉搜索树的中序遍历是递增序列，那么我就把中序遍历的结果放到数组nums里，然后再判断nums是否是递增序列
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
    vector<int> nums;
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        dfs(root);
        for(int i=0;i<nums.size()-1;i++) //判断中序遍历是不是递增序列
        {
            if(nums[i]>=nums[i+1]){ //不是递增序列则不是二叉搜索树
                return false;
            }
        }
        return true;

    }
    void dfs(TreeNode* root){
        if(!root){
            return ;
        }
        //中序遍历
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }
};

//方法三：
//用划定边界的方法递归，注意样例中有数据INT_MAX和INT_MIN，改用long型的边界即可
//左结点要大于long_MIN且小于其父节点，右节点大于父节点且小于LONG_MAX
class Solution {
public:
    bool isValid(TreeNode* current,long left,long right){
    if(current==nullptr) return true;
    else if(current->val<=left||current->val>=right) return false;
    return isValid(current->left,left,current->val)&&isValid(current->right,current->val,right);
    }
    
    bool isValidBST(TreeNode* root) {
    return isValid(root,LONG_MIN,LONG_MAX);
    }

};
