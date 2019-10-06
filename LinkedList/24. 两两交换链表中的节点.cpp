/*给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.
*/

//方法一：递归
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        //整个递归的终止条件：只剩下一个结点或者没结点了就没得交换了 ，返回已经处理好的链表
        if(head==NULL or head->next==NULL){
            return head;
        }
        
        //由于递归只考虑本级递归，所以对我们来说本级递归只有head、head->next和已经处理完的链表部分
        //我们要做的就是把这三个节点中的前两个结点交换
        
        ListNode *next = head->next;
        head->next = swapPairs(head->next->next);
        next->next = head;
        
        //返回给上一级的应该是已经交换好的链表
        return next;
        
    }
};
