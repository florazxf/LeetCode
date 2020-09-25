/*
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
示例 1:
输入: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2:
输入: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
进阶:
	一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
	一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
	你能想出一个常数空间的解决方案吗？

*/

//方法一：
/*
空间复杂度 O(m+n)
先遍历一遍 用数组把第i行和第j列是0的都存下来
*/
class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int [] zero = new int[m+n];
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){

                if(matrix[i][j]==0){
                    zero[i] = 1;
                    zero[m+j]=1;
                }
            }
        }

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){

                if(zero[i]==1 || zero[m+j]==1){
                    matrix[i][j]=0;
                }
            }
        }
    }
}

/*
题解用的是hash表存
*/

class Solution {
  public void setZeroes(int[][] matrix) {
    int R = matrix.length;
    int C = matrix[0].length;
    Set<Integer> rows = new HashSet<Integer>();
    Set<Integer> cols = new HashSet<Integer>();

    // Essentially, we mark the rows and columns that are to be made zero
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (matrix[i][j] == 0) {
          rows.add(i);
          cols.add(j);
        }
      }
    }

    // Iterate over the array once again and using the rows and cols sets, update the elements.
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (rows.contains(i) || cols.contains(j)) {
          matrix[i][j] = 0;
        }
      }
    }
  }
}

//方法二：
/*
用第一行和第一列来标记 这一行这一列是否有零

由于第一行和第一列可能本身会有0，所以应该先提前做一个标记
*/

class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        boolean rowZero = false;
        boolean colZero = false;

        // 第一行本身有没有零
        for(int i = 0;i<n;i++){
            if(matrix[0][i]==0){
                rowZero = true;                
            }
        }

        //第一列本身有没有零
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                colZero = true;
            }
        }

        //用第一行第一列做标记
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        //根据标记修改matrix的值
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }
        }
        //修改第一行的值
        if(rowZero){
            for(int i = 0;i<n;i++){
                matrix[0][i] = 0;
            }
        }
        //修改第一列的值
        if(colZero){
            for(int i = 0;i<m;i++){
                matrix[i][0] = 0;
            }
        }
    
    }
}
