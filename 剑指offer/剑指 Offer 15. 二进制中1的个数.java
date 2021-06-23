/*
请实现一个函数，输入一个整数（以二进制串形式），输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。

示例 1：
输入：00000000000000000000000000001011
输出：3
解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。

示例 2：
输入：00000000000000000000000010000000
输出：1
解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。

示例 3：
输入：11111111111111111111111111111101
输出：31
解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。
 
提示：
输入必须是长度为 32 的 二进制串 。
*/
  // 题解：因为题目说明了二进制位为32位，所以可以直接遍历0到31位，然后用n与2的i次方进行与运算
      public int hammingWeight(int n) {
        int ans=0;
        for (int i = 0; i < 32; i++) {

            if((n & (1<<i))!=0){
                ans++;
            }
        }
        return ans;
    }
    
    // 题解：位运算优化
    // n&(n-1) 的运算结果就是把n的最低位的1变成0后的结果，我们可以不断的进行这个与操作，直到n变成0 也就得到了1的个数
    public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int ans=0;
        while(n!=0){
            n = n&(n-1);
            ans++;
        }
        return ans;
    }
}


    // 自己写的感觉很蠢
    public int hammingWeight(int n) {
        String s = Integer.toBinaryString(n);
        int ans=0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(c=='1'){
                ans++;
            }
        }
        return ans;
    }
