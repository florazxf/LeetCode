/*
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

进阶：

你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
*/

// 归并排序
`时间复杂度：O(nlogn)`
`空间复杂度：O(logn)，递归调用的栈空间`

递归进行如下操作：
* 找到链表的中点，以中点为分界，将链表拆成两个子链表。
* 拆成的子链表进行排序
* 将排序后的子链表进行合并
递归的终止条件：链表的节点个数小于或等于1

class Solution {
public ListNode sortList (ListNode head) {
        // write code here
        return sortList(head,null);
    }
    public ListNode sortList(ListNode head,ListNode tail){
        // 递归终止条件
        if(head==null){
            return head;
        }
        if(head.next==tail){
            head.next = null;
            return head;
        }
        // 找到中间节点
        ListNode fast = head;
        ListNode slow = head;
        while(fast!=tail){
            fast = fast.next;
            slow = slow.next;
            if(fast!=tail){
                fast = fast.next;
            }
        }
        ListNode mid = slow;
        ListNode l1 = sortList(head,mid);
        ListNode l2 = sortList(mid,tail);
        //合并
        ListNode sorted = merge(l1,l2);
        return sorted;
    }
    public ListNode merge(ListNode head1,ListNode head2){
        ListNode head = new ListNode(0);
        ListNode l = head;
        while(head1!=null && head2!=null){
            if(head1.val<=head2.val){
                l.next = head1;
                head1 = head1.next;
            }
            else{
                l.next = head2;
                head2 = head2.next;
            }
            l = l.next;
        }
        l.next = head1==null?head2:head1;
        return head.next;
    }
}
