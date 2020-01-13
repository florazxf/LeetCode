/*
给你一棵二叉树，请你返回层数最深的叶子节点的和。
输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
输出：15
*/

//方法一：
//官方题解把当l>maxd的时候就把sum的初始值设为当前结点的值，这是当时我做的时候没有想到的
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
    int maxd=-1;
    int sum=0;
    int deepestLeavesSum(TreeNode* root) {
        dfs(root,0); 
        return sum;
    }
    void dfs(TreeNode* root,int l){//得到二叉树的深度
        if(!root){
            return ;
        }
        if(l>maxd){ //当前深度比最大深度大，则更新maxd和sum
            maxd=l;
            sum=root->val;//sum的初始值为当前结点的值
        }
        else if(l==maxd){
            sum+=root->val;
        }
        dfs(root->left,l+1);
        dfs(root->right,l+1);

    }



};

//方法二：
//先得到最大深度再看当前的深度是否等于最大深度，若等于就加当前结点的权值

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
    int maxd=0;
    int sum=0;
    int deepestLeavesSum(TreeNode* root) {
        dfs(root,0); //得到二叉树的深度
        lsum(root,0);
        return sum;
    }
    void dfs(TreeNode* root,int l){//得到二叉树的深度
        if(!root){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            if(l>maxd){
                maxd=l;
            }
            return ;
        }
        l++;
        dfs(root->left,l);
        dfs(root->right,l);

    }

    void lsum(TreeNode* root,int l){
        if(!root){
            return ;
        }

        if(root->left==NULL && root->right==NULL){
            if(l==maxd){
            sum+=root->val;
        }

            return ;
        }
        l++;

        lsum(root->left,l);
        lsum(root->right,l);

    }

};
