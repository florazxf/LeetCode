/*
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

*/

//方法一：
//递归方法是分别遍历一个节点的右节点和左节点，因为是从右边看过来，所以我们需要首先遍历右节点。
/*
这里有个疑问，当遍历左节点时候，怎么判定它右边没有其他节点了呢？
就是我们判断当前数组已经保存的个数是否和当前层的高度相等， 如果高度相等证明此结点是最右边的结点，就把当前结点push进去
如果高度不等证明当前层已经有结点push进去了
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans,0);  
        return ans;
    }

    void dfs(TreeNode* root,vector<int>& ans, int height){
        if(!root){
            return ;
        }
        if(ans.size()==height){//当前的高度和已经保存的结点数目相等，证明当前高度的右边还没有保存，此结点就是最右边的
            ans.push_back(root->val);
        }
        //先遍历右边
        dfs(root->right,ans,height+1);
        //再遍历左边
        dfs(root->left,ans,height+1);
    }


};


//方法二：自己的方法
//其实方法一的思想和方法二是一样的，就是做了画蛇添足的部分

//做了好长时间，主要想的是弄一个全局变量h为当前右边保存的高度，当左边的大于h后就保存左边的最大节点
//蠢的地方在于还分情况讨论当前结点是否属于要保存的结点，实际根本无需区分
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
    int h=0;
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans,1,1);  
        return ans;
        
    }
    void dfs(TreeNode* root, vector<int> &ans,int flag,int trueheight){
        if(!root){
            return ;
        }
        if(flag==1){//当前结点是最右的结点，被push进去
            ans.push_back(root->val);
            h++;
            //cout<<h;
            if(root->right==NULL&&root->left==NULL){//叶节点
                return ;
            }
            
            else if(root->right!=NULL){//右节点有值
                //h++;
                dfs(root->right,ans,1,trueheight+1);//右节点为下一个被push的节点
                dfs(root->left,ans,0,trueheight+1);
            }
            else{//只有左节点有值
                //h++;
                dfs(root->left,ans,1,trueheight+1);//左结点为下一个被push的结点
            }
        }
        else{
            if(trueheight+1>h){ //孩子结点的高度大于h
                if(root->right!=NULL){
                    dfs(root->right,ans,1,trueheight+1);
                    dfs(root->left,ans,0,trueheight+1);
                }
                else{
                    dfs(root->left,ans,1,trueheight+1);
                }
                
            }
            else{
                dfs(root->right,ans,0,trueheight+1);
                dfs(root->left,ans,0,trueheight+1);
                

            }
     
        }
        
    }
};

