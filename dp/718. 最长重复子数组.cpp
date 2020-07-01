/*
难度中等229给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

示例 1:

输入:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出: 3
解释: 
长度最长的公共子数组是 [3, 2, 1]。

*/

//方法一：自己做出来的
/*
刚开始自己想的时候想的是一维的，然后看了提示说dp[i][j]就是答案，这才有了思路
*/

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        int ans=0;
        vector<vector<int>>dp(m,vector<int>(n,0));//当前的公共子序列的长度
        //初始化第一行
        for(int j=0;j<n;j++){
            if(A[0]==B[j]){
                dp[0][j]=1;
            }
        }
        //初始化第一列
        for(int i=0;i<m;i++){
            if(A[i]==B[0]){
                dp[i][0]=1;
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(A[i]==B[j]){//当前值相等 那就在前一个基础上加1
                    dp[i][j] = dp[i-1][j-1]+1;
                    if(dp[i][j]>ans){
                        ans = dp[i][j];
                    }
                }

            }
        }
        return ans;

    }
};

//官方
/*
自己的方法是从0开始的，这样就要先初始化第一行和第一列
官方是从后往前的，这样就不用初始化了只用再补一行0和再补一列0
*/

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        int ans=0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));//当前的公共子序列的长度

        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(A[i]==B[j]){//当前值相等 那就在前一个基础上加1
                    dp[i][j] = dp[i+1][j+1]+1;
                    ans = max(dp[i][j],ans);
                }

            }
        }
        return ans;

    }
};
