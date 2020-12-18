/*
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效的 IP 地址。

 

示例 1：

输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
示例 2：

输入：s = "0000"
输出：["0.0.0.0"]
示例 3：

输入：s = "1111"
输出：["1.1.1.1"]
示例 4：

输入：s = "010010"
输出：["0.10.0.10","0.100.1.0"]
示例 5：

输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

*/


//方法一：自己做出来啦！
class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> ans = new ArrayList<String>();
        List<String> path = new ArrayList<String>();
        dfs(ans, s,path,0,0);

        return ans;
    }
    public void dfs(List<String> ans, String s,List<String> path,int depth,int begin){
        //终止条件
        if(path.size()==4){

            if(begin==s.length()){
                ans.add(String.join(".",path));
            }
            return ;

        }

        for (int i = begin; i < s.length(); i++) {

            //剪枝 以0开头的2位数以上的
            if(i>begin && s.charAt(begin)=='0'){
                continue;
            }

            String s1= s.substring(begin, i+1);//当前层选的数字


            //当前数比255 大 剪枝
            if(Integer.parseInt(s1)>255){
                break;
            }
            //剩余的数字个数比 需要的最大个数还多 剪枝
            if((s.length()-i-1)>(3-path.size())*3){
                continue;
            }

            path.add(s1);
            dfs(ans,s,path,depth+1,i+1);
            path.remove(path.size()-1);

        }

    }
}
