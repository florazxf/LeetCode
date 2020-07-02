/*
给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。

 

示例：

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。

*/

//方法一：自己的方法 建最小堆
class Solution {
public:

    void AdjustHeap(vector<vector<int>>& matrix,int i, int HeatSize){//调整最小堆
        int l = 2*i+1;
        int r = 2*i+2;
        int MinValue = i;
        int n=matrix.size();
        if(l<HeatSize && matrix[l/n][l%n]<matrix[MinValue/n][MinValue%n]){
            MinValue = l;
        }

        if(r<HeatSize && matrix[r/n][r%n]<matrix[MinValue/n][MinValue%n]){
            MinValue = r;
        }
        if(MinValue!=i){
            swap(matrix[MinValue/n][MinValue%n],matrix[i/n][i%n]);
            AdjustHeap(matrix,MinValue,HeatSize);
        }

    }
    void CreateHeat(vector<vector<int>>& matrix, int HeatSize){//创建最小堆
        for(int i=HeatSize/2;i>=0;--i){
            AdjustHeap(matrix,i,HeatSize);
        }
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();
        int HeatSize = n*n;
        CreateHeat(matrix,HeatSize);
        //删除小顶堆的前k个元素
        for(int i=HeatSize-1;i>n*n-k;--i){
            cout<<i<<' ';
            swap(matrix[0][0],matrix[i/n][i%n]);//堆顶元素和最后一个元素交换
            --HeatSize;//堆的数目减1
            AdjustHeap(matrix,0,HeatSize);
        }
        return matrix[0][0];
    }
};
