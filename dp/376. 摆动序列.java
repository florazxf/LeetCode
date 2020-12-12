/*
如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。第一个差（如果存在的话）可能是正数或负数。少于两个元素的序列也是摆动序列。

例如， [1,7,4,9,2,5] 是一个摆动序列，因为差值 (6,-3,5,-7,3) 是正负交替出现的。相反, [1,4,7,2,5] 和 [1,7,4,5,5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。

给定一个整数序列，返回作为摆动序列的最长子序列的长度。 通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。

示例 1:

输入: [1,7,4,9,2,5]
输出: 6 
解释: 整个序列均为摆动序列。
示例 2:

输入: [1,17,5,10,13,15,10,5,16,8]
输出: 7
解释: 这个序列包含几个长度为 7 摆动序列，其中一个可为[1,17,10,13,10,16,8]。
示例 3:

输入: [1,2,3,4,5,6,7,8,9]
输出: 2
进阶:
你能否用 O(n) 时间复杂度完成此题?

*/

//方法一： On的动态规划
class Solution {
    public int wiggleMaxLength(int[] nums) {

        int n = nums.length;
        if(n<2){
            return n;
        }
        int[] up = new int[n];//以i结尾的最长上升序列的长度
        int[] down  = new int[n];//以i结尾的最长上升序列的长度
        up[0] =1 ;
        down[0] = 1;

        for (int i=1;i<n;i++) {

            if(nums[i-1]<nums[i]){
                up[i] = Math.max(up[i-1],down[i-1]+1);
                down[i] = down[i-1];
            }
            else if(nums[i-1]>nums[i]){
                up[i] = up[i-1];
                down[i] = Math.max(down[i-1],up[i-1]+1);
            }
            else{
                up[i] = up[i-1];
                down[i] = down[i-1];
            }

        }
        return Math.max(up[n - 1], down[n - 1]);
    }
}

//方法二：只与前一个状态有关，所以不需要要数组
class Solution {
    public int wiggleMaxLength(int[] nums) {

        int n = nums.length;
        if(n<2){
            return n;
        }

        int up = 1;
        int down = 1;
        

        for (int i=1;i<n;i++) {

            if(nums[i-1]<nums[i]){
                //up = Math.max(up,down+1);
                up = down+1;
            }
            else if(nums[i-1]>nums[i]){
                //down = Math.max(down,up+1);
                down = up+1;
            }
 

        }
        return Math.max(up, down);
    }
}
