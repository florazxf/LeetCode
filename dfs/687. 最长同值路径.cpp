/*
给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。
注意：两个节点之间的路径长度由它们之间的边数表示。
示例 1:

输入:

              5
             / \
            4   5
           / \   \
          1   1   5
输出:
2

示例 2:
输入:

              1
             / \
            4   5
           / \   \
          4   4   5
输出:
2
*/

//方法一：
/*
做这个题就想到了那个最大路径和，因为都是路径可以是任意节点开始，那这种题我们每遍历一个结点其实都是要求两个值：
① 对父节点的贡献：是单边的，向下延伸与自己相同的最大深度，是左右子树的最大者
② 以当前结点为根节点的答案： 以自己为根节点就是把左右深度都加上，这个结果和全局的res来比较

这个自己都想到了，可是就是当前层那里不知道新创建 curLeft 和curRight ，如果和左结点值相等就curLef+1，和右子结点值相等就curRight+1
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
    int res=0;
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return res;    
    }

    int dfs(TreeNode* root){
        //递归终止条件
        if(root==NULL){
            return 0;
        }

        //得到左右子节点的深度
        int left = dfs(root->left);
        int right = dfs(root->right);

        //看自己的值和左右子节点的值是否相同，相同说明能d从当前节点向下延伸
        int curleft=0,curright=0;//向左延伸的最长箭头和向右延伸的最长箭头
        if(root->left&&root->val==root->left->val){//左节点的值和自己相等 那么就是左节点的深度+1
            curleft = left+1;
        }
        
        //进入下一层
        if(root->right&&root->val==root->right->val){
            curright = right+1; 
        }
        
        //回到本层，恢复状态
       
        res = max(res,curright+curleft); //对自己是根节点的话 就是左边走到自己再走到右边
      
        return max(curright,curleft);//返回给上一层的贡献就是左边和右边哪条路径长，就返回哪条
    }    
};
