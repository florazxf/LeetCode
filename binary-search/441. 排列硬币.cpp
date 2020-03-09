/*
你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。

给定一个数字 n，找出可形成完整阶梯行的总行数。

n 是一个非负整数，并且在32位有符号整型的范围内。

示例 1:

n = 5

硬币可排列成以下几行:
¤
¤ ¤
¤ ¤

因为第三行不完整，所以返回2.
示例 2:

n = 8

硬币可排列成以下几行:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

因为第四行不完整，所以返回3.

*/

//方法一：
class Solution {
public:
    int arrangeCoins(int n) {

        int k=1;

        while(n){
            if(n>k){
                n=n-k;
            }
            else if(n==k){
                return k;
            }
            else{
                return k-1;
            }
            
            k++;
        }

        return 0;

    }
};

//方法二：
/*
等差数列公式k*(k+1)/2=n 就是我们从1到第k行的硬币和为n
k = sqrt(2n+1/4) - 1/2。然后求整即可。
唯一的问题是，这里2n+1/4有可能会超出sqrt函数的参数范围。
于是，我们可以变换一下， k = sqrt(2) * sqrt(n+1/8) - 1/2，这样求平方根就不会超限了。

class Solution {
public:
    int arrangeCoins(int n) {
        return int(sqrt(2)*sqrt(n+0.125)-0.5);

    }
};
*/
