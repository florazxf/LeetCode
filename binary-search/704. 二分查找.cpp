/*

给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
 

提示：

你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。
*/


/*
https://leetcode-cn.com/problems/binary-search/solution/er-fen-cha-zhao-xiang-jie-by-labuladong/
终止条件：while(left<=right) 因为我们搜索的区间是[left,right]，当搜索区间为空的时候停止搜索，当while(left<=right)的终止条件是left=right+1，
那么搜索空间即为[right+1,right]，显然搜索空间为空
while(left<right)的终止条件是left==right，那么搜索空间为[left,right]，这时搜索空间不为空，还有一个数，如果这时候停止搜索那么这个数就被漏掉了

*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        
        int mid;
        while(left<=right){//直到数组为空
            mid = left + (right - left) / 2;//mid = (left+right)/2;防止溢出
            if(target==nums[mid]){ //找到直接返回结果
                return mid;
            }
            else if(target<nums[mid]){ //目标在左边
                right=mid-1; //target在左边不包含当前mid的值
            }
            else if(target>nums[mid]){
                left = mid+1;
            }

            
        }

        return -1;
    }
};
