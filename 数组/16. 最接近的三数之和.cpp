/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

 

示例：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。


*/


//方法一：自己的方法
/*
先排序，然后固定最左边的数，再通过双指针 找最接近target的sum
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());//排序
        int best=INT_MAX;
        int bestc = INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
            int left = i+1;
            int right = nums.size()-1;
            
            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                if(sum<target){
                    left++;
                }
                else if(sum>target){
                    right--;
                }
                else{ //已经找到和target相等的值了
                    return target;
                }
                
                if(abs(sum-target)<bestc){
                    bestc = abs(sum-target);
                    best = sum;
                }
                //cout<<sum<<endl;
            }
        }
        return best;

    }
};

//优化 

/*
当我们枚举 
a,b,ca, b, c
a,b,c 中任意元素并移动指针时，可以直接将其移动到下一个与这次枚举到的不相同的元素，减少枚举的次数。
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());//排序
        int ans = nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-1;i++){
            int left = i+1;
            int right = nums.size()-1;

            // 保证和上一次枚举的元素不相等
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];

                if(abs(sum-target)<abs(ans-target)){
                    ans = sum;
                }
                if(sum<target){
                    
                    int nextleft = left+1;
                    //移到下一个不相等的元素
                    while(nextleft<right&&nums[nextleft]==nums[left]){
                        nextleft++;
                    }
                    left = nextleft;
                }
                else if(sum>target){
                    
                    int nextright = right-1;
                    //移到下一个不相等的元素
                    while(nextright>left && nums[nextright]==nums[right]){
                        nextright--;
                    }
                    right = nextright;
                }
                else{ //已经找到和target相等的值了
                    return target;
                }
                

                
            }
        }
        return ans;

    }
};
