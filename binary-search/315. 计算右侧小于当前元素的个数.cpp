/*
给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

示例:

输入: [5,2,6,1]
输出: [2,1,1,0] 
解释:
5 的右侧有 2 个更小的元素 (2 和 1).
2 的右侧仅有 1 个更小的元素 (1).
6 的右侧有 1 个更小的元素 (1).
1 的右侧有 0 个更小的元素.

*/

//看了题解都写不出来
//方法一：归并排序+索引数组

class Solution {
public:
    vector<int> res;

    vector<int> countSmaller(vector<int>& vec) {

        if (vec.empty()){
            return {};
        }

        vector<pair<int, int>> nums;
        for (int i = 0; i < vec.size(); i++){
            nums.emplace_back(vec[i], i);
        }

        res = vector<int>(vec.size(), 0);
        merge_sort(nums, 0, (int)nums.size() - 1);

        return res;
    }

    void merge_sort(vector<pair<int, int>>& nums, int left, int right){
        if (left < right){
            int mid = left + (right - left) / 2;

            merge_sort(nums, left, mid);
            merge_sort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }

    void merge(vector<pair<int, int>>& nums, int left, int mid, int right){
        int i = left, j = mid + 1;
        int k = left;

        vector<pair<int, int>> sort_nums;

        while (i <= mid && j <= right){
            if (nums[i].first <= nums[j].first){
                res[nums[i].second] += j - mid - 1;
                sort_nums.push_back(nums[i++]);
            }else if (nums[i].first > nums[j].first){
                sort_nums.push_back(nums[j++]);
            }
        }

        while (i <= mid){
            res[nums[i].second] += j - mid - 1;
            sort_nums.push_back(nums[i++]);
        }

        while (j <= right){
            sort_nums.push_back(nums[j++]);
        }

        for (int m = 0, n = left; m < sort_nums.size(); m++, n++){
            nums[n] = sort_nums[m];
        }
    }
};
