/*
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

 

示例 1：

输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
 

提示：

S的长度在[1, 500]之间。
S只包含小写字母 'a' 到 'z' 。

*/

//方法一：自己的
class Solution {
    public List<Integer> partitionLabels(String S) {
        List<Integer> list = new ArrayList<Integer>();
        StringBuilder str = new StringBuilder(S);
        int l=0,r=0;

        for(int i=0;i<str.length();i++){
            String a = str.charAt(i)+"";
            int lastIndex = str.lastIndexOf(a);
            r = lastIndex>r?lastIndex:r;//右边界
            if(i==r){//走到右边界
                list.add(r-l+1);
                l = r+1;
            }
        }
        return list;

    }
}
