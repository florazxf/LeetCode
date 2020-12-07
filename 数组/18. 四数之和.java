/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

*/

// 延续之前三数之和的方法 ,外面再加一个循环即可
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {

        //先给nums排序
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<List<Integer>>();

        int n = nums.length;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {

                int l = j+1;
                int r = n-1;
                //求两数之和
                while(l<r){
                    int sum = nums[l]+nums[r]+nums[i]+nums[j];
                    int left = nums[l];
                    int right = nums[r];
                    if(sum<target){
                        while(l<r && nums[l]==left){
                            l++;
                        }
                    }
                    else if(sum>target){
                        while(l<r && nums[r]==right){
                            r--;
                        }
                    }
                    else{
                        List<Integer> list = new ArrayList<Integer>();
                        list.add(nums[i]);
                        list.add(nums[j]);
                        list.add(nums[l]);
                        list.add(nums[r]);
                        ans.add(list);
                        while(l<r && nums[l]==left){
                            l++;
                        }
                        while(l<r && nums[r]==right){
                            r--;
                        }
                    }

                }

                while(j<n-1 && nums[j]==nums[j+1]){
                    j++;
                }
            }
            while(i<n-1 && nums[i]==nums[i+1]){
                i++;
            }


        }


        return ans;

    }
}
