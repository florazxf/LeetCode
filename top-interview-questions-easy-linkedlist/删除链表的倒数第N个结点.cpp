/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
*/

//方法一
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m=0; //链表的长度
        ListNode* p = head;
        ListNode* dummy = (struct ListNode*)malloc(sizeof(ListNode)); 
        dummy->next = head;//设置一个哑结点
        //得到链表的长度m
        for(;p;p=p->next){
            m = m+1;
        }

        p = dummy;
        //找到要删除结点的位置
        for (int i=0;i<m-n;i++){
            p = p->next;
        }
        //删除结点
        p->next = p->next->next;
        return dummy->next;   
    }
};

// 方法二：用双指针实现一次遍历
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m=0; //链表的长度
        ListNode* first = (struct ListNode*)malloc(sizeof(ListNode));
        ListNode* second = (struct ListNode*)malloc(sizeof(ListNode));
        ListNode* dummy = (struct ListNode*)malloc(sizeof(ListNode)); //设置一个哑结点

        dummy->next = head;
        first = dummy; //first->next = head; 不能写成这样
        second = dummy; //second->next = head; 不能写成这样
        
        // 先让first走n+1步
        while(n>=0){
            first = first->next;
            n = n-1;
        }
        //找到要删除节点的前一个节点
        while(first!=nullptr){
            first = first->next;
            second = second->next;
        }
        
        second->next = second->next->next;//删除当前结点
        
        return dummy->next;
        
    }
};
