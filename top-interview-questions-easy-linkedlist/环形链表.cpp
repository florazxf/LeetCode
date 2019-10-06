/*
给定一个链表，判断链表中是否有环。
*/

//方法一：哈希表
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //建一个哈希set
        set<ListNode*> nodeseen;
        while(head!=NULL){
            if(nodeseen.count(head)){  //当前访问的结点在hash表中存在
                return true;
            }
            else{
                nodeseen.insert(head); //将当前结点存储在hash表中
            }
            head = head->next;
        }
        
        return false;
        
    }
};

//方法二：创建快慢两个指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //创建快慢两个指针
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast!=NULL and fast->next!=NULL){ //要注意访问后两个结点的时候要判断fast的next是否为空
            //快指针每次走两步，慢指针每次走一步
            slow = slow->next;
            fast = fast->next->next;
            while(slow==fast){   //如果慢指针追上了快指针证明有环
                return true;
            }
            
        }
        return false;
    }
};
