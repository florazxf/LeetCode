/*
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

 

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

 

注意：两结点之间的路径长度是以它们之间边的数目表示。

*/


/*
因为先做的是[687.最长同值路径](https://github.com/florazxf/LeetCode/blob/master/dfs/687.%20%E6%9C%80%E9%95%BF%E5%90%8C%E5%80%BC%E8%B7%AF%E5%BE%84.cpp) 
这道题比那道简单，不用判断子节点和自己的值是否相等， 直接获取左子节点的深度left和右子节点的深度right，然后 同样是left+right和全局ans比， max(left,right)+1是返回给上一个结点的贡献
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
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;

    }

    int dfs(TreeNode* root){

        if(root==NULL){
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        ans = max(ans,left+right); //本节点为根节点
        return max(left,right)+1; //给父节点的贡献
    }
};
