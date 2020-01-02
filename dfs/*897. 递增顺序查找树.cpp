/*
给定一个树，按中序遍历重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点。

 

示例 ：

输入：[5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \ 
1        7   9

输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9  
 

提示：

给定树中的结点数介于 1 和 100 之间。
每个结点都有一个从 0 到 1000 范围内的唯一整数值。

*/
//这道题自己没做出来
//方法一：
//第一步：中序遍历生成数组，第二步：根据数组生成树
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
    vector<int> ans;      
    TreeNode* increasingBST(TreeNode* root) {
          dfs(root);//生成中序遍历数组
          TreeNode* p = new TreeNode(ans[0]);
          generate(p,1);//根据数组生成树
          return p;

    }
    void generate(TreeNode* p,int index){
        if(index==ans.size()){
            return ;
        }
        TreeNode* current = new TreeNode(ans[index]);
        p->left = NULL;
        p->right = current;
        generate(p->right,index+1);
    }
    void dfs(TreeNode* root){ //中序遍历得到数组ans

        if(!root){
            return ;
        }
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
        return ;
    }
};
//方法二
//生成树不需要再弄个递归
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
    vector<int> ans;      
    TreeNode* increasingBST(TreeNode* root) {
          dfs(root);//生成中序遍历数组
          TreeNode* p = new TreeNode(ans[0]);
          TreeNode* cur = p;
          for(int i=1;i<ans.size();i++){
              cur->right = new TreeNode(ans[i]);
              cur=cur->right;
          }
          
          return p;

    }
    void dfs(TreeNode* root){ //中序遍历得到数组ans

        if(!root){
            return ;
        }
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
        return ;
    }
};

//方法三：在遍历的时候直接生成树
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
    TreeNode* p;
    TreeNode* increasingBST(TreeNode* root) {
          p = new TreeNode(0);
          TreeNode* t = p;//头结点
          dfs(root);//中序遍历生成树
          return t->right;

    }
    void dfs(TreeNode* root){ //中序遍历得到数组ans
        if(!root){
            return ;
        }
        dfs(root->left);
        TreeNode *n = new TreeNode(root->val);
        p->right = n;
        p = n;
        dfs(root->right);
        return ;
    }
};
