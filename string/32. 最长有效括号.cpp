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

//这道题自己看到第一反应是用栈但是 解决不了中间有不匹配的问题 看了题解以后把下面的方法都做了一遍
//方法一：正向逆向相结合遍历
/*
1. 正向遍历一遍：
记下左括号和右括号的数量， 如果数量相等证明匹配了，那就记下长度； 如果右括号的数量比左括号多了，说明不匹配，要重新开始
正向遍历一遍后，我们会漏掉一种情况：就是遍历的时候左括号的数量始终大于右括号的数量，即 (() ，这种时候最长有效括号是求不出来的。 因此再逆向遍历一遍

2. 逆向遍历一遍
左括号数量比右括号多的时候，说明不匹配，又重新开始
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int leftcnt = 0; //左括号数量 
        int rightcnt = 0; //右括号数量
        int length = 0;
        for(int i=0;i<n;i++){ //从左到右遍历
            if(s[i]=='('){
                leftcnt++;
            }
            else{
                rightcnt++;
            }
            if(leftcnt==rightcnt){//匹配
                length = max(length,leftcnt*2);
            }
            else if(rightcnt>leftcnt){//右括号数量比左括号数量多 不匹配 就要重新开始
                leftcnt = 0;
                rightcnt=0;
            }
        }
        leftcnt = 0;
        rightcnt = 0;
        for(int i =n-1;i>=0;i--){//从右往左遍历
            if(s[i]=='('){
                leftcnt++;
            }
            else{
                rightcnt++;
            }  
            if(leftcnt==rightcnt){//匹配
                length = max(length,leftcnt*2);
            } 
            else if(leftcnt>rightcnt){ //左括号数量比右括号数量多 证明不匹配 就要重新开始
                leftcnt=0;
                rightcnt=0;
            }

        }
        return length;
        
    }
};

//方法二：栈

//方法三：动态规划

/*
dp[i]为以i结尾的最长有效括号的长度
有效的子串一定以)结尾，因此我们可以知道以(结尾的子串对应的dp必定为0 ，我们只需要求解)在dp 数组中对应位置的值。
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        vector<int>dp(n,0);//dp[i]为以i结尾的最长有效括号的长度
        int maxans = 0;
        for(int i=1;i<n;i++){
            if(s[i]==')'){
                if(s[i-1]=='('){//()
                    dp[i] = 2+(i>=2?dp[i-2]:0);
                }
                else if((i-dp[i-1])>0 && s[i-dp[i-1]-1]=='('){//....)) 且s[i-dp[i-1]-1]=='('
                    dp[i]=2+dp[i-1]+(i-dp[i-1]>=2?dp[i-dp[i-1]-2]:0);
                    
                }
            }
            maxans = max(maxans, dp[i]);
        }
        return maxans;
    }
};
