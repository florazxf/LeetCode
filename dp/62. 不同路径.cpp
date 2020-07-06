/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？


说明：m 和 n 的值均不超过 100。

示例 1:

输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右
示例 2:

输入: m = 7, n = 3
输出: 28

*/

//方法一：
class Solution {
public:
    int uniquePaths(int m, int n) {

        if(m==0){
            return 0;
        }
        int dp[m][n]={0};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(i==0&&j==0){
                    dp[i][j] = 1;
                    continue;
                }
                else if(i==0){
                    dp[i][j] = dp[i][j-1];
                    continue;
                }
                else if(j==0){
                    dp[i][j] = dp[i-1][j];
                    continue;
                }
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        
        return dp[m-1][n-1];
    }
};

//方法二：
//对方法一的优化
//对每一行来说，就是上一行的值和这一行他左边的值， 所以只用一维数组就够了
class Solution {
public:
    int uniquePaths(int m, int n) {

        if(m==0){
            return 0;
        }
        int dp[n]={0};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(j==0){
                    dp[j] = 1;
                    continue;
                }
                //dp[i][j] = dp[i-1][j]+dp[i][j-1];
                dp[j] = dp[j-1]+dp[j]; //该位置左边的值和上面的值
            }
        }
        
        return dp[n-1];
    }
};


//刷每日一题做的方法
class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m,vector<int>(n,1)); //dp[i][j]到达ij的可能的路径

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){  
                dp[i][j]  = dp[i-1][j]+dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
        
    }
};

//唉 还是没有优化
class Solution {
public:
    int uniquePaths(int m, int n) {

        //vector<vector<int>> dp(m,vector<int>(n,1)); //dp[i][j]到达ij的可能的路径
        vector<int> dp(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){  
                dp[j]  = dp[j-1]+dp[j];
            }
        }

        return dp[n-1];
        
    }
};
