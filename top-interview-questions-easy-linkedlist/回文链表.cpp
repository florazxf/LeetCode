/*
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL or head->next==NULL){
            return true;
        }
        
        ListNode *pre = head;
        ListNode *lst = head->next;
        ListNode *cur = new ListNode(0);
        ListNode *q = new ListNode(0);
        ListNode *p = new ListNode(0);
        
        //找到链表的中间结点
        while(lst!=NULL  and lst->next!=NULL){
            lst = lst->next->next; //lst向后走两步
            pre = pre->next;       //pre向后走一步
        }
        //把链表分成两部分
        cur = pre->next;
        pre->next=NULL; //前半部分的尾结点赋值为NULL
        p = NULL; //后半部分的尾结点赋值为NULL
        
        //把后半部分的链表反转
        while(cur!=NULL){
            q = cur->next;
            cur->next = p;
            p = cur;
            cur = q;
        }
        
        //比较前半部分的链表和反转后的后半部分的链表是否一样
        while(p!=NULL and head!=NULL){
            
            if(head->val!=p->val){
                return false;
            }
            head = head->next;
            p = p->next;
        }
        
        return true;
        
    }
};
