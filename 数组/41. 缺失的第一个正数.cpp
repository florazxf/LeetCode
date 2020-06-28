/*
给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。

示例 1:
输入: [1,2,0]
输出: 3

示例 2:
输入: [3,4,-1,1]
输出: 2

示例 3:
输入: [7,8,9,11,12]
输出: 1

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。
*/

//自己快快的就做出来了，嘻嘻
/*
交第一次的时候忘记去重，这是以后需要注意的点

但题目的要求是你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。
排序就已经不是O(n)了
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int target = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<1){
                continue;
            }
            
            if(nums[i]==target){
                //去重 如果下一个元素和当前元素相等则i++
                while(i+1<nums.size()&&nums[i]==nums[i+1]){ 
                    i++;
                }
                target++;//找到当前正整数就继续看下一个
            }
            else{
                return target;
            }
        }
        return target;
    }
};
