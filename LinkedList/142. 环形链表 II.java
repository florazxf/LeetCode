/*
找到环形链表的入环节点
*/

//用快慢指针
//第一步：快指针走两步慢指针走一步找到相遇点
//第二步：head和相遇点同时向后走，相遇点即入环节点

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        int hasCycle=0;
        //判断是否有环
        while(fast!=NULL and fast->next!=NULL){
            fast=fast->next->next;
            slow = slow->next;
            if(fast==slow){
                hasCycle = 1;
                break;
            }
        }
        //找到入环节点
        if(hasCycle){ 
            slow = head;     //让head和fast同时向后走，相遇的地方就是入环的第一个节点。
            while(slow!=fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }else 
        {return NULL;}
    }
};

// 用java写的
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        boolean hasCycle = false;
        // 判断是否有环：找到第一次相遇点
        while(fast!=null && fast.next!=null){
            fast = fast.next.next;
            slow = slow.next;
            if(fast==slow){
                hasCycle = true;
                break;
            }
           
        }
        if(hasCycle){
            slow = head;
            //head 和 相遇点 一起往后走 相遇点即为入环点
            while(fast!=slow){
                fast = fast.next;
                slow = slow.next;
            }
            return fast;
        }
        else{
            return null;
        }
    }
}
