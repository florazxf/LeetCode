/*

给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
两个字符串完全匹配才算匹配成功。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "*"
输出: true
解释: '*' 可以匹配任意字符串。
示例 3:

输入:
s = "cb"
p = "?a"
输出: false
解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
示例 4:

输入:
s = "adceb"
p = "*a*b"
输出: true
解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
示例 5:

输入:
s = "acdcb"
p = "a*c?b"
输出: false
*/

//方法一：自己做的
/*
就是状态转移方程把*的几种情况想清楚就很容易写： ①不使用* 则dp[i][j] = dp[i][j-1] ② 使用* dp[i][j] = dp[i-1][j]
自己写的时候还多写了个dp[i-1][j-1]也就是*是匹配一个字符，其实这种就包含在②里了

自己写的时候一个很大的问题就是边界处理 看了题解 学习了一下
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        s = " "+s;
        p = " "+p;
        
        int m = s.size();
        int n = p.size();
        //dp[i][j]表示s的前i个字符能否被p的前j个字符匹配
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        dp[0][0] = true;
        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                //cout<<i;
                
                if(i==0 || j==0){
                    if(i==0&&j==0)
                        continue;
                    else if(i==0 && p[j]=='*'){
                        if(j==1){
                            dp[i][j] = true;
                        }
                        else{
                            dp[i][j]=dp[i][j-1];
                        }
                        continue;
                    }
                    continue;
                }

                if(s[i]==p[j]||p[j]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j]=='*'){
                    dp[i][j] = dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j];
                    /*
                    dp[i-1][j-1] *匹配单个字符
                    dp[i][j-1] *是空
                    dp[i-1][j] *匹配多个字符
                    */
                }

            }
        }

        return dp[m][n];
        
    }
};

// 方法二：题解
/*
https://leetcode-cn.com/problems/wildcard-matching/solution/tong-pei-fu-pi-pei-by-leetcode-solution/
主要就是边界处理 ，最开始的初始化

还有就是注意题解写的si和pj 对应的是s[i-1]和p[j-1] 因为大部分语言的字符串下标从0开始

*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = true;
            }
            else {
                break;
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

