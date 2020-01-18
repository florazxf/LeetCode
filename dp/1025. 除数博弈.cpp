/*
爱丽丝和鲍勃一起玩游戏，他们轮流行动。爱丽丝先手开局。

最初，黑板上有一个数字 N 。在每个玩家的回合，玩家需要执行以下操作：

选出任一 x，满足 0 < x < N 且 N % x == 0 。
用 N - x 替换黑板上的数字 N 。
如果玩家无法执行这些操作，就会输掉游戏。

只有在爱丽丝在游戏中取得胜利时才返回 True，否则返回 false。假设两个玩家都以最佳状态参与游戏。

 

示例 1：

输入：2
输出：true
解释：爱丽丝选择 1，鲍勃无法进行操作。
示例 2：

输入：3
输出：false
解释：爱丽丝选择 1，鲍勃也选择 1，然后爱丽丝无法进行操作。
 

提示：

1 <= N <= 1000

*/

//方法一：
//第一次自己做的方法，按照题目的意思做了一遍，本来想的是遍历1到N，但是从x=1开始选，其实每次选的都是1

class Solution {
public:
    bool divisorGame(int N) {
        if(N==1){
            return false;
        }
        int k=0;
        int x=0;
        while(x<N){

            x++;

            if(N%x==0){
                N=N-x;
                k++; //Alice做k是奇数
                x=0;
            }
            if(N==1){
                break;
            }
        
        }
            

        if(k%2==0){
            return false;
        }
        else{
            return true;
        }
    }
};

//方法二：
class Solution {
public:
    bool divisorGame(int N) {

        if(N%2==0){
            return true;
        }
        else{ //N是奇数Alice输
            return false;
        }
    }
};
