/*
给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
*/


//12.13 每日一题

//第一遍用的hashmap  不应该 用hashmap而应该用set
class Solution {
    public boolean containsDuplicate(int[] nums) {
        
        Map<Integer,Integer> map  = new HashMap<Integer,Integer>(); 
        for(int i=0;i<nums.length;i++){

            if(!map.isEmpty() && map.containsKey(nums[i])){
                return true;
            }

            map.put(nums[i],1);
        }
        return false;

    }
}

//应该用hashset  set.add() 添加一个元素时 如果包含这个元素就返回true
class Solution {
    public boolean containsDuplicate(int[] nums) {
        
        Set<Integer> set = new HashSet<>();
        for(Integer num:nums){
            if(!set.add(num)){ //set.add() 如果没有包含这个元素返回true
                return true;
            }
        }
        return false;
    }
}


//一年前用python写的
class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        n = len(nums)
        m = len(set(nums))
        if n == m:
            return False
        else:
            return True

        
       
