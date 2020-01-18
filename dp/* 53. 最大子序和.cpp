/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

*/

//方法一：动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int dp[n]={0};
        dp[0] = nums[0];
        int result=dp[0];
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1]+nums[i],nums[i]);//dp[i]表示以i结尾的最大子序列和
            result = max(result,dp[i]);//然后在所有的dp[i]中找最大的
        }
        return result;
    }
};
