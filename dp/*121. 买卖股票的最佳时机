/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

*/

//方法一： 套框架
//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len==0){
            return 0;
        }
        int dp[len][2];
        for(int i=0;i<len;i++){
            if(i-1==-1){
                dp[i][0]=0;
                dp[i][1]=-prices[i];
                continue;
            }

            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1],-prices[i]);

        }
        return dp[len-1][0];
        
    }
};

//方法二：
//从方法一其实可以看出来只有两个状态，dp[i][0]和dp[i][1]，因此无需开辟二维数组

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if(len==0){
            return 0;
        }
        int dp_i_0 = 0;
        int dp_i_1 = -prices[0];
        for(int i=1;i<len;i++){

            dp_i_0 = max(dp_i_0,dp_i_1+prices[i]);
            dp_i_1 = max(dp_i_1,-prices[i]);

        }
        return dp_i_0;
        
    }
};
