/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
*/

// 迭代
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode head = new ListNode();
        ListNode l = head;

        while(l1!=null && l2!=null){
    
            if(l1.val<=l2.val){
                l.next = l1;
                l1 = l1.next;
            }
            else{
                l.next = l2;
                l2 = l2.next;
            }

            l = l.next;
        }
        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        l.next = l1==null?l2:l1;
        return head.next;

    }
}
