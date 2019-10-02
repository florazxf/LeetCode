/*
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
*/

//方法一：递归
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
    ListNode* reverseList(ListNode* head) {
        
        
        if(head==NULL||head->next==NULL){ //空链或只有一个结点直接返回它本身
            return head;
        }
        else{
        //定义三个结点分别指向相邻的结点
            ListNode *new_head = reverseList(head->next);//反转以第二个结点为头的子链表
            
            // 将之前的头结点放入子链尾
            head->next->next = head;
            head->next = NULL;
            return new_head;
        }

        
        
    }
};

//方法二： 迭代
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL){ //空链或只有一个结点直接返回它本身
            return head;
        }
        else{
        //定义三个结点分别指向相邻的结点
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        ListNode* p3 = p2->next;
        
 
        while(p2){
            p3=p2->next;
            p2->next = p1;  //第二个结点指向第一个结点进行反转
            p1 = p2;       //第一个结点向后移
            p2 = p3;       //第二个结点向后移
        }
        head->next = NULL;
        head = p1;
        return head;
        }
    }
};
