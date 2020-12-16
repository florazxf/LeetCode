/*
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/

//回溯 
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        ArrayList<Integer> path = new ArrayList<Integer>();
        dfs(ans,path,nums,0);
        return ans;
    }
    public void dfs(List<List<Integer>> ans,ArrayList<Integer> path,int[] nums,int begin){
        ans.add(new ArrayList<>(path));

        for(int i= begin;i<nums.length;i++){
            if(i>begin && nums[i]==nums[i-1]){ //去重 同一层的相同元素 只保留第一个
                continue;
            }
            path.add(nums[i]);
            dfs(ans,path,nums,i+1);
            path.remove(path.size()-1);
        }
    }
}
