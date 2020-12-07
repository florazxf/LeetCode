/*
有一个二维矩阵 A 其中每个元素的值为 0 或 1 。

移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。

在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。

返回尽可能高的分数。

 

示例：

输入：[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
输出：39
解释：
转换为 [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

*/

//方法一:

/*
贪心就是按照我们本身的思路 实现出来就好
我们需要第一列都是1,这样最后的值才会高因此
第一步: 将每一行最左边的数 都变成1
第二步: 将剩余列中1尽可能多
第三步:计算
*/
    public int matrixScore(int[][] A) {

        int m = A.length;
        int n = A[0].length;

        //将每一行最左边的数 变为1
        for (int i = 0; i < m; i++) {
            if(A[i][0]!=1){
                for (int j = 0; j < n; j++) {
                    A[i][j] = A[i][j] == 0 ? 1 : 0;
                }
            }

        }

        //第二列开始
        for(int j=1;j<n;j++){
            int count= 0;//得到当前列的个数
            for (int i=0;i<m;i++){
                if(A[i][j]==1){
                    count++;
                }
            }
            //如果当前列个数1少0多 则翻转
            if(count<(m+1)/2){
                for (int i=0;i<m;i++){
                    A[i][j] = A[i][j] == 0 ? 1 : 0;
                }
            }
        }
        int ans = 0;
        //计算结果
        for(int j=0;j<n;j++){
            int temp = (int)Math.pow((double)2,(double)(n-j-1));
            for (int i=0;i<m;i++){
                ans+=A[i][j]*temp;
            }
        }

        return ans;
    }
    
    //方法二"
    /*
    其实我们不用实际都矩阵进行操作,直接计算就可以得到答案
    因为我们已经保证第一列都是1, 然后其余列只要计算出每列1多还是0多 得到这个多的数 就可以进行计算了
    注意:要考虑第一列有没有翻转
    */
    
    class Solution {
    public int matrixScore(int[][] A) {

        int m = A.length;
        int n = A[0].length;

        int ret = m*(1<<(n-1));

        //第二列开始 计算每列 最多1的数量
        for(int j=1;j<n;j++){
            int count= 0;//得到当前列的个数
            for (int i=0;i<m;i++){
                if(A[i][0]==1){
                    count+=A[i][j];
                }
                else {
                    count+=(1-A[i][j]); // 如果这一行进行了行反转，则该元素的实际取值为 1 - A[i][j]
                }
            }

            int k = Math.max(count,m-count);
            ret+=k*(1<<(n-j-1));

        }


        return ret;
    }
}
