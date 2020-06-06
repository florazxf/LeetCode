/*
给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

*/
//方法一：暴力法(自己的方法)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()==0) return 0;
    
        set<int> s(nums.begin(),nums.end()); //把vector转成set
        nums.clear();
        
        int cnt=1;
        int ans = 1;

        set<int>::iterator it;

        //把set转成vector
        for( it = s.begin();it!=s.end();++it){
            nums.push_back(*it);
        }

        for(int i=0;i<nums.size()-1;i++){

            if(nums[i+1]==(nums[i]+1)){ //连续
                cnt++;
                
            }
            else{
                if(cnt>ans){ //不连续记下当前最大连续长度
                    ans = cnt;
                }

                cnt=1;
            }
           
        }
        
        if(cnt>ans){
                    ans = cnt;
                }
        return ans;

    }
};

//方法二：哈希表

/*
①去重，不需要排序
②遍历集合，看当前元素减一后是否在集合中，不在的话就找以这个元素为起始点的最大长度
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()==0) return 0;

        //去重

        
        unordered_set<int> s(nums.begin(),nums.end()); //把vector转成set，因为查找元素在不在，所以无需排序

        int MaxCnt=0;

         for(const int& num:s){
            
             //我们要的最大长度，则起始元素的前一个元素不会出现在s中

             if(s.count(num-1)==0){ //前一个元素不在s中
                 
                 int curnum = num;
                 int curcnt = 1;

                 while(s.count(curnum+1)){ //该元素加1后的值也在s中{
                     curnum +=1;
                     curcnt +=1;
                 }
                 MaxCnt = max(curcnt,MaxCnt);
             }
         }

         return MaxCnt;
    }
};




//方法三：并查集

/*
初始化的时候先把数组里每个元素初始化为他的下一个数；
并的时候找他能到达的最远的数字就可以了。
*/

class Solution {
public:
    unordered_map<int,int> a,b;
    int find(int x){
        return a.count(x)?a[x]=find(a[x]):x;
    }
    int longestConsecutive(vector<int>& nums) {
        for(auto i:nums)
            a[i]=i+1;
        int ans=0;
        for(auto i:nums){
            int y=find(i+1);
            ans=max(ans,y-i);
        }
        return ans;
    }
};
