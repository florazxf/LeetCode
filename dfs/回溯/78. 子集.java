/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

//方法一：回溯 自己写的
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer> path = new ArrayList<Integer>();
        dfs(ans,path,nums,0,nums.length);
        ans.add(new ArrayList<>());
        return ans;
    }

    public void dfs(List<List<Integer>> ans,List<Integer> path,int[] nums,int begin,int length){
        //终止条件
        if(begin==length){
            return ;
        }

        for(int i=begin;i<length;i++){
            path.add(nums[i]);
            ans.add(new ArrayList<>(path));//每一个结点都要
            dfs(ans,path,nums,i+1,length);
            path.remove(path.size()-1);
        }
    }
}

//题解的回溯 少判断一点


class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer> path = new ArrayList<Integer>();
        dfs(ans,path,nums,0,nums.length);
        return ans;
    }

    public void dfs(List<List<Integer>> ans,List<Integer> path,int[] nums,int begin,int length){

        ans.add(new ArrayList<>(path));//每一个结点都要
        for(int i=begin;i<length;i++){
            path.add(nums[i]);
            
            dfs(ans,path,nums,i+1,length);
            path.remove(path.size()-1);
        }
    }
}

//方法二： 递归 可以用选和不选的方式 生成数

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer> path = new ArrayList<Integer>();
        dfs(ans,path,nums,0,nums.length);
        return ans;
    }

    public void dfs(List<List<Integer>> ans,List<Integer> path,int[] nums,int index,int length){
        //终止条件 叶节点
        if(index ==length){
            ans.add(new ArrayList<>(path));
            return ;
        }
        //走不选这个分支
        dfs(ans,path,nums,index+1,length);

        //走选这个分支
        path.add(nums[index]);
        dfs(ans,path,nums,index+1,length);
        //撤销选择
        path.remove(path.size()-1);
        

    }
}
