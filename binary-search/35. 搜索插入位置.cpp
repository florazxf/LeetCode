/*

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right  = nums.size()-1 ;
        int mid;

        while(left<=right){
            mid = (left+right)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                left = mid+1;
            }
            else if(nums[mid]>target){
                right = mid-1;
            }
        }
        return left;//被顺序插入的位置
    }
};

//7.17每日一题遇到后自己做的结果
/*
问题在于： 求mid时候忘了mid = left+(right-left)/2; 这样可以防止溢出
还有就是当target大于nums[mid]的时候mid=left+1 而不是mid = left 因为mid已经不是target了，正是因为这样 才有了边界情况 我还单独处理了一下！！ 下次一定要记住二分法的基本套路
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        if(target>nums[right]){
            return right+1;
        }
        else if(target<nums[left]){
            return left;
        }
        while(left<=right){
            int mid = left+(right-left)/2;
            //cout<<mid<<' ';
            if(nums[mid]<target){
                if(left==mid){
                    return right;
                }
                left = mid;

            }
            else if(nums[mid]>target){
                right = mid;
            }
            else{
                return mid;
            }
        }
        return left;
    }
};
