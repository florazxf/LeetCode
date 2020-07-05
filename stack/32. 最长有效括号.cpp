/*
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"

*/

//栈：
/*
始终保持栈底元素为当前已经遍历过的元素中「最后一个没有被匹配的右括号的下标」
所以最开始栈底元素为-1，表示最长有效括号字符串是从0开始的。
后面如果有未匹配的)就把其下标入栈，这样最长有效括号字符串只能从下一个开始
*/

//看了题解后自己做的方法：
class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> index;
        int cnt = 0;
        int ans = 0;                                                                          
        index.push(-1);//表示最长子串从0开始
        for(int i=0;i<s.size();i++){
            //cout<<i;
            if(s[i]=='('){
                index.push(i);
            }
            else{
                if(index.top()!=-1&&s[index.top()]=='('){//匹配
                    index.pop();
                    cnt = i-index.top();
                    ans = max(cnt,ans);
                }
                else{//已经不匹配了，那把当前)入栈 做一个隔断 说明最长有效括号长度智能从i+1开始
                    index.pop();//栈顶元素出栈
                    index.push(i);
                }
 
            }
        }
        return ans;
    }
};


//题解的方法：
//还是比自己的思路更清晰，我自己的写的很冗余
/*
对于遇到的每个 ‘(’ ，我们将它的下标放入栈中
对于遇到的每个 ‘)' ，我们先弹出栈顶元素表示匹配了当前右括号：
如果栈为空，说明当前的右括号为没有被匹配的右括号，我们将其下标放入栈中来更新我们之前提到的「最后一个没有被匹配的右括号的下标」
如果栈不为空，当前右括号的下标减去栈顶元素即为「以该右括号为结尾的最长有效括号的长度」
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {//说明当前的右括号为没有被匹配的右括号，就将其入栈，作为隔断
                    stk.push(i); 
                } else {//匹配
                    maxans = max(maxans, i - stk.top());
                }
            }
        }
        return maxans;
    }
};
