/*
  两个数组的交集 II
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
说明：

输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
我们可以不考虑输出结果的顺序。
进阶:

如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小很多，哪种方法更优？
如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？

*/

//10个月以前用python做的
class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        n1 = len(nums1)
        n2 = len(nums2)
        nums3=list()
        if n2-n1 > 0:
            for num in nums1:
                if num in nums2:
                    nums3.append(num)
                    nums2.remove(num)
        else:
            for num in nums2:
                if num in nums1:
                    nums3.append(num)
                    nums1.remove(num)
        return nums3
      
//7.13号刷每日一题的时候自己用c++做的方法
/*
1. 先给两个数组排序
2. 分别给nums1和nums2一个指针，比较值的大小，值小的指针右移
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int l1 = 0,l2=0;
        while(l1<nums1.size()&&l2<nums2.size()){
            if(nums1[l1]==nums2[l2]){
                ans.push_back(nums1[l1]);
                l1++;
                l2++;
            }
            else if(nums1[l1]<nums2[l2]){
                l1++;
            }
            else{
                l2++;
            }
        }
        return ans;

    }
};
