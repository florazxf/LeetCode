/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]
示例 2：

输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
 

提示：

1 <= candidates.length <= 30
1 <= candidates[i] <= 200
candidate 中的每个元素都是独一无二的。
1 <= target <= 500
*/

//方法一：

/*
https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/
1. 首先注意i要从begin开始 这样去重 即本层前面用过的结点 接下来往下递归的时候就不选了
2. 为了剪枝，把target-candidates[i]<0 排除， 就要先排序
*/
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {

        Arrays.sort(candidates);

        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        ArrayList<Integer> path = new ArrayList<Integer>();

        backtrack(candidates,0,0,target,path,ans);
        return ans;

    }
    public void backtrack(int[] candidates, int begin,int depth,int target, List<Integer> path,List<List<Integer>> ans){
        //终止条件

        if(target==0){
            ans.add(new ArrayList<Integer>(path));
            return ;
        }

        for(int i=begin;i<candidates.length;i++){//从begin 开始 去重

            if(target-candidates[i]<0){
                break;
            }
            path.add(candidates[i]);
            backtrack(candidates,i,depth+1,target-candidates[i],path,ans); //注意是i 因为可以重复选
            path.remove(path.size()-1);
        }
        
        
    }
}
//方法二： 看每个数选还是不选

/*
我们定义递归函数 dfs(target, combine, idx) 表示当前在 candidates 数组的第 idx 位，还剩 target 要组合，已经组合的列表为 combine。递归的终止条件为 target <= 0 或者 candidates 数组被全部用完。那么在当前的函数中，每次我们可以选择跳过不用第 idx 个数，即执行 dfs(target, combine, idx + 1)。也可以选择使用第 idx 个数，即执行 dfs(target - candidates[idx], combine, idx)，注意到每个数字可以被无限制重复选取，因此搜索的下标仍为 idx。
*/
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {

        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        ArrayList<Integer> combine = new ArrayList<Integer>();

        backtrack(candidates,0,target,combine,ans);
        return ans;

    }
    public void backtrack(int[] candidates, int index,int target, List<Integer> combine,List<List<Integer>> ans){
        //终止条件
        if(index==candidates.length){
            return ;
        }
        if(target==0){
            ans.add(new ArrayList<Integer>(combine));
            return ;
        }
        //直接跳过
        backtrack(candidates,index+1,target,combine,ans); //不选当前index指的数

        //选当前index指的数
        if(target-candidates[index]>=0){
            combine.add(candidates[index]);
            backtrack(candidates,index,target-candidates[index],combine,ans);
            combine.remove(combine.size()-1);
        }
        
        
    }
}
