/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

 

示例 1:

输入: [7,5,6,4]
输出: 5

*/

//转化一下题目就是 找当前数右边比自己小的元素的个数 就和 315. 计算右侧小于当前元素的个数 一样！

//树状数组 从右往左遍历统计每个位置右侧小于当前元素的个数

class Solution {
public:
    vector<int>a;
    vector<int>c;
    int LowBit(int x){
        return x&(-x);
    }
    void Update(int pos){
        while(pos<c.size()){
            c[pos]++;
            pos+=LowBit(pos);
        }
    }
    int Query(int pos){
        int res = 0;
        while(pos>0){
            res+=c[pos];
            pos-=LowBit(pos);
        }
        return res;
    }
    
    int reversePairs(vector<int>& nums) {
        int ans=0;
        //离散化
        a.assign(nums.begin(),nums.end());
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());

        c.resize(nums.size()+5,0);
        
        //从后往前遍历 找所有比当前元素小的数的个数和
        for(int i=nums.size()-1;i>=0;--i){
            
            int id = lower_bound(a.begin(), a.end(), nums[i]) - a.begin() + 1;
            ans = ans+Query(id-1);
            Update(id);
        
        }
        return ans;
    }
};
