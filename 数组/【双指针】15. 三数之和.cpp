/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

*/
//方法一：自己的方法
/*
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());//对nums从小到大排序
        vector<int>tmp;
        //超级多0的情况下
       if(nums.size()>=3 && nums[0]==0 && nums[1]==0&& nums[2]==0)
       {
        tmp.push_back(0);
        tmp.push_back(0);
        tmp.push_back(0);
        ans.push_back(tmp);
           return ans;
       }

        int left=0;
        int right = nums.size()-1;
       
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0){ //有负数的情况
                left = i+1;
                right = nums.size()-1;

                while(left<right){
                    
                    if(nums[left]+nums[right]+nums[i]<0){//加的负数太小了 需要加小大的负数
                        left++;
                    }
                    else if(nums[left]+nums[right]+nums[i]>0){//加的正数太大了  需要加小点的正数
                        right--;
                    }
                    else{//等于0符合条件
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[left]);
                        tmp.push_back(nums[right]);
                        /*
                        if(ans.size()!=0){
                             for(vector<int> ansi:ans){

                                if(ansi==tmp){
                                 flag=1;
                                break;
                            }

                             }
                             

                        }*/
                        
                        //if(flag==0){
                            ans.push_back(tmp);

                        //}
                        
                        tmp.clear();
                        left++;
                        //flag=0;

                    }
                }


            }
            else{ //num>0就找不到匹配的了
                set<vector<int>> s(ans.begin(),ans.end()); // vector 转set
                ans.assign(s.begin(),s.end()); //set转vector
                return ans;
            }
        }

        set<vector<int>> s(ans.begin(),ans.end());
        ans.assign(s.begin(),s.end());

        return ans;

    }
};
