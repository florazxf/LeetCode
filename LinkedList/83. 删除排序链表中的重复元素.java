/*给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3

*/


// 2.20 自己用java写的

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode l = head;
        while(l!=null && l.next!=null){
            if(l.next.val==l.val){ //相等就删除下一个节点
                l.next = l.next.next;
            }
            else{ //直到不相等才指向下一个节点
                l = l.next;
            }
            
        }
        return head;

    }
}



//方法一
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        while(p!=NULL and p->next!=NULL){
            if(p->next->val==p->val){  //如果当前值和下一个节点值相等
                p->next = p->next->next; //则删除下一个结点
  
            }
            else{
                p = p->next;   
            }    
        }
        return head;
        
    }
};

//方法二 ：递归
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        //第一步：找终止条件，head指向链表只剩下一个元素的时候
        if(head==NULL or head->next==NULL){
            return head;
        }
        //第二步: 本级递归需要做什么
        head->next = deleteDuplicates(head->next);
        if(head->val==head->next->val){
            head = head->next;
        }
        //第三步：返回值是什么
        return head;
    }
};
