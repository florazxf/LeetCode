/*
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

*/
/*
首先知道二叉搜索树是什么：

二叉搜索树（Binary Search Tree）是指一棵空树或具有如下性质的二叉树：

若任意节点的左子树不空，则左子树上所有节点的值均小于它的根节点的值
若任意节点的右子树不空，则右子树上所有节点的值均大于它的根节点的值
任意节点的左、右子树也分别为二叉搜索树
没有键值相等的节点

基于以上性质，我们可以得出一个二叉搜索树的特性：二叉搜索树的中序遍历结果为递增序列。

*/

//方法一：自己的方法
//题目已经给我们递增序列了，而二叉搜索树的中序遍历结果为递增序列，所以我就把数组最中间的点作为根，左边的作为左子树，右边的作为右子树进行递归
//然后用了两个vector分别保存左半部分的数组和右半部分的数组，其实没必要这样做，可以看方法二的改进
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len=nums.size();
        if(!len){
            return NULL;
        }
        TreeNode* root=new TreeNode(nums[len/2]);
        if(len==1){
            root->left=NULL;
            root->right=NULL;
            return root;
        }
        vector<int> lnums;
        vector<int> rnums;
        for(int i=0;i<len/2;i++){ //根结点的左边部分作为左子树
            lnums.push_back(nums[i]);
        }
        int p=len/2+1;
        while(p<len){//根节点的右边部分
             rnums.push_back(nums[p]);
             p++;
        }
        root->left=sortedArrayToBST(lnums);
        root->right = sortedArrayToBST(rnums);
        return root;
    }
};

//方法二：
//方法一用了两个vector，其实没必要，只用传整个数组+左右边界的位置即可
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums,0,nums.size()-1);
    }
    TreeNode* dfs(vector<int>& nums,int left, int right){
        
        if(right<left){
            return NULL;
        }
        int mid = (left+right)/2;//得到中间结点
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=dfs(nums,left,mid-1);
        root->right=dfs(nums,mid+1,right);
        return root;
    }
};


