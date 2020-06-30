/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

示例 1：
输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]

示例 2：
输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
*/

//方法一：自己的方法
/*
自己看到这个题的时候无从下手，还是王欢提示我先在最上面定义两个stack
然后自己就做出来了，但是时间好长啊
*/

class CQueue {
public:
    stack<int> s1;
    stack<int> s2;
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s1.empty()){
            return -1;
        }
        else{
            //先把s1的都移到s2
            while(!s1.empty()){
                int tmp = s1.top();
                s2.push(tmp);
                s1.pop();
            }
            int ans = s2.top();//得到栈顶元素
            s2.pop();//栈顶元素出栈
            //再把s2所有元素移到s1
            while(!s2.empty()){
                int tmp = s2.top();
                s1.push(tmp);
                s2.pop();
            }          
            return ans;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
 
 //方法二： 自己在方法一的基础上改的
 
 /*
 不用每次删元素的时候都把s1的移到s2的，等s2的删空了再移
 这个和题解一样爱！！开心
 */
 class CQueue {
public:
    stack<int> s1;
    stack<int> s2;
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s1.empty() && s2.empty()){
            return -1;
        }
        else{

            if(s2.empty()){//s2为空s1不为空，就把s1的都转到s2
                while(!s1.empty()){
                    int tmp = s1.top();
                    s2.push(tmp);
                    s1.pop();
                }
            }

            int ans = s2.top();
            s2.pop();
            return ans;

        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
