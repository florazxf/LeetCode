/*
给你一个整数数组 arr 和一个目标值 target ，请你返回一个整数 value ，使得将数组中所有大于 value 的值变成 value 后，数组的和最接近  target （最接近表示两者之差的绝对值最小）。

如果有多种使得和最接近 target 的方案，请你返回这些整数中的最小值。

请注意，答案不一定是 arr 中的数字。

 

示例 1：

输入：arr = [4,9,3], target = 10
输出：3
解释：当选择 value 为 3 时，数组会变成 [3, 3, 3]，和为 9 ，这是最接近 target 的方案。
示例 2：

输入：arr = [2,3,5], target = 10
输出：5
示例 3：

输入：arr = [60864,25176,27249,21296,20204], target = 56803
输出：11361

提示：

1 <= arr.length <= 10^4
1 <= arr[i], target <= 10^5
*/

//方法一：
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {

        //排序
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            double x = ((double)(target-sum))/(n-i);
            if(arr[i]>x){ //如果当前值比剩余的平均值大，则就超了(因为是递增排序)，应该返回剩余的平均值
                //四舍六入 
                if(x-int(x)>0.5){
                    return x+1;
                }else{
                    return x;
                }
            }
            sum+=arr[i];
        }
        return arr[n-1]; //刚好和target相等
    }
};
