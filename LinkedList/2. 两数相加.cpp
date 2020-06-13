/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

//方法一：自己写的
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* l=new ListNode;
        ListNode* head=new ListNode;
        l=head;
        int jinwei=0;
        int sum;
        while(l1!=NULL&&l2!=NULL){

            ListNode* p = new ListNode;
            sum = l1->val+l2->val+jinwei;//取l1的值和l2的值相加
            p->val = sum%10;
            l->next = p;
            l=p;
            jinwei = sum/10;//进位
            l1=l1->next;
            l2=l2->next;
            
        }
        
        while(l1!=NULL){ //l1比l2长
            ListNode* p = new ListNode;
            sum = l1->val+jinwei;
            p->val = sum%10;
            l->next = p;
            l=p;
            jinwei = sum/10;
            l1=l1->next;
                
        }

        while(l2!=NULL){//l2比l1长
            ListNode* p = new ListNode;
            sum = l2->val+jinwei;
            p->val = sum%10;
            l->next = p;
            l=p;
            jinwei = sum/10;
            l2=l2->next;
                
        }
        if(jinwei){ //最后一位有进位
            ListNode* p = new ListNode;
            p->val = jinwei;
            l->next=p;
        }

        return head->next;
        
    }
};
//方法二：
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* l=new ListNode;
        ListNode* head=new ListNode;
        l=head;
        int carry=0;
        int sum;
        while(l1!=NULL||l2!=NULL){

            
            int l1val = l1!=NULL?l1->val:0;
            int l2val = l2!=NULL?l2->val:0;
            sum = l1val+l2val+carry;//取l1的值和l2的值相加
            carry = sum/10;//进位

            ListNode* p = new ListNode;
            p->val = sum%10;
            l->next = p;
            l=p;
            
            if(l1!=NULL){l1=l1->next;}
            if(l2!=NULL){l2=l2->next;}
            
            
        }
        

        if(carry){ //最后一位有进位
            ListNode* p = new ListNode;
            p->val = carry;
            l->next=p;
        }

        return head->next;
        
    }
};
