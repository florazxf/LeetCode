/*

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string s="";

        if(strs.size()==0){
            return s;
        }

        if(strs.size()==1){
            return strs[0];
        }

        int i=0;
        
        while(1){

        for(int j=1;j<strs.size();j++){

            if(i==strs[j].size() ||strs[j][i]!=strs[j-1][i]){ //有一个不满足就返回
                return s;
            }

        }
        s = s+strs[0][i];//满足加到s中
        i++;

        }
        return s;


        
    }
};
