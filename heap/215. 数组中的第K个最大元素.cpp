/*
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

*/
//方法一：堆
/*
这道题是找到第k个最大的元素， 维护动态数据的最大最小值 可以考虑堆
我们可以维护一个k大小的的小顶堆，堆顶就是第k个最大的数
*/

// 用自带的优先队列priority_queue

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;//最小堆
        for(auto& num:nums){
            if(pq.size()==k && pq.top()>=num)//num比堆顶元素小不可能是答案
                continue;
            if(pq.size()==k){
                pq.pop();//删除堆顶元素并自动整理
            }
            pq.push(num);//插入元素num并自动整理
        }
        return pq.top();//k大小的最小堆的堆顶即为所求
    }
};

//方法二：自己实现堆
