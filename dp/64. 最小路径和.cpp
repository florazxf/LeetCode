/*
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m==0){
            return 0;
        }
        int n = grid[0].size();
        int dp[m][n]={0};//当前的最小路径和
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(i==0&&j==0){
                    dp[0][0] = grid[0][0];
                    continue;
                }
                else if(i==0){  
                    dp[i][j] = dp[i][j-1]+grid[i][j];
                    continue;
                }
                else if(j==0){
                    dp[i][j] = dp[i-1][j]+grid[i][j];
                    continue;
                }
                dp[i][j] = min(dp[i][j-1],dp[i-1][j])+grid[i][j];
            }
        }

        
        return dp[m-1][n-1];
    }
};
