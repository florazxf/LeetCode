/*
编写一个函数，检查输入的链表是否是回文的。

示例 1：
输入： 1->2
输出： false 

示例 2：
输入： 1->2->2->1
输出： true  

进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/

// 方法一：自己的想法
/*
1. 通过快慢指针得到链表的中间节点
2. 将后一段链表反转
3. 判断两个链表是否相等

注意点：
1. 比较完成后我们应该将链表恢复原样。虽然不需要恢复也能通过测试用例，但是使用该函数的人通常不希望链表结构被更改。
2. 该方法虽然可以将空间复杂度降到 O(1)O(1)，但是在并发环境下，该方法也有缺点。在并发环境下，函数运行时需要锁定其他线程或进程对链表的访问，因为在函数执行过程中链表会被修改。

*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode fast=head;
        ListNode slow=head;
        //通过快慢指针得到链表的中间节点
        while(fast!=null){
            slow = slow.next;
            fast = fast.next;
            if(fast!=null){
                fast = fast.next;
            }
        }
        //将后一段链表反转
        ListNode prev = null;
        ListNode curr = slow;
        while(curr!=null){
            ListNode tmp = curr.next;//存下一个节点
            curr.next = prev;//当前结点的下一个节点是前一个结点
            prev = curr;
            curr = tmp;
        }

        //判断两个链表是否相等
        while(prev!=null){
            if(head.val!=prev.val){
                return false;
            }
            head = head.next;
            prev = prev.next;
        }

        return true;
    }
}
