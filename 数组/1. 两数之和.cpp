/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

 

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

//方法一：hashmap 一次遍历
/*
hashmap<数字值，数字索引>
遍历nums[i]，取得b=target-nums[i]
如果hashmap中存在b，则找到。 如果不存在就把nums[i]存到hashmap中
在进行迭代并将元素插入到表中的同时，我们还会回过头来检查表中是否已经存在当前元素所对应的目标元素。如果它存在，那我们已经找到了对应解，并立即将其返回。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ans;
        unordered_map<int, int> hash;//<数字值，数字索引>
        for(int i=0;i<nums.size();i++){
            int valuetofind = target-nums[i]; //要找的数
            if(hash.find(valuetofind)!=hash.end()){ //要找的数已经存在了哈希表中
                ans.push_back(hash[valuetofind]);
                ans.push_back(i);
                return ans;
            }
            //把当前的数存到hashmap中
            hash[nums[i]]=i;
        }
        return ans;
    }
};

//方法二： hashmap 两次遍历
/*
在第一次迭代中，我们将每个元素的值和它的索引添加到表中。
在第二次迭代中，我们将检查每个元素所对应的目标元素（target - nums[i]）是否存在于表中
注意，该目标元素不能是 nums[i]nums[i] 本身！

作者：LeetCode

*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ans;
        unordered_map<int, int> hash;//<数字值，数字索引>
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]=i;//存在每个值及其对应的索引
        }

        for(int i=0;i<nums.size();i++){
            int valuetofind = target-nums[i]; //要找的数
            if(hash.find(valuetofind)!=hash.end()&&hash[valuetofind]!=i){ //要注意目标元素不能是他本身
                ans.push_back(i);
                ans.push_back(hash[valuetofind]);
                return ans;
            }
        }
        return ans;
    }
};
//方法三：暴力法
