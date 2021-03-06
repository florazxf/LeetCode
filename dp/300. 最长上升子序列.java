/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

*/
//方法一：动态规划
/*
时间复杂度O(n2)
1. 明确dp数组的含义：以i结尾的最长上升子子序列的长度 。
2. 得到状态转移方程： 假设dp[0...i-1]都已知，想办法求出dp[i]; 如果这一步求不出，则可能要返回第一步重新定义 dp数组的含义（可能要变成2维、3维）
3. 定义base case，初始化dp数组，如注意要全部初始化为1，因为子序列最少要包含自己
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);//dp[i] 以i结尾的最长上升子子序列的长度 
                           //dp数组应该全部初始化为1，因为子序列最少要包含自己
        int ans = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){ //找前面所有比自己小的，然后进行比较
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;

    }
};

//12/13 自己用java写的
class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int ret = 1;
        if(n==0){
            return 0;
        }
        int[] dp = new int[n]; //以i结尾的最长上升子序列的长度
        dp[0] = 1;
        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i] = Math.max(dp[i],dp[j]+1);
                }
            }
            ret = Math.max(ret,dp[i]);
        }
        return ret;

    }
}

//方法二：二分查找
