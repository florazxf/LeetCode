/*
找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
 

限制：

2 <= n <= 100000
*/

// 数组的范围在0~n-1 之间，因此可以遍历数组 将nums[i] 移到对应索引的地方，即第一次遇到数字x时，将其交换到索引x处；第二次有nums[x]==x 即重复 直接返回

class Solution {
    public int findRepeatNumber(int[] nums) {

        int i =0;
        while(i<nums.length){

            // 无需交换
            if(nums[i]==i){
                i++;
                continue;
            }

            // 当前值和 以当前值为索引的值 相等 说明重复
            if(nums[nums[i]]==nums[i]){
                return nums[i];
            }

            // 将当前值交换到索引位置
            int tmp = nums[i];
            nums[i] = nums[tmp];
            nums[tmp] = tmp;

        }
        return -1;
    }
}

// 自己想的先排序 再遍历
class Solution {
    public int findRepeatNumber(int[] nums) {

        Arrays.sort(nums);
        for (int i = 1; i < nums.length; i++) {
            if(nums[i]==nums[i-1]){
                return nums[i];
            }
        }
        return 0;
    }
}

// 题解 ： 用set 放已经遍历的数组
class Solution {
    public int findRepeatNumber(int[] nums) {

        Set<Integer> set = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            
            // 没有添加成功 说明已经存在
            if(!set.add(nums[i])){
                return nums[i];
            }
 
        }
        return 0;
    }
}
