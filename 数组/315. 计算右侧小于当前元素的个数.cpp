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
/*
为什么要想到用树状数组？
树状数组用来修改某个点的值、求某个区间的和的时间复杂度是O(logN)
而我们找比nums[i]小的元素，就是要把其后比他小的所有元素出现的次数加起来，所以用树状数组很方便
*/

/*
用桶来表示nums中的数，桶中记录这些数字出现的次数。我们用数组a实现这个桶，用离散化优化空间。
具体离散化的方法：将nums去重后排序 对应代码的Discretization函数


从后往前遍历nums，先找到其在桶a中的位置id
开始用树状数组来计算 id左边所有数字出现次数总和
① Query 得到id左边的数出现次数的和，由于c保存了相应数出现次数的和，只需要从id-1开始根据LowBit找到所有比id小的数的c即可
② Update 当前数出现次数加1，那么和其相关的c的值也要更新
*/
class Solution {
public:
    //a和c用LowBit来联系
    vector<int> a;//离散化后的结果
    vector<int> c;//树状数组 桶中相应数出现次数的和，这个相应数就是用LowBit求出来的
    void Init(int length){
        c.resize(length,0);
    }
    int LowBit(int x){//联系a和c
        return x&(-x);
    }
    //单点更新：从子节点更新到所有父节点
    void Update(int pos){//a[i]+1，则和a[i]有关的c[i]都要更新
        while(pos<c.size()){
            c[pos] +=1;
            pos += LowBit(pos);
        }
    }
    //求和[0,..,id-1]
    int Query(int pos){//把id左边的c都加起来 也就是比nums[i]小的值出现的次数和
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
            //Query就是用树状数组把id左边的所有数字出现的次数加起来
            resultList.push_back(Query(id-1));//Query(id-1)求id-1的前缀和
            //因为每遍历一个nums[i]，这个值出现的次数a[i]就要更新，那和a[i]有关的c的值就也要更新
            Update(id);
        }
        reverse(resultList.begin(),resultList.end());
        return resultList;
    }
};

//方法二：归并排序

