/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
*/

class Solution {
public:
    int reverse(int x) {      
        
        //用long型存储转换后的结果判断是否越界，因为int越界后会出现意想不到的结果,题目规定的数据范围在long类型怎么反转都不会越界
        long n = 0;
        int flag = 0;
        long m;
        if(x<0){
            if(x==-2147483648){
                return 0;
            }
            flag = 1;
            x = -x;
        }
        
        while(x>0){
            n = n*10+x%10;
            x = x/10;
        }
        if(n>=2147483647)
            return 0;
        if(flag==1){
            n = -n;
        }
        return n;
        
    }
};
