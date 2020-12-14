/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
*/
//官方

public class Solution {

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        int len = candidates.length;
        List<List<Integer>> res = new ArrayList<>();
        if (len == 0) {
            return res;
        }

        // 关键步骤
        Arrays.sort(candidates);

        Deque<Integer> path = new ArrayDeque<>(len);
        dfs(candidates, len, 0, target, path, res);
        return res;
    }

    /**
     * @param candidates 候选数组
     * @param len        冗余变量
     * @param begin      从候选数组的 begin 位置开始搜索
     * @param target     表示剩余，这个值一开始等于 target，基于题目中说明的"所有数字（包括目标数）都是正整数"这个条件
     * @param path       从根结点到叶子结点的路径
     * @param res
     */
    private void dfs(int[] candidates, int len, int begin, int target, Deque<Integer> path, List<List<Integer>> res) {
        if (target == 0) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (int i = begin; i < len; i++) {
            // 大剪枝：减去 candidates[i] 小于 0，减去后面的 candidates[i + 1]、candidates[i + 2] 肯定也小于 0，因此用 break
            if (target - candidates[i] < 0) {
                break;
            }

            // 小剪枝：同一层相同数值的结点，从第 2 个开始，候选数更少，结果一定发生重复，因此跳过，用 continue
            if (i > begin && candidates[i] == candidates[i - 1]) {
                continue;
            }

            path.addLast(candidates[i]);
            // 因为元素不可以重复使用，这里递归传递下去的是 i + 1 而不是 i
            dfs(candidates, len, i + 1, target - candidates[i], path, res); 
            path.removeLast();

        }
    }

//自己写的
/*
这一题比39多的条件是candidates有重复元素，所以我们需要把同一层的重复元素剪枝 
首先还是要排序，然后判断两个相邻元素相等，还有就是used[i-1]是false ，也就是used[i-1]没有被使用，所以不是上下级关系，而是同层关系

看了题解后发现看相同元素是不是同一层，其实不需要用used 来保存状态，只需看当前是不是begin，不是begin就直接剪掉
*/

class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        ArrayList<Integer> path = new ArrayList<Integer>();
        boolean[] used = new boolean[candidates.length];
        backtrack(candidates,used,0,target,path,ans);

        return ans;
    }

    public void backtrack(int[] candidates,boolean[] used,int begin,int target, List<Integer> path,List<List<Integer>> ans){
        //终止条件

        if(target==0){
            ans.add(new ArrayList<Integer>(path));
            return ;
        }
        

        for(int i=begin;i<candidates.length;i++){//从begin 开始 去重
            if(i>0 && candidates[i]==candidates[i-1]&&!used[i-1]){ //是相同层的一样的元素 就剪枝 
                continue;
            }

            if(target-candidates[i]<0){
                break;
            }
            path.add(candidates[i]);
            used[i]=true;
            backtrack(candidates,used,i+1,target-candidates[i],path,ans);
            path.remove(path.size()-1);
            used[i]=false;
        }   


    }
}

自己的改过后
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        ArrayList<Integer> path = new ArrayList<Integer>();
       
        backtrack(candidates,0,target,path,ans);

        return ans;
    }

    public void backtrack(int[] candidates,int begin,int target, List<Integer> path,List<List<Integer>> ans){
        //终止条件

        if(target==0){
            ans.add(new ArrayList<Integer>(path));
            return ;
        }
        

        for(int i=begin;i<candidates.length;i++){//从begin 开始 去重
            if(i>begin && candidates[i]==candidates[i-1]){ //是相同层的一样的元素 就剪枝 
                continue;
            }

            if(target-candidates[i]<0){
                break;
            }
            path.add(candidates[i]);
            
            backtrack(candidates,i+1,target-candidates[i],path,ans);
            path.remove(path.size()-1);
            
        }   


    }
}
