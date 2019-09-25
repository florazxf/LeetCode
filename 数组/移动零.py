class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """

        cnt = 0
        i = 0
        
            
        cnt0 = nums.count(0)
        while True:
            if nums[i] == 0:
                cnt = cnt + 1
                if i ==len(nums)-cnt: #此时0已经在最后或后面已经全是0
                    break
                for j in range(i, len(nums) - cnt):
                    nums[j] = nums[j + 1]
                nums[j+1] = 0
            else:
                i = i+1
            if cnt==cnt0:
                break
