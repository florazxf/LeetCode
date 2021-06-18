/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
*/


// 和斐波那契数列是一样的
class Solution {
    public int numWays(int n) {

        int dp_0 = 1;
        int dp_1 = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = (dp_0 + dp_1) % 1000000007;
            dp_0  = dp_1;
            dp_1 = sum;
        }
        return dp_0;
    }
}
