/*
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

 

示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
//方法一：自己做的
/*
因为有重复的数字，通过画出递归树发现 如果这一层已经添加过这个数，那就没必要再添加一次了，所以在每一层放了一个map来存已经添加过的数
*/
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer>path = new ArrayList<>();
        boolean[] used = new boolean[n];

        dfs(ans,path,0,used,nums);
        return ans;
    }

    public void dfs(List<List<Integer>> ans,List<Integer> path,int depth,boolean[] used,int[] nums){
        //终止条件
        if(depth==nums.length){
            ans.add(new ArrayList<Integer>(path));
            return ;
        }
        Map<Integer,Integer> map = new HashMap<>();//存本层的元素 
        for(int i=0;i<nums.length;i++){
            if(!map.containsKey(nums[i]) && !used[i]){
                map.put(nums[i],1);
                used[i] = true;
                path.add(nums[i]);
                dfs(ans,path,depth+1,used,nums);
                used[i] = false;
                path.remove(path.size()-1);
            }
        }


    }
}

//方法二：
/*
因为考虑重复元素， 所以就排序看相邻元素相等不相等即可，并且前一个元素要没被使用过（这样才是同一层，如果前一个元素被用过那就是上下级的关系）
方法二通过排序 看相邻元素是否重复； 剪枝的条件：i>0 && nums[i]==nums[i-1] && !used[i-1]  

*/
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer>path = new ArrayList<>();
        boolean[] used = new boolean[n];
        Arrays.sort(nums);
        dfs(ans,path,0,used,nums);
        return ans;
    }

    public void dfs(List<List<Integer>> ans,List<Integer> path,int depth,boolean[] used,int[] nums){
        //终止条件
        if(depth==nums.length){
            ans.add(new ArrayList<Integer>(path));
            return ;
        }
        //Map<Integer,Integer> map = new HashMap<>();//存本层的元素 
        for(int i=0;i<nums.length;i++){
            if(used[i]){
                continue;
            }

            //当前元素和前一个元素相同 且前一个元素没有被用过
            if(i>0 && nums[i]==nums[i-1] && !used[i-1]){
                continue;
            }

            used[i] = true;
            path.add(nums[i]);
            dfs(ans,path,depth+1,used,nums);
            used[i] = false;
            path.remove(path.size()-1);
            
        }


    }
}
