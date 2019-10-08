/*删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/

//方法一
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0);  //添加一个哑结点，这样就不用考虑删头结点的问题
        dummy->next = head;
        ListNode *p = dummy;
        if(p->next==NULL){return NULL;} //链表本身为空

        while(p!=NULL and p->next!=NULL){
            if(p->next->val==val){
                p->next = p->next->next;
            }
            else{    //当前p的下一个结点不要被删除时再后移
                p=p->next;
            }   
        }
        
        return dummy->next;
    }
};
// 方法二 递归

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head==NULL)
        {
            return head;
        }
        
        head->next = removeElements(head->next,val);
        if(head->val==val){
            return head->next;
        }
        else{
            return head;
        }
        
    }
};
