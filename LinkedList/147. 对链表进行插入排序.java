/*
使用插入排序对链表进行排序。
示例 1：

输入: 4->2->1->3
输出: 1->2->3->4
*/

class Solution {
    public ListNode insertionSortList(ListNode head) {
        if(head==null){
            return head;
        }
        // write code here
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        // 已排序部分的最后一个节点
        ListNode lastSorted = head;
        //待插入的元素
        ListNode curr = head.next;
        while(curr!=null){
            if(curr.val>=lastSorted.val){
                //lastSorted = lastSorted.next;
                lastSorted = curr;
            }
            else{
                ListNode prev = dummyHead;
                //prev向后移，直到找到curr的插入位置
                while(prev.next.val<=curr.val){
                    prev = prev.next;
                }
                lastSorted.next = curr.next;
                //将curr插入
                curr.next = prev.next;
                prev.next = curr;
            }
            curr = lastSorted.next;
        }
        return dummyHead.next;
    }
}
