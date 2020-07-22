/*

给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11

*/
//方法一：双重dfs

/*
因为题目说的是不是从根节点开始，那我们可以把每个节点当成根节点进行dfs，得到以该结点为根节点的满足条件的值
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
 //4:17
class Solution {
public:
    int ans=0;
    int pathSum(TreeNode* root, int sum) {
        
        if(root==NULL){
            return ans;
        }
        dfs(root,sum); //以每个节点作为起始结点 DFS寻找满足条件的路径和

        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return ans;
    }
    void dfs(TreeNode* root, int sum){
        if(root==NULL){
            return;
        }
        sum-=root->val;
        if(sum==0){
            ans++;
        }
        dfs(root->left,sum);
        dfs(root->right,sum);
    
    }
};

//方法二： 前缀和
