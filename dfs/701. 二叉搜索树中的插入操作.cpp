/*
给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 保证原始二叉搜索树中不存在新值。

注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果。

例如, 

给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和 插入的值: 5
你可以返回这个二叉搜索树:

         4
       /   \
      2     7
     / \   /
    1   3 5
或者这个树也是有效的:

         5
       /   \
      2     7
     / \   
    1   3
         \
          4

*/

//递归 自己做的
/*
时间复杂度：O(H)，其中 H 指的是树的高度。平均情况下 O(logN)，最坏的情况下O(N)。
空间复杂度：平均情况下 O(H)。最坏的情况下是 O(N)，是在递归过程中堆栈使用的空间。

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        TreeNode* head = root;
        dfs(root,val);
        return head;
        
    }
    void dfs(TreeNode* root,int val){
        if(root==nullptr){
            return ;
        }
        if(root->val<=val){
            if(root->right==nullptr){
                TreeNode* node = new TreeNode(val);
                root->right = node;
                return ;
            }
            else{
                insertIntoBST(root->right,val);
            }
        }
        else{
            if(root->left==nullptr){
                TreeNode* node = new TreeNode(val);
                root->left=node;
                return ;
            }
            else{
                insertIntoBST(root->left,val);
            }
        }
    }
};

//递归 题解
/*
自己写的太麻烦啦！!  插入肯定是插到叶节点的，所以只用在是叶节点的时候进行插入操作即可
*/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){
            return new TreeNode(val);
        }
        if(root->val<val){
            root->right = insertIntoBST(root->right,val);
        }
        else if(root->val>val){
            root->left = insertIntoBST(root->left,val);
        }
        return root;
        
    }

};

//迭代
/*
自己写的那种方法很容易改成迭代
空间复杂度O(1)

时间复杂度：O(H)，其中 H 指的是树的高度。平均情况下 O(logN)，最坏的情况下O(N)。

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* head = root;
        while(root!=nullptr){
            if(root->val<=val){
                if(root->right==nullptr){
                    TreeNode* node = new TreeNode(val);
                    root->right = node;
                    return head;
            }
            else{
                root = root->right;
            }
        }
        else{
            if(root->left==nullptr){
                TreeNode* node = new TreeNode(val);
                root->left=node;
                return head;
            }
            else{
                root = root->left;
            }
        }
        }
        return new TreeNode(val);
        
    }

};
