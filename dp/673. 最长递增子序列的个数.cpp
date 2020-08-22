/*

给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
示例 2:

输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。
*/

/*
相比于300那道题，还要有一个cnt数组，以i结尾的递增子序列的个数
比较dp[j]+1 比dp[i]大的时候证明可以接上，所以cnt[i] = cnt[j]
dp[j]+1==dp[i] 说明前面已经有最长序列了，cnt[i]+=cnt[i]
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1); //长度至少为自己 dp[i]以i结尾的递增子序列的长度
        vector<int>cnt(n,1); //cnt[i] 以i结尾的递增子序列的个数
        int max_dp = 1;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if((dp[j]+1)>dp[i]){ //比当前长 当前的cnt[i]的序列数为之前cnt[j]的

                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    }
                    else if((dp[j]+1)==dp[i]){ //和之前相等，证明有同样长度的 所以累加
                        cnt[i]+=cnt[j];
                    }
                   
                }
            }
            max_dp = max(max_dp,dp[i]);

        }
        for(int i=0;i<n;i++){
            if(dp[i]==max_dp){
                ans+=cnt[i];
            }
        }
        return ans;
       
    }
};
