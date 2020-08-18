/*
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

*/


//方法一：
/*
1、 要会找链表的中间结点
2、 知道二叉搜索树的中序遍历是递增序列
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    ListNode* middleNode(ListNode* head, ListNode* end) { //找到链表的中间结点
    
        //设置快慢两个结点
        ListNode *fast = head;
        ListNode *low = head;
        //快结点每次走两步，慢结点每次走一步，当快结点为空或快结点的下一个结点为空时，low就是中间结点。
        while(fast!=end and fast->next!=end){
            fast = fast->next->next;
            low = low->next;
        }
        return low;
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        
        return dfs(head,nullptr);
    }
    TreeNode* dfs(ListNode* begin,ListNode* end){
        if(begin==end){
            return nullptr;
        }
        ListNode *mid = middleNode(begin,end); //找到链表的中间结点
        TreeNode* root = new TreeNode(mid->val);
        root->left = dfs(begin,mid);
        root->right = dfs(mid->next,end);
        return root;
    }
};
