/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

说明：

如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

*/
//方法一：自己的做法
//自底向上，不用进行边界优化

//第i行的最小路径和 = 第i+1的最小路径和 + 第i行路径值
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if(m==0){
            return 0;
        }

        vector<vector<int>> dp;
        dp.resize(m);
        int k = triangle[0].size();
        for(int i=0;i<m;i++){
            dp[i].resize(k);
            k++;
        }
        k=k-1;
        for(int j=k-1;j>=0;j--){
            dp[m-1][j] = triangle[m-1][j];//最后一行初始化
        }
        
        for(int i=m-2;i>=0;i--){ //从倒数第二行开始
            k--;
            for(int j=k-1;j>=0;j--){
                dp[i][j] = min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];//每一行等于下一行相邻最小的加上本身的值
            }
            
        }
        return dp[0][0];
    }
};

//方法二：对方法一的优化
//方法一的初始化复杂了，下面是题解，也是自底向上
        int rowSize = triangle.size();
        vector<vector<int>> dp(triangle);
                
        for(int i=rowSize-2;i>=0;i--) {        
            for(int j=0; j<triangle[i].size(); j++) {
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }


//方法三：空间压缩
//对上面方法的改进，其实用不到二维数组，用一维数组即可
//dp[i][j] = min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j]可以写成dp[j] = min(dp[j],dp[j+1])+triangle[i][j]
//因为右边的dp[j]就是下一行的值，但是注意j遍历要从左到右，不能再从右往左了
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if(m==0){
            return 0;
        }
        
        vector<int> dp(m+1,0); //dp的大小为三角的行数，初始化为0 也就是最后一行下一行的值为0
        
        for(int i=m-1;i>=0;i--){ 
            for(int j=0;j<triangle[i].size();j++){ //j不能倒着来，要正着
                dp[j] = min(dp[j],dp[j+1])+triangle[i][j];//每一行等于下一行相邻最小的加上本身的值
                                                          //dp暂存了下一行的值所以只需要一维即可
            }
            
        }

        return dp[0];
    }
};


