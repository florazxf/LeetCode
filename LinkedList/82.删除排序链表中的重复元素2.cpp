/*
给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

示例 1:

输入: 1->2->3->3->4->4->5
输出: 1->2->5
示例 2:

输入: 1->1->1->2->3
输出: 2->3

*/

//2.21 


* 需要一个虚拟头节点dummyHead，用prev指向dummyHead，用prev来控制新的链表的连接
这样在删除重复节点后，剩余节点就挂在prev之后
* 当有重复节点，prev.next = difNode prev的下一个节点为和前面不重复的，这样就把之前那些重复的都删了
* 没有重复节点，prev = curr



public class Solution {
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    public ListNode deleteDuplicates (ListNode head) {
        // write code here
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        ListNode prev = dummyHead;
        ListNode curr = prev.next;
        boolean hasRepeatNode = false;
        while(curr!=null){
            hasRepeatNode = false;
            ListNode difNode = curr.next;
            while(difNode!=null && difNode.val==curr.val){
                difNode = difNode.next;
                hasRepeatNode = true;
            }
            if(hasRepeatNode){// 有重复节点
                prev.next = difNode;
            }
            else{
                prev = curr;
            }
            curr = difNode;
        }
        return dummyHead.next;
    }
}




//方法一：迭代
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *a = new ListNode(0);
        ListNode *b = new ListNode(0);
        int flag=0;
        dummy->next = head; //创建一个哑结点
        a = dummy;
        if(a->next==NULL or a->next->next==NULL) //是空结点或只有一个结点
        {
            return head;
        }
    
        else if(a->next->next->next==NULL)//有两个结点
        {
            if(a->next->val==a->next->next->val){return NULL;}
            else{return head;}
        }
        else{
            b = a->next;
            
            while(b!=NULL and b->next!=NULL){
                
                while(b->val==b->next->val){ 
                     flag=1;

                    b->next = b->next->next; 
                    if(b->next==NULL)
                    {
                        break;
                    }
                   
                }
                if(flag==1){//有重复元素
                    flag=0;
                    if(a==NULL){break;}
                a->next = b->next;
                }
            else{ //没有要删除的结点
                a=a->next;
            }
                b = a->next;
            }
        }
        return dummy->next;  
        }
        
        
    
};

//方法二：递归

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL or head->next==NULL){return head;}
        
        if(head->val==head->next->val){
            while(head->next!=NULL and head->val==head->next->val){
                head=head->next;
            }
            return deleteDuplicates(head->next);
        }
        else{
            head->next = deleteDuplicates(head->next);
        }
        
        return head;
        }  
    
};
