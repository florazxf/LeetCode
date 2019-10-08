/*
编写一个程序，找到两个单链表相交的起始节点。
*/

// 方法一
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *pa = headA;
        ListNode *pb = headB;
        if(pa==NULL or pb==NULL){return NULL;}
        
        //定义两个指针 走两轮
        //第一轮是为了抹除长度差 ：让两个到达末尾的结点指向另一个链表的头部 比如pa比pb少3个结点，那pa先到pa的尾部，则让他指向pb的头结点，当他在pb走三步后，原来的pb刚好走到尾部指向了pa的头结点，这样两个人和相交点的距离就一样长了
        //第二轮就一起走向相交点
        while(pa!=pb){
            if(pa==NULL){
                pa=headB; //pa走到了尾部就让他指向pb的头结点
            }
            else{
                pa = pa->next;
            }
            
            if(pb==NULL){
                pb=headA;//pb走到了尾部就让他指向pa的头结点
            }
            else{
                pb = pb->next;
            }
        }
    return pa;
    }
};

//方法二
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *pa = headA;
        ListNode *pb = headB;
        int ma=0;//a链表的长度
        int mb=0;//b链表的长度
        int len;
        if(pa==NULL or pb==NULL){return NULL;}
        
        //得到a链表的长度
        while(pa!=NULL){
            pa=pa->next;
            ma++;
        }
        //得到b链表的长度
        while(pb!=NULL){
            pb=pb->next;
            mb++;
        }
        pa = headA;
        pb = headB;
        // 谁长让谁先向后走几步
        if(ma>=mb){
            len = ma-mb;
            while(len!=0){
                pa = pa->next;
                len--;
                
            }
        }
        else{
            len = mb-ma;
            while(len!=0){
                pb=pb->next;
                len--;
            }
        }
        //同时向后走
        while(pa!=pb){
            pa = pa->next;
            pb = pb->next;
        }
        return pa;

    }
};
