/*
给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。

例如，

给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和值: 2
你应该返回如下子树:

      2     
     / \   
    1   3
在上述示例中，如果要找的值是 5，但因为没有节点值为 5，我们应该返回 NULL。
*/

//递归 自己做的
/*
时间复杂度 O(h) h是树的高度，平均时间复杂度是O(logn) 最坏是O(n)
空间复杂度 O(h) 递归深度为h，平均情况下深度为O(logn) 最坏是O(n)
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
    TreeNode* searchBST(TreeNode* root, int val) {

        if(root==NULL){
            return root;
        }

        if(root->val==val){
            return root;
        }
        else if(root->val<val){ //当前值小于val，那目标值肯定在其右子树
            return searchBST(root->right,val);
        }
        else{
            return searchBST(root->left,val);
        }

    }
};
//迭代 以后一定要想到用这种方式做
/*
时间复杂度 O(h) h是树的高度，平均时间复杂度是O(logn) 最坏是O(n)
空间复杂度O(1)
*/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        while(root){
            if (root->val==val){
                return root;
            }
            else if(root->val<val){ //当前值小于val，那目标值肯定在其右子树
                root = root->right;
            }
            else{
                root = root->left;
        }

        }
        return root;

    }
};
