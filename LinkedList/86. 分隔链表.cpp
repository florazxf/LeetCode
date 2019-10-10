/*给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

*/

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
