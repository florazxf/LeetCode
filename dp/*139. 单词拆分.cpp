/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：


	拆分时可以重复使用字典中的单词。
	你可以假设字典中没有重复的单词。


示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。


示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。


示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

*/


//自己没做出来 看的题解

/*
主要是要想到用dp[i]表示s的前i个是否能被wordDict的单词拆分，如果能拆分就看第i个起的后半段字符串能否被拆，能拆的部分就设为true
到最后如果dp[n]为true，则就是s的前n个字符能被拆分
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);//s的前i个字符串是否能被拆分
        dp[0] = true;

        for(int i=0;i<n;i++){
            if(!dp[i]) //前i个i字符串不能被拆分
                continue;
            
            for(auto& word:wordDict){
                //前i个能被分了，看后i个能被wordDict的单词分吗
                if(word.size()+i<=n && s.substr(i,word.size())==word){
                    dp[i+word.size()]=true;
                }
            }
        }

        return dp[n];
        
    }
};
