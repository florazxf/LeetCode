/*
给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。
只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 

示例 1：
输入：["a==b","b!=a"]
输出：false
解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。

示例 2：
输出：["b==a","a==b"]
输入：true
解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。

示例 3：
输入：["a==b","b==c","a==c"]
输出：true

示例 4：
输入：["a==b","b!=c","c==a"]
输出：false

示例 5：
输入：["c==c","b==d","x!=z"]
输出：true
 

提示：

1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] 和 equations[i][3] 是小写字母
equations[i][1] 要么是 '='，要么是 '!'
equations[i][2] 是 '='

*/

//方法一
class Solution {
public:
    int pre[30]; //记录每个点的前驱节点

    //查找
    int find(int x){        //查找根节点
        int r = x;
        while(r!=pre[r]){   //返回根节点
            r = pre[r];
        }
        //路径压缩 尽量把每个节点的前驱结点直接设成根节点
        int i = x;
        int j; //临时变量

        while(i!=r){
            j=pre[i];
            pre[i]=r; //把i的前驱结点直接改成根节点
            i = j;
        }

        return r; //返回要查找的x对应的根节点
    }

    //合并
    void join(int x,int y){
        int fx = find(x);//查找x的根节点
        int fy = find(y);//查找y的根节点

        if(fx!=fy){
            pre[fx] = fy; //合并
        }
        
    }
    bool equationsPossible(vector<string>& equations) {

        


        //初始化 每个节点的根节点都是他本身
        for(string equation:equations){
            pre[equation[0]-'a'] = equation[0]-'a';
            pre[equation[3]-'a'] = equation[3]-'a';     
        }
        //合并节点
        for(string equation:equations){


            if(equation[1]=='='){ //等式是等于 则把等式左右两边合并
                join(equation[0]-'a',equation[3]-'a');
            }

        }

        for(string equation:equations){
            if(equation[1]=='!'){//等式是不等于

                if(find(equation[0]-'a')==find(equation[3]-'a')){
                    return false;
                }

            }
        }

        
        return true;
    }
};
