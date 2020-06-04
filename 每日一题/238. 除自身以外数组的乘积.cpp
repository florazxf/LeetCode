/*
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

 

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
 

提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。

说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
*/

//方法一

//乘积 = 当前数左边的乘积 * 当前数右边的乘积

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n);

        int k=1;
        
        //该数左边的乘积
        for(int i=0;i<n;i++){
            ans[i] = k;
            k = k*nums[i];// 第i个数左边的乘积
        }
        //每个数左边的乘积已经放在ans里
        //然后乘右边的乘积
        k=1;
        for(int i=n-1;i>=0;i--){
            
            ans[i] = ans[i]*k;// 该数左边的乘积乘上右边的乘积
            k = k*nums[i]; //该数右边的乘积
        }
        return ans;

    }
};
