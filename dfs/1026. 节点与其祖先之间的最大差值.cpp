/*
给定二叉树的根节点 root，找出存在于不同节点 A 和 B 之间的最大值 V，其中 V = |A.val - B.val|，且 A 是 B 的祖先。

（如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先）
输入：[8,3,10,1,6,null,14,null,null,4,7,13]
输出：7
解释： 
我们有大量的节点与其祖先的差值，其中一些如下：
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
在所有可能的差值中，最大值 7 由 |8 - 1| = 7 得出。

提示：
树中的节点数在 2 到 5000 之间。
每个节点的值介于 0 到 100000 之间。
*/

//方法一：把当前结点的祖先都push到数组a中，然后把当前结点的值和其所有祖先的值一一比较
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
    int V=0;
    int maxAncestorDiff(TreeNode* root) {
        vector<int> a;//把当前结点的祖先都push到数组a中
        dfs(root,a);
        return V;
    }
    void dfs(TreeNode* root,vector<int> a){
        if(root==NULL){
            return ;
        }

        for(int i=0;i<a.size();i++){//当前结点和祖先的值一一比较
            if(abs(root->val-a[i])>V){
                V=abs(root->val-a[i]);
            }
        }
        if(root->left==NULL&&root->right==NULL){ 
            return ;
        }
        a.push_back(root->val);
        dfs(root->left,a);
        dfs(root->right,a);

    }
};
//方法二：
//因为和祖先的最大差值，最大差值的产生只会是和祖先结点最大值或者最小值产生，所以dfs遍历结点的时候只用把最大值和最小值记录下来，再求差值即可
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
    int V=0;
    int maxAncestorDiff(TreeNode* root) {
        dfs(root,root->val,root->val);//把当前遍历过的结点的最大值和最小值保留
        return V;
    }
    void dfs(TreeNode* root,int Max,int Min){
        if(root==NULL){
            return ;
        }

        int tmp=root->val;
        if(tmp>Max){ //当前遍历过结点中的最大值
            Max=tmp;
        }
        if(tmp<Min){ //当前遍历过结点中的最小值
            Min=tmp;
        }
        int dif=max(Max-tmp,tmp-Min); //得到当前节点和祖先的最大差值
        if(dif>V){
            V=dif;
        }
        if(root->left==NULL&&root->right==NULL){ 
            return ;
        }
        
        dfs(root->left,Max,Min);
        dfs(root->right,Max,Min);

    }
};
