/*
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：
	插入一个字符
	删除一个字符
	替换一个字符

示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')


示例 2：

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1));//dp[i][j] word1的前i个字符转换成word2的前j个字符所用的最少操作数
        //base case 
        for(int i=1;i<=m;i++){
            dp[i][0] = i;// word2为空，word1删除所有字符才能与word2相等
        }
        for(int j=1;j<=n;j++){
            dp[0][j] = j; //word1为空，word1不断插入新字符与word2相等
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{ //删除 插入 替换
                    int tmp = min(dp[i-1][j-1]+1,dp[i][j-1]+1);
                    dp[i][j] = min(tmp,dp[i-1][j]+1);
                }
            }
        }

        
        return dp[m][n];
    }
};
