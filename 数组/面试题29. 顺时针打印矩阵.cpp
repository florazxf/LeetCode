/*

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

 

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

限制：

0 <= matrix.length <= 100
0 <= matrix[i].length <= 100
*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        

        int m = matrix.size(); //矩阵的行数

        if(m==0){
            vector<int> k;
            return k;}
        int n = matrix[0].size(); //矩阵的列数
        vector<int> ans(m*n);
       

        int cur0 = 0;
        int curm = m; 
        int curn = n;
        int curc = 0;

        int cnt=0; //放进ans中的数量
        int index = 0; //ans中的索引
        while(index<m*n){

            int add = curn-curc+curm-cur0-2;
            int add1 = curn-curc + curm-cur0-2;

            int jc=0;

        //把第cur0行和第curm-1行放进ans中, cur0的当前元素在ans中的index时，curm-1行对应元素索引为index+add
            for(int j=curc;j<curn;j++){    
                
                ans[index] = matrix[cur0][j]; //顺序取该行(cur0)每一个元素
                cnt++;
                if(add!=0 &&cur0!=(curm-1)){
                    ans[index+add] = matrix[curm-1][curn-jc-1]; //逆序取该行(curm-1)每一个元素
                    jc++;
                    cnt++;
                }
                index++;
            }
           

            if(cnt==m*n){
                return ans;
            }


            int ic=1;
            for(int i=cur0+1; i<curm-1;i++){ //从下到上取每一行的第一个元素

                    ans[index] = matrix[i][curn-1]; //该行最后一个元素
                    cnt++;
                    if(add1!=0 && curc!=(curn-1)){
                        ans[index+add1] = matrix[curm-ic-1][curc]; //该行第一个元素
                        ic++;
                        cnt++;
                    }
                    index++;

                    if(i==curm-2){
                        index = index+add1;
                    }

            }

            

            cur0++;
            curm--;
            curn--;
            curc++;

            

        }

        return ans;

    }
};
