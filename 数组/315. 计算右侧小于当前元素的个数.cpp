/*
给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

 

示例：

输入：[5,2,6,1]
输出：[2,1,1,0] 
解释：
5 的右侧有 2 个更小的元素 (2 和 1)
2 的右侧仅有 1 个更小的元素 (1)
6 的右侧有 1 个更小的元素 (1)
1 的右侧有 0 个更小的元素

*/


//方法一：离散化树状数组

class Solution {
public:
    vector<int> a;//离散化后的结果
    vector<int> c;//前缀和
    void Init(int length){
        c.resize(length,0);
    }
    int LowBit(int x){
        return x&(-x);
    }
    void Update(int pos){//把id后的桶的值都加1
        while(pos<c.size()){
            c[pos] +=1;
            pos += LowBit(pos);
        }
    }
    int Query(int pos){//得到id-1的前缀和
        int ret = 0;
        while(pos >0){
            ret+=c[pos];
            pos -= LowBit(pos);
        }
        return ret;
    }
    void Discretization(vector<int> &nums){//离散化：把原数组去重后排序
        a.assign(nums.begin(),nums.end());//把nums的内容复制到a中
        sort(a.begin(),a.end());//排序
        a.erase(unique(a.begin(),a.end()),a.end());//unique把相邻的重复元素去重， erase把后面剩下的元素删除
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> resultList;
        Discretization(nums);//离散化 把原序列的值域映射到一个连续的整数区间
        Init(nums.size()+5);//将c初始化为长度为nums.size()+5,值为0的数组
        for(int i=(int)nums.size()-1;i>=0;--i){//从后往前遍历数组
            int id = lower_bound(a.begin(),a.end(),nums[i]) - a.begin()+1;//得到当前数字在桶中(a中)的id
            //id-1的前缀和就是nums[i]的结果 即已入桶的元素比nums[i]小的元素的个数总和
            resultList.push_back(Query(id-1));//Query(id-1)求id-1的前缀和
            //把a中nums[i]及其后(>nums[i])的桶的值+1
            Update(id);
        }
        reverse(resultList.begin(),resultList.end());
        return resultList;
    }
};
