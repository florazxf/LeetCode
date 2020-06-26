/*
编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

 示例1:

 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]


 示例2:

 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]


提示：


链表长度在[0, 20000]范围内。
链表元素在[0, 20000]范围内。

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 //方法一：自己做出来的方法
 /*
 用set存储链表上的值来去重
 */
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        unordered_set<int> ans;
        ListNode* p = new ListNode(0);
        ListNode* headp = p;
        while(head!=NULL){

            if(ans.empty() ||!ans.count(head->val)){//set是空的，或者当前值不存在在set中
                ans.insert(head->val);
                p->next = new ListNode(head->val);
                p= p->next;
            }

           
           head = head->next;
        }
        

        return headp->next;
    }
};

//方法二
/*
题解的方法，也是用set 就是写的比我写的更顺手
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(head==NULL){return head;}
        unordered_set<int> ans = {head->val};
        ListNode* p=head;
        while(p->next!=NULL){

            if(ans.count(p->next->val)){//下一个节点值存在在set中
                p->next = p->next->next;
            }
            else{
                ans.insert(p->next->val);
                p = p->next;
            }
        }
        

        return head;
    }
};
