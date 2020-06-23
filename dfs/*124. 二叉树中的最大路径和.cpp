/*

给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
输入: [1,2,3]
输出: 6

输入: [-10,9,20,null,null,15,7]
输出: 42

*/
//题解的方法
/*
自己没有思路，看题解做的
①主要是要掌握 对于二叉树的一个结点，该结点的最大路径和取决于该结点的值与该节点左右子节点的最大贡献值
②一个结点的最大贡献值为以该结点为根节点的子树中寻找以该节点为起点的一条路径，使得该路径上的结点值之和最大

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
    int maxSum = 0;//最大路径和
    int maxGain(TreeNode* root){//每个结点的最大贡献值
        if(root==NULL){ 
            return 0;
        }
        
        //计算左右结点的最大贡献值
        int leftmaxG = max(maxGain(root->left),0);//最大贡献值大于0，才选该节点
        int rightmaxG = max(maxGain(root->right),0);

        //对于二叉树的一个结点，该结点的最大路径和取决于该结点的值与该节点左右子节点的最大贡献值

        int pricenewpath = root->val+leftmaxG+rightmaxG; //该结点的最大路径和

        maxSum = max(pricenewpath,maxSum);

        //放回结点的最大贡献值
        return root->val+max(leftmaxG,rightmaxG);
    }
    int maxPathSum(TreeNode* root) {

        maxGain(root);
        return maxSum;
    }
};
