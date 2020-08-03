/*
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。
说明： 要求算法时间复杂度为 O(h)，h 为树的高度。

示例:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。

一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。

    5
   / \
  4   6
 /     \
2       7

另一个正确答案是 [5,2,6,null,4,null,7]。

    5
   / \
  2   6
   \   \
    4   7
*/


//递归
/*
第一步：找到要删除的值
第二步：①要删除的是叶节点，直接删除
      ② 要删除的节点有右子树，则用右子树中的最小值来代替，并删除这个最小值。 右子树中的最小值就是一直找左结点找到叶子节点
      ③ 要删除的结点有左子树，则用左子树的最大值来代替，并删除这个最大值。 左子树中的最大值就是一直找右节点找到叶子节点
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
    TreeNode* getMax(TreeNode* root){
        while(root->right){
            root=root->right;
        }
        return root;
    }
    TreeNode* getMin(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->val<key){ //值在右边
            root->right = deleteNode(root->right,key);
        }
        else if(root->val>key){
            root->left = deleteNode(root->left,key);
        }
        else{//删除当前值
            if(root->left==NULL && root->right==NULL){
                root=NULL;
            }
            else if(root->right){ //有右子树，找到右子树中最小的值来代替
                TreeNode* MinNode=getMin(root->right);
                root->val = MinNode->val;
                root->right = deleteNode(root->right,MinNode->val);
            }
            else{//有左子树，找到最子树中最大的值来代替
                TreeNode* MaxNode = getMax(root->left);
                root->val = MaxNode->val;
                root->left = deleteNode(root->left,MaxNode->val);
            }
        }
        return root;
    }
};
