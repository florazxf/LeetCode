/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
        ListNode *head = new ListNode(0); //创建一个合并后的链表
        ListNode *l3 = head; //最后用来返回
        
        while(l1!=NULL and l2!=NULL){
                if(l1->val<=l2->val){
                    head->next = l1;
                    l1 = l1->next;
                    head = head->next;
                }
                else{
                    head->next = l2;
                    l2 = l2->next;
                    head = head->next;
                }
        }  
        
        //最后还会剩下一个结点
        
        if(l1!=NULL){
            head->next = l1;
        }
        else{
            head->next = l2;
        }
        
        return l3->next;

    }
};
