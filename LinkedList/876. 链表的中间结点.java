/*给定一个带有头结点 head 的非空单链表，返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。
示例 1：

输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
示例 2：

输入：[1,2,3,4,5,6]
输出：此列表中的结点 4 (序列化形式：[4,5,6])
由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
    
    //设置快慢两个结点
        ListNode *fast = head;
        ListNode *low = head;
    //快结点每次走两步，慢结点每次走一步，当快结点为空或快结点的下一个结点为空时，low就是中间结点。
        while(fast!=NULL and fast->next!=NULL){
            fast = fast->next->next;
            low = low->next;
        }
        
        return low;
        
    }
};

//2.20 整理链表专题的时候用java做的
class Solution {
    public ListNode middleNode(ListNode head) {

        ListNode fast = head;
        ListNode low = head;
        while(fast!=null && fast.next!=null){
            fast = fast.next.next;
            low = low.next;
        }
        return low;
    }
}
