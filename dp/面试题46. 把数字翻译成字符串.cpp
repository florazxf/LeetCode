/*

给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

 

示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
 

提示：

0 <= num < 231
*/


/*
状态定义： 设动态规划列表 dp，dp[i]代表以 x_i为结尾的数字的翻译方案数量。
则当x_i-1 x_i 在10到25之间时， dp[i]  = dp[i-1]+dp[i-2]
否则 dp[i]=dp[i-1]
*/

class Solution {
public:

    int translateNum(int num) {

        
        string s = to_string(num);

        int a = 1;//dp[i-1]
        int b = 1; //dp[i-2]

        for(int i=2;i<=s.size();i++){
            
            string tmp = s.substr(i - 2, 2);
           
            int c = stoi(tmp) >= 10 && stoi(tmp) <= 25 ? a + b : a; 
            b = a;
            a = c;

        }
        return a;

    }
};
