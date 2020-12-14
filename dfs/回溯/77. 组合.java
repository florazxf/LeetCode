/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/

//方法一：自己的方法
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer> path = new ArrayList<Integer>();
        dfs(ans,path,0,0,k,n);
        return ans;
    }


    public void dfs(List<List<Integer>> ans,List<Integer> path,int depth,int j,int k,int n){
        //终止条件
        if(depth==k){
            ans.add(new ArrayList<Integer>(path));
            return ;
        }

        for(int i=j+1;i<=n;i++){
            path.add(i);
            dfs(ans,path,depth+1,i,k,n);
            path.remove(path.size()-1);
        }


    }
}

//方法二： 加剪枝

/*
当前数后面剩下的数的个数 不够k个了 那就不需要再往后遍历了
*/

class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        List<Integer> path = new ArrayList<Integer>();
        dfs(ans,path,0,0,k,n);
        return ans;
    }


    public void dfs(List<List<Integer>> ans,List<Integer> path,int depth,int j,int k,int n){
        //终止条件
        if(depth==k){
            ans.add(new ArrayList<Integer>(path));
            return ;
        }

        for(int i=j+1;i<=n;i++){
            if(n-i<k-1-path.size()){ // 剪枝： 当前数剩下的数 满足不了需要的k的个数
                return ;
            }
            path.add(i);
            dfs(ans,path,depth+1,i,k,n);
            path.remove(path.size()-1);
        }


    }
}

/*
可以直接写成
 for (int i = index; i <= n - (k - path.size()) + 1; i++) 
*/
