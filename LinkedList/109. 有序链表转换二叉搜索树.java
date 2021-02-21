/*
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

*/

这个单链表是按升序排序的，我们只需找到他的中间节点，让他成为树的根节点，中间节点前面的就是根节点左子树的所有节点，中间节点后面的就是根节点右子树的所有节点。然后递归分别对左右子树进行相同操作

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
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        // write code here
        if(head==null){
            return null;
        }
        if(head.next==null){
            return new TreeNode(head.val);
        }
        //找到中间节点
        ListNode fast = head;
        ListNode slow = head;
        ListNode prev = null;
        while(fast!=null && fast.next!=null){
            prev = slow;
            fast = fast.next.next;
            slow = slow.next;
        }
        //将链表断开为两部分
        prev.next = null;
        TreeNode node = new TreeNode(slow.val);
        node.left = sortedListToBST(head);
        node.right = sortedListToBST(slow.next);
        return node;
    }
}
