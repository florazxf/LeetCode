/*
二叉搜索树中的两个节点被错误地交换。

请在不改变其结构的情况下，恢复这棵树。

示例 1:

输入: [1,3,null,null,2]

   1
  /
 3
  \
   2

输出: [3,1,null,null,2]

   3
  /
 1
  \
   2
示例 2:

输入: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

输出: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
进阶:

使用 O(n) 空间复杂度的解法很容易实现。
你能想出一个只使用常数空间的解决方案吗？
*/

/*
首先想到二叉搜索树的中序遍历为递增序列，现在有两个元素的被交换了，也就是我们要在中序遍历中把两个被交换的元素找出来。
所需的知识就是 中序遍历+在几乎排序的数组中查找两个交换的元素
我们之前总结了中序遍历的方式有递归、迭代，Morris。 这道题只是在遍历的时候判断当前结点是否比前驱节点大，因此这道题还是能用这三种方法写
*/
//方法一： 递归
/*
空间复杂度:O(h) h为树的高度，平均空间复杂度为O(logn) n为二叉树节点的个数
时间复杂度：最好的情况下是 O(1)；最坏的情况下是交换节点之一是最右边的叶节点时，此时是O(N)。
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
    TreeNode* x = nullptr;
    TreeNode* y = nullptr;
    TreeNode* prev = nullptr;
    void swap(TreeNode* x, TreeNode* y){
        int tmp = x->val;
        x->val = y->val;
        y->val = tmp;
    }
    void recoverTree(TreeNode* root) {
        traversal(root); //找到两个被错误交换的结点
        swap(x,y);
    }
    void traversal(TreeNode* root){//中序遍历
        if(root==nullptr){
            return ;
        }
        traversal(root->left);
        if(prev!=nullptr && root->val<prev->val){//中序遍历是递增序列，当前结点比前驱节点小，证明找到一个
            y = root;
            if(x==nullptr){
                x=prev;
            }
            else{//两个错误交换的结点都被找到
                return ;
            }
        }
        prev = root;
        traversal(root->right);
    }
};
//方法二：Morris遍历
/*
时间复杂度:O(n) 访问每个节点两次
空间复杂度:O(1)

遍历的时候，在每个节点上我们需要决定下一个遍历的方向：是遍历左子树还是遍历右子树。Morris的思想就是在节点和他的直接前驱之间设一个临时的链接predecessor->right = root.
所以就是遍历到root的时候 我们先找到他的直接前驱predecessor，（先root-left 然后一直->right直到右子树为0或为root就找到直接前驱了）
如果没有链接即predecessor->right==NULL,则建立链接，走向root->left【这是第一次遍历root结点，因此前序遍历的时候是在这里操作】
如果有链接，即predecessor->right==root，则断开连接，走向root->right 【这是第二次遍历root结点，因此中序遍历的时候是在这里操作】
*/
class Solution {
public:

    void swap(TreeNode* x, TreeNode* y){
        int tmp = x->val;
        x->val = y->val;
        y->val = tmp;
    }
    void recoverTree(TreeNode* root) {
        
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        TreeNode* prev = nullptr;
        TreeNode* processor = nullptr;
        while(root!=nullptr){

            if(root->left){
                processor = root->left;
                while(processor->right!=nullptr&&processor->right!=root){
                    processor=processor->right;
            }
            if(processor->right==nullptr){//第一次遍历到
                processor->right = root;
                root=root->left;
            }
            else{//第二次遍历到，root->left已经遍历完了，要遍历右子树了
                //找到交换的结点
                if(prev!=nullptr&&root->val<prev->val){
                    y = root;
                    if(x==nullptr){
                        x = prev;
                    }
                }
                prev = root;
                processor->right=nullptr;//断开连接
                root=root->right;
            }
        }
        else{//没有左子树，直接遍历右子树

            if(prev!=nullptr&&root->val<prev->val){
                    y = root;
                    if(x==nullptr){
                        x = prev;
                    }
            }
            prev = root;
            root = root->right;
        }

        }

        swap(x,y);

    }

};
//方法三：迭代
/*
用之前学到的迭代的方法 在相应的位置加入适当的操作
*/
class Solution {
public:

    void swap(TreeNode* x, TreeNode* y){
        int tmp = x->val;
        x->val = y->val;
        y->val = tmp;
    }
    void recoverTree(TreeNode* root) {
        
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        TreeNode* prev = nullptr;
        stack<TreeNode*>stk;
        if(root!=nullptr){
            stk.push(root);
        }
        while(!stk.empty()){
            TreeNode* t = stk.top();
            stk.pop();
            if(t!=nullptr){
                //中序遍历 left->node->right 所以right先入栈
                if(t->right)
                    stk.push(t->right);

                stk.push(t);
                stk.push(nullptr);
                
                if(t->left)
                    stk.push(t->left);
            }
            else{
                TreeNode* cur = stk.top();
                if(prev!=nullptr &&cur->val<prev->val){
                    y = cur;
                    if(x==nullptr){
                        x = prev;
                    }
                    else{
                        break;
                    }
                }
                prev = stk.top();
                stk.pop();
            }
        }
        swap(x,y);

    }

};
