/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

/*
第一步：画树形图
 想递归终止条件
 题目需要的解在哪里（叶子节点？从根结点到叶子结点的路径？）
 https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/
*/

class Solution {
    public List<List<Integer>> permute(int[] nums) {
        int n = nums.length;

        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer> path = new ArrayList<Integer>();
        boolean[] used = new boolean[n];
        dfs(ans,path,0,used,nums);
        return ans;

    }


    public void dfs(List<List<Integer>> ans,List<Integer> path,int depth,boolean[] used,int[] nums){

        //终止条件
        if(depth==nums.length){
            ans.add(new ArrayList<Integer>(path));//因为java是值传递，所以我们一定要拷贝一份
            return ;
        }

        //本层的遍历
        // 从剩下未选的数中选一个数
        for(int i=0;i<nums.length;i++){
            if(!used[i]){//当前数没被选过 则可以选
                used[i] = true;
                path.add(nums[i]);
                dfs(ans,path,depth+1,used,nums);
                //移除，恢复状态
                used[i] = false;
                path.remove(path.size()-1);
            }
        }

    }
}
