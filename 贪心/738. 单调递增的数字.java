/*
给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。

（当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）
示例 1:

输入: N = 10
输出: 9
示例 2:

输入: N = 1234
输出: 1234
示例 3:

输入: N = 332
输出: 299
说明: N 是在 [0, 10^9] 范围内的一个整数。

*/

//方法一：暴力 超时  第一反应就是暴力，但是超时了

//方法二：贪心
/*
用贪心的思路想就是看当前位比前一位小的话，那为了得到的数字大就只能是9，当前是9那前一位就是减1.
当前位变成9之后，当前位后面的可能右比当前位小了，所以要把后面的也判断一下
*/

class Solution {
    public int monotoneIncreasingDigits(int N) {


        char[] chars = Integer.toString(N).toCharArray(); //int 转char
        for (int i = chars.length-1; i >0; i--) {

            if(chars[i]<chars[i-1]){
                chars[i] = '9';
                if(chars[i-1]=='0'){
                    chars[i-1] = '9';
                }
                else{ //前一个数减一
                    chars[i-1] -= 1; //必须用这种形式
                }
                int k = i+1;
                while(k<chars.length){
                    if(chars[k]<chars[i]){
                        chars[k] = chars[i];
                    }
                    k++;
                }
            }

        }


        return Integer.parseInt(new String(chars)); //char转int

    }
}
