/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

示例 1：
输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：
输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 

限制：
1 <= target <= 10^5

*/



//方法一：自己的方法
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {


        vector<int> eveans;

        vector<vector<int>> ans;
        int i = 1;
        int sum=0;
        int begin=1;
        int end;
        while(begin<target){
            
            sum+=i;
            i++;
            if(sum==target){
                end=i;
                for(int k=begin;k<end;k++){
                    eveans.push_back(k);
                }
                ans.push_back(eveans);
                eveans.clear();
                
            }
            else if(sum>target){

                begin++;
                i=begin;
                sum=0;
            }
            
        }

        return ans;

    }
};

//方法二：双指针

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {


        vector<int> eveans;
        vector<vector<int>> ans;
        
        int sum=0;
        int l=1;
        int r=2;

        while(l<r){
            int sum=(l+r)*(r-l+1)/2;//等差数列求和公式
            if(sum==target){
                for(int k=l;k<=r;k++){
                    eveans.emplace_back(k);
                }
                ans.emplace_back(eveans);
                eveans.clear();
                l++;
            }
            else if(sum<target){ //和比target小则r向右
                r++;
            }
            else{ //和比target大，证明以l为起点的没有满足条件的，所以l++
                l++;
            }
        }
        return ans;

    }
};
