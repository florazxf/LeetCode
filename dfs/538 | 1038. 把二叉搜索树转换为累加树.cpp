/*
给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

 

例如：

输入: 原始二叉搜索树:
              5
            /   \
           2     13

输出: 转换为累加树:
             18
            /   \
          20     13

1038: 和538一模一样
给出二叉 搜索 树的根节点，该二叉树的节点值各不相同，修改二叉树，使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

提醒一下，二叉搜索树满足下列约束条件：

节点的左子树仅包含键 小于 节点键的节点。
节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。

*/

/*
首先知道二叉搜索树是什么：

知道以后就知道根节点的右子树比自己大，左子树比自己小 。 题目要的是把每个节点的值加上所有大于它的节点，那就是把右子树的值都加上

所以我们只需先遍历右子节点，然后把当前结点的值加上所有遍历过的节点的值， 在遍历左子节点. 即反序中序遍历（从右到左的中序遍历）
*/


//方法一：自己写了另外的dfs
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
    TreeNode* convertBST(TreeNode* root) {

        //TreeNode* newroot;
        int sum=0;
        dfs(root,sum);
        return root;

    }

    void dfs(TreeNode* root,int& sum){
        if(root==NULL){
            return ;
        }
        
        //int temp = root->val;
        //右
        dfs(root->right,sum);//先遍历右子树，返回的sum就是比root->val大的所有节点

        //中
        sum+=root->val;
        root->val = sum;
        

        //左
        dfs(root->left,sum);
        
    }
};

//方法二：题解
/*
根据这个模版，看到题 想起初应该以什么方式遍历它  套这个模版即可
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
    int sum=0;
    TreeNode* bstToGst(TreeNode* root) {

        if(root!=NULL){
            //右
            bstToGst(root->right);
            //根节点： 根节点的值需要被刚刚遍历过的所有右节点的值更新
            sum+=root->val; //遍历过的结点的值
            root->val=sum;//更新
            //左
            bstToGst(root->left);
        }
        return root;

    }
};
