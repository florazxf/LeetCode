/**
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2


示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。

*/

//方法一：二分法
/**
x平方根的整数部分ans是满足k方小于等于x的最大k值，可以对k进行二分查找
*/
class Solution {
    public int mySqrt(int x) {

        int left = 0;
        int right = x;
        int ans=-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            
            if((long)mid*mid<=x){ //先把前一个mid转成long，然后再相乘 这样才不会溢出
                left = mid+1;
                ans = mid;
            }
            else {
                right=mid-1;
            }

        }
        return ans;

    }
}
