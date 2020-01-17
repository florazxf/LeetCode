/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [2,4,1], k = 2
输出: 2
解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2:

输入: [3,2,6,5,0,3], k = 2
输出: 7
解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。

*/

//方法一：
//k=any integer
//k等于任意整数，可以分成两部分 k<=n/2 和k>n/2
//k<=n/2:k是有效交易，因为一次交易由买入和卖出构成，至少需要两天。
//k>n/2： k=+infinity

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        int n=prices.size();
        if(n<=1){
            return 0;
        }
        //一次交易由买入和卖出构成，至少需要2天。所以有效的k一定不超过n/2，如果超过就是k=+infinity
        if(k>n/2){//k=+infinity的情况
            int dpi0 = 0;
            int dpi1 = -prices[0];
            for(int i=0;i<n;i++){
                dpi0 = max(dpi0,dpi1+prices[i]);
                dpi1 = max(dpi1,dpi0-prices[i]);
            }
            return dpi0;
        }
        int dp[n][k+1][2]={0};
        for(int i=0;i<n;i++){ //有效的k次交易
            for(int j=k;j>=1;j--){
                if(i==0){
                    dp[i][j][0]=0;
                    dp[i][j][1]=-prices[0];
                    continue;
                }
                dp[i][j][0] = max(dp[i-1][j][0],dp[i-1][j][1]+prices[i]);//第i天不持有股票：取无操作和卖的最大值
                dp[i][j][1] = max(dp[i-1][j][1],dp[i-1][j-1][0]-prices[i]);//第i天持有股票：取无操作和买的最大值
            }
        }
        return dp[n-1][k][0]; 
        
    }
};
