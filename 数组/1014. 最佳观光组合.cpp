/*

给定正整数数组 A，A[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的距离为 j - i。
一对景点（i < j）组成的观光组合的得分为（A[i] + A[j] + i - j）：景点的评分之和减去它们两者之间的距离。
返回一对观光景点能取得的最高分。

示例：
输入：[8,1,5,2,6]
输出：11
解释：i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11 

提示：
2 <= A.length <= 50000
1 <= A[i] <= 1000
*/

//方法一：官方
/*
求A[i]+i+A[j]-j最大值， A[j]-j其实是固定的，遍历时找他左边最大的A[i]+i即可

*/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ans = 0, mx = A[0] + 0;
        for (int j = 1; j < A.size(); ++j) {
            ans = max(ans, mx + A[j] - j);
            // 边遍历边维护
            mx = max(mx, A[j] + j); //当前最大的A[i]+i
        }
        return ans;
    }
};

//方法二：自己 超时了！
/*
自己也想到了分解成A[i]+i 和A[j]-j， 然后把A[i]+i 固定，找最大的A[j]-j去了， 这样就得保存住所有i后面的A[j]-j，然后再找最大值。 
而如果把A[j]-j，只用在遍历j的时候把A[i]+i的最大值找到就行。。。
好气
*/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {

        int ans=0;
        int n = A.size();
        vector<int> Ai;
        for(int i=n-1;i>=0;i--){ 
           
            Ai.push_back(A[i]-i);
            
              //Ai放A[i]减i的值 逆序

        }

        //int max_iv =  *max_element(Ai.begin(),Ai.end()); //最大的A[j]-[j]  
        int maxPosition = max_element(Ai.begin(),Ai.end()) - Ai.begin(); //最大值的索引 
    
        for(int i=0;i<n-1;i++){

            Ai.pop_back();
            if(i>=(n-1-maxPosition)){
                maxPosition = max_element(Ai.begin(),Ai.end()) - Ai.begin();
                //size=Ai.size();
            }
            int sum_i = A[i]+i+Ai[maxPosition];

            if(sum_i>ans){
                ans = sum_i;
            }
        }

        
        return ans;
    }
};

