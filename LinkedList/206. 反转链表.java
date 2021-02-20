/*
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

*/

//方法一：迭代
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        while(curr!=null){
            ListNode temp = curr.next; //先把下一个节点存一下
            curr.next = prev; //当前的下一个节点是前一个结点 倒回去
            prev = curr;
            curr = temp;
        }
        return prev;
    }
}


// 方法二：递归
class Solution {
    public ListNode reverseList(ListNode head) {
        //base case
        if(head==null || head.next==null){ //只有当前结点一个结点则返回
            return head;
        }
        ListNode last = reverseList(head.next); //得到反转后的头结点
        head.next.next = head;
        head.next=null;
        return last;
    }
}
