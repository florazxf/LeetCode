/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素


所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

说明:


	s 可能为空，且只包含从 a-z 的小写字母。
	p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。


示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。


示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。


示例 3:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。


示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。


示例 5:

输入:
s = "mississippi"
p = "mis*is*p*."
输出: false

*/

https://leetcode-cn.com/problems/regular-expression-matching/solution/dong-tai-gui-hua-zen-yao-cong-0kai-shi-si-kao-da-b/
class Solution {
public:
    bool isMatch(string s, string p) {
        s=" "+s;//防止该案例：""\n"c*"
        p=" "+p;
        int m=s.size(),n=p.size();
        bool dp[m+1][n+1];//表示s的前i个是否能否被p的前j个匹配
        memset(dp,false,(m+1)*(n+1));
        dp[0][0]=true;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='.'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    if(s[i-1]!=p[j-2] && p[j-2]!='.') //前一个字符匹配不上 s:pbb 和p:pbbc* c*看作没有，即匹配0次，直接去掉c
                        dp[i][j]=dp[i][j-2];
                    else{//*前面那个字符能匹配s[i]，或者*前面那个字符是万能的.
                        dp[i][j]=dp[i][j-1] || dp[i][j-2] || dp[i-1][j]; //满足任意以终都可以匹配上
                        /*
                        dp[i][j-1] 单个字符匹配的情况，去掉* qqb和qqb b*表示单个b
                        dp[i][j-2] 没有匹配 去掉多余的b* b*表示0个b
                        dp[i-1][j] 多个字符匹配的情况 看s里b多不多 b*表示多个b
                 
                        */

                    }
                }
            }
        }
        return dp[m][n];
    }
};
