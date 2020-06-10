/*

判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
进阶:

你能不将整数转为字符串来解决这个问题吗？
*/

//方法一：把整数转成字符串
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }

            i++;
            j--;
        }
        return true;

 
    }
};

//方法二： 反转一半数字
class Solution {
public:
    bool isPalindrome(int x) {
        //反转一半数字
        if(x<0 || (x%10==0 && x!=0)) return false;
        int reversed_x=0;
        while(reversed_x<x){ //当reversed_x大于等于x证明已经翻译一半了
            reversed_x = reversed_x*10+x%10;
            x=x/10;
        }

        return (x==reversed_x) || (x==reversed_x/10); //当输入数字为奇数时 我们除10去除


    }
};
