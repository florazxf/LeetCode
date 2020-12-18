/*
给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

 

示例 1：

输入：n = 3, k = 3
输出："213"
示例 2：

输入：n = 4, k = 9
输出："2314"
示例 3：

输入：n = 3, k = 1
输出："123"
 

提示：

1 <= n <= 9
1 <= k <= n!

*/

//weiwei
https://leetcode-cn.com/problems/permutation-sequence/solution/hui-su-jian-zhi-python-dai-ma-java-dai-ma-by-liwei/


//方法一：自己用回溯 把k之前的结果都得到
class Solution {
    int cnt=0;
    String ans;
    public String getPermutation(int n, int k) {
         StringBuilder sb = new StringBuilder();
         //List<String> ans = new ArrayList<String>();
         boolean[] used = new boolean[n];
         dfs(used,sb,n,k,0);
         
         return ans;
    }

    public void dfs(boolean[] used,StringBuilder sb,int n,int k,int depth){
        if(cnt==k){
                return ;
        }
        if(depth==n){
            cnt++;
            if(cnt==k){
                ans = sb.toString();
                return ;
            }
            
        }

        for(int i = 0;i<n;i++){
            if(used[i]){
                continue;
            }
            used[i] = true;
            sb.append(i+1);
            dfs(used,sb,n,k,depth+1);
            used[i] = false;
            sb.deleteCharAt(sb.length()-1);
        }

      

    }
}
