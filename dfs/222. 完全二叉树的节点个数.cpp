/*
给出一个完全二叉树，求出该树的节点个数。

说明：

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

示例:

输入: 
    1
   / \
  2   3
 / \  /
4  5 6

输出: 6

*/

//方法一：自己做的 没有用到完全二叉树的性质
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
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return countNodes(root->left)+countNodes(root->right)+1;

    }
};
//方法二： 二分 递归
/*
完全二叉树的定义：它是一棵空树或者它的叶子节点只出在最后两层，若最后一层不满则叶子节点只在最左侧。
满二叉的节点个数: 如果满二叉树的层数为h，则总节点数为：2^h - 1.

那么我们来对root节点的左右子树进行高度统计，分别记为left和right,有以下两种结果：

left == right。这说明，左子树一定是满二叉树，因为节点已经填充到右子树了，左子树必定已经填满了。所以左子树的节点总数我们可以直接得到，是2^left - 1，加上当前这个root节点，则正好是2^left。再对右子树进行递归统计。
left != right。说明此时最后一层不满，但倒数第二层已经满了，可以直接得到右子树的节点个数。同理，右子树节点+root节点，总数为2^right。再对左子树进行递归查找。
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
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        //计算左子树和右子树的高度
        int left = countLevel(root->left);
        int right = countLevel(root->right);
        
        if(left!=right){//最后一层不满，但倒数第二层已经满了，可以直接得到右子树的节点个数
            return countNodes(root->left)+(1<<right);
        }
        else{//左子树是满二叉树
            return countNodes(root->right)+(1<<left);//如何计算2^left，最快的方法是移位计算
        }

    }

    int countLevel(TreeNode* root){ //利用完全二叉树的性质求高度
        int level=0;
        while(root!=NULL){
            level++;
            root=root->left;
        }
        return level;
    }
};
//方法三：二分 迭代
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
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int count =0;
        //计算左子树和右子树的高度
        int left = countLevel(root->left);
        
        while(root!=NULL){
            int right = countLevel(root->right);
            if(left!=right){//最后一层不满，但倒数第二层已经满了，可以直接得到右子树的节点个数
                root = root->left;
                count+=1<<right;
            }
            else{//左子树是满二叉树
                root = root->right;
                count+=1<<left;
            }
            left--;

        }

        return count;
    }

    int countLevel(TreeNode* root){ //利用完全二叉树的性质求高度
        int level=0;
        while(root!=NULL){
            level++;
            root=root->left;
        }
        return level;
    }
};
