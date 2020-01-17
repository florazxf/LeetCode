/*
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:

输入: [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

*/

//方法一：
/*
每次 sell 之后要等一天才能继续交易。只要把这个特点融入上一题的状态转移方程即可：

dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i])
解释：第 i 天选择 buy 的时候，要从 i-2 的状态转移，而不是 i-1 。

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0){
            return 0;
        }

        int dpi0=0;
        int dpi1=-prices[0];
        int dppre = 0;//代表dp[i-2][0]

        for(int i=0;i<n;i++){
            int temp = dpi0;
            dpi0 = max(dpi0,dpi1+prices[i]);
            dpi1 = max(dpi1,dppre-prices[i]); //dppre是第i-2天
            //dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
            //dp[i][1] = max(dp[i-1][1],dp[i-2][0]-prices[i]);
            dppre = temp;
        }
        return dpi0;
    }
};
