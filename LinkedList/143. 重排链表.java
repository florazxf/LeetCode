/*
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
*/


//方法一：找链表中点 + 链表逆序 + 合并链表

/*
时间复杂度：O(N)，其中 N 是链表中的节点数。

空间复杂度：O(1)。
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public void reorderList(ListNode head) {

        while(head==null){
            return ;
        }
        
        //1. 找到链表的中间结点
        ListNode low = head; //中间结点
        ListNode fast=head;
        while(fast!=null && fast.next!=null){
            fast = fast.next.next;
            low = low.next;
        }

        ListNode l1 = head;
        ListNode l2 = low.next;
        low.next=null;//要断开

        //2. 反转后半段链表
        ListNode prev = null;//反转后链表的首节点
        ListNode curr = l2;
        while(curr!=null){
            ListNode tmp = curr.next;
            curr.next=prev;
            prev = curr;
            curr = tmp;
        }


        //3. 将原链表的两端合并
        mergeList(l1,prev);
        
    }

        public void mergeList(ListNode l1, ListNode l2) {
        ListNode l1_tmp;
        ListNode l2_tmp;
        while (l1 != null && l2 != null) {
            l1_tmp = l1.next;
            l2_tmp = l2.next;

            l1.next = l2;
            l1 = l1_tmp;

            l2.next = l1;
            l2 = l2_tmp;
        }
    }

}

//方法二：线性表

/*
因为链表不支持下标访问，所以我们无法随机访问链表中任意位置的元素。

因此比较容易想到的一个方法是，我们利用线性表存储该链表，然后利用线性表可以下标访问的特点，直接按顺序访问指定元素，重建该链表即可。
时间复杂度：O(N)，其中 N 是链表中的节点数。

空间复杂度：O(N)，其中 N 是链表中的节点数。主要为线性表的开销。
*/
class Solution {
    public void reorderList(ListNode head) {
        if (head == null) {
            return;
        }
        List<ListNode> list = new ArrayList<ListNode>();
        ListNode node = head;
        while (node != null) {
            list.add(node);
            node = node.next;
        }
        int i = 0, j = list.size() - 1;
        while (i < j) {
            list.get(i).next = list.get(j);
            i++;
            if (i == j) {
                break;
            }
            list.get(j).next = list.get(i);
            j--;
        }
        list.get(i).next = null;
    }
}
