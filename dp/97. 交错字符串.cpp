/*
给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

示例 1:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出: true
示例 2:

输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出: false

*/
 
//字符串匹配这类题目的 定义都是前多少个字符能否被匹配
/*
然后我们就看这道题目是s3是去匹配s1和s2的字符，那s3的前i+j个字符就是由s1的前i个字符和s2的前j个字符组合而成的 。
所以我们就可以定义：f[i][j]表示s1的前i个字符和s2的前j个字符能否交错成s3的前i+j个字符。
状态转移方程：
那f[i][j]为true也就是能否交错成可以有两种情况：
① s1[i-1]==s3[i+j-1] 
   s3的前一个字符是和s1的前一个字符匹配的，那f[i][j] = f[i-1][j]
② s2[j-1] == s3[i+j-1]
   s3的前一个字符是和s2的前一个字符匹配的，那f[i][j] = f[i][j-1]
*/
//方法一：二维数组
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        //f[i][j]表示s3的前i+j个字符可以被s2的前i个字符和s3的前j个字符表示
        auto f = vector<vector<int>>(s1.size()+1,vector<int>(s2.size()+1,false));

        int m = s1.size();
        int n = s2.size();
        int t = s3.size();
        if(m+n!=t){//连长度都不相等，肯定不能
            return false;
        }
        f[0][0] = true;
        for(int i=0;i<=m;++i){
            for(int j=0;j<=n;++j){
                int p = i+j-1;
                if(i>0){ 
                    f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);//当s3的第i+j-1个字符和s1的第i-1个字符相等
                }
                if(j>0){
                    f[i][j] |= (f[i][j-1]&&s2[j-1]==s3[p]);//当s3的第i+j-1个字符和s2的第j-1个字符相等
                }
            }
        }
        return f[m][n];
    }
};
//方法二：一维数组 用滚动数组优化空间复杂度
/*
就这种二维的动态规划的题每次做完就可以看一下，是不是这一行只和前一行有关 那就只需要定义一维数组了
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto f = vector <int> (s2.size() + 1, false);

        int n = s1.size(), m = s2.size(), t = s3.size();

        if (n + m != t) {
            return false;
        }

        f[0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0) {
                    f[j] &= (s1[i - 1] == s3[p]);
                }
                if (j > 0) {
                    f[j] |= (f[j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }

        return f[m];
    }
};
