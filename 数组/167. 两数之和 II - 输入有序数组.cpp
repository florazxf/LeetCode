/*
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:

返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
示例:

输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
*/

//方法一：自己做的 双指针 用时7分钟
/*
可以改进的地方：
题目要返回的是数组 自己就创建了个ans 用来放结果
其实直接return (left+1,right+1) 即可

双指针法的时间复杂度是O(n) 两个指针移动的总次数最多为 n 次。

*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int left =0;
        int right = numbers.size()-1;
        //vector<int> ans;
        while(left<right){
            int sum = numbers[left]+numbers[right];
            if(sum<target){
                left++;
            }
            else if(sum>target){
                right--;
            }
            else{
                //ans.push_back(left+1);
                //ans.push_back(right+1);
                //return ans;
                return (left+1,right+1);
            }
        }
        //return ans;
        return {-1,-1};

    }
};

//方法二：二分法 时间复杂度O(nlogn)
/*
在数组中找到两个数，使得它们的和等于目标值，可以首先固定第一个数，然后寻找第二个数，第二个数等于目标值减去第一个数的差。利用数组的有序性质，可以通过二分查找的方法寻找第二个数。为了避免重复寻找，在寻找第二个数时，只在第一个数的右侧寻找。
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int low = i + 1, high = numbers.size() - 1;
            while (low <= high) {
                int mid = (high - low) / 2 + low;
                if (numbers[mid] == target - numbers[i]) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] > target - numbers[i]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return {-1, -1};
    }
};
