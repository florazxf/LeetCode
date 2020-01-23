/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 1 和 0 来表示。

说明：m 和 n 的值均不超过 100。

示例 1:

输入:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
输出: 2
解释:
3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右

*/

//方法一：
//加个判断如果是1则这条路不通
//这个题主要的坑是不能用int，要用long不然会出现runtime 
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        if(m==0){
            return 0;
        }
        int n = obstacleGrid[0].size(); 


        long dp[m][n] = {0};
        if(obstacleGrid[m-1][n-1]==1||obstacleGrid[0][0]==1){
            return 0;
        }
        dp[0][0] = 1;


        for(int j=1;j<n;j++){//对第一行初始化 i=0
            if(obstacleGrid[0][j-1]==1){
                dp[0][j]=0;
                continue;
            }
            dp[0][j] = dp[0][j-1];
        }

        for(int i=1;i<m;i++){ //对第一竖初始化 j=0
            if(obstacleGrid[i-1][0]==1){
                dp[i][0]=0;
                continue;
            }
            dp[i][0] = dp[i-1][0];
        }

        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){

                if(obstacleGrid[i-1][j]==1&&obstacleGrid[i][j-1]==1){ //上面和左边都有障碍物则此路不通
                    dp[i][j] = 0;
                    continue;
                }
                else if(obstacleGrid[i-1][j]==1){ //左边有障碍物则值为上面的值
                    dp[i][j] = dp[i][j-1];
                    continue;
                }
                else if(obstacleGrid[i][j-1]==1){//上边有障碍物则值为左边的值
                    dp[i][j] = dp[i-1][j];
                    continue;
                }
                dp[i][j] = dp[i-1][j]+dp[i][j-1]; //正常情况值为上面加左边的路径和
            }
        }

        return dp[m-1][n-1];
    }
};

//方法二：官方
//不用像方法一那么复杂，如果当前obstacleGird是1则dp是0，当前结点对后面的路径不产生贡献
//对第一行和第一列来说，因为只有一条路，所以要保证当前和前面一格都能走通才是1
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        if(m==0){
            return 0;
        }
        int n = obstacleGrid[0].size(); 


        long dp[m][n] = {0};
        if(obstacleGrid[m-1][n-1]==1||obstacleGrid[0][0]==1){
            return 0;
        }
        dp[0][0] = 1;


        for(int j=1;j<n;j++){//对第一行初始化 i=0
            dp[0][j] = (obstacleGrid[0][j]==0&&dp[0][j-1]==1)?1:0; //当前和前一格都能走通才是1
        }

        for(int i=1;i<m;i++){ //对第一竖初始化 j=0
            dp[i][0] = (obstacleGrid[i][0]==0&&dp[i-1][0]==1)?1:0;//当前和前一格都能走通才是1

        }

        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }

                dp[i][j] = dp[i-1][j]+dp[i][j-1]; //正常情况值为上面加左边的路径和
            }
        }

        return dp[m-1][n-1];
    }
};
