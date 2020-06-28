/*
难度中等350给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。

示例: 

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。


进阶:

如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

*/

//方法一：暴力法 自己做出来的方法
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int ans=INT_MAX;
        for(int l = 0;l<nums.size();l++){
            int sum=0;
            for(int r = l;r<nums.size();r++){
                sum+=nums[r];
                if(sum>=s){
                    ans = (r-l+1)<ans?r-l+1:ans;
                    break;
                }
            }
        }

        return ans==INT_MAX?0:ans;

    }
};

//方法二：双指针
/*
做完暴力法，自己就在想还能用什么方法，就再草稿纸上画出来双指针这种方法，但是还是思路不够清楚，没有那么清晰的想出来：

当sum>=s时 left右移，直到sum<s了，right右移
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int ans=INT_MAX;
        int left=0;
        int right =0;
        int sum=0;
        while(right<nums.size()){
            sum+=nums[right];
            while(sum>=s){//sum>=s 则left右移
                sum = sum-nums[left];
                ans = (right-left+1)<ans?(right-left+1):ans;//找到以right为右边界的满足条件的最小长度
                left++;
            }
            //sum<s right右移
            right++;
        }

        return ans==INT_MAX?0:ans;

    }
};

//方法三：二分法
