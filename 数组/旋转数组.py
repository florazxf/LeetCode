'''
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的 原地 算法。
'''
class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        if k>len(nums):
            k = k%len(nums)
        n = len(nums)-1
        n1 = len(nums)-k-1

        for i in range(int(n1/2)+1): #对数组的前半部分进行翻转
                t = nums[i]
                nums[i]=nums[n1-i]
                nums[n1-i]=t
        j = 0
        for i in range(len(nums)-k,len(nums)-k+int(k/2)): # 对数组的后半部分进行翻转
            t = nums[i]
            nums[i] = nums[n-j]
            nums[n-j]=t
            j = j + 1
        
        nums.reverse() # 对整个数组进行翻转


        
       
