/*
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
进阶：

一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？
*/

/*
用三个指针：
cur：当前指针，p0:0和1的分界线   p1：1和2的分界线
如果nums[cur]==0,就交换nums[cur]和nums[p0],交换完cur和p0都++
如果nums[cur]==2,就交换nums[cur]和nums[p1],交换完p1是--，右边换回来的数还没有做过比较所以cur不能++
如果nums[cur]==1，直接比较下一个cur++
*/
class Solution {

    public void sortColors(int[] nums) {
        int cur=0,p0=0;
        int p1 = nums.length-1;
        while(cur<=p1){
            if(nums[cur]==0){ //和01分界线互换
                swap(nums,cur,p0);
                p0++;
                cur++;
            }
            else if(nums[cur]==2){//和12分界线互换
                swap(nums,cur,p1);
                p1--;
                //右边换回来的数还没有做过比较所以cur不能++
            }
            else{
                cur++;
            }
            
        }

    }
    public void swap(int[] nums,int cur,int p){
        int tmp = nums[cur];
        nums[cur] = nums[p];
        nums[p] = tmp;
    }
}
