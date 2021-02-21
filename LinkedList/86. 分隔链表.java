/*给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

*/


//2.21 用java写的
public class Solution {
    /**
     * 
     * @param head ListNode类 
     * @param x int整型 
     * @return ListNode类
     */
    public ListNode partition (ListNode head, int x) {
        // write code here
        // 哑节点指向两个链表的头部
        ListNode l1 = new ListNode(0);
        ListNode l2 = new ListNode(0);
        // 指针指向两个链表的尾部
        ListNode l1_curr = l1;
        ListNode l2_curr = l2;
        while(head!=null){
            if(head.val<x){
                l1_curr.next = head;
                l1_curr = l1_curr.next;
            }
            else{
                l2_curr.next = head;
                l2_curr = l2_curr.next;
            }
            head = head.next;
        }
        l1_curr.next = l2.next;
        l2_curr.next= null;
        return l1.next;
    }
}



class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *before = new ListNode(0);//创建before链来放值小于x的结点
        ListNode *after = new ListNode(0); //创建after链来放值大于等于x的结点
        ListNode *newhead = before;
        ListNode *newafter = after;
        while(head!=NULL){
            if(head->val<x)
            {
                before->next = head;
                before = before->next;
            }
            else{
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        after->next = head; //这一步一定要注意，最后尾结点要为NULL，否则return的时候一直会超时
        before->next = newafter->next; //把before和after连起来
        return newhead->next;
    }
};
