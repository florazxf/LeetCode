/*
给定两个字符串 s 和 t，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。

 

示例 1：

输入：s = "abcd", t = "abcde"
输出："e"
解释：'e' 是那个被添加的字母。
示例 2：

输入：s = "", t = "y"
输出："y"
示例 3：

输入：s = "a", t = "aa"
输出："a"
示例 4：

输入：s = "ae", t = "aea"
输出："a"
 

提示：

0 <= s.length <= 1000
t.length == s.length + 1
s 和 t 只包含小写字母
*/
//方法四：求和
//因为只差一个字母 所以t所有字母求和后减去s所有字母求和的值就是 要求的

class Solution {
    public char findTheDifference(String s, String t) {
        int as = 0;
        int at = 0;
        for (int i = 0; i < s.length(); ++i) {
            as += s.charAt(i);
        }
        for (int i = 0; i < t.length(); ++i) {
            at+= t.charAt(i);
        }
        return (char) (at-as);
    }
}

//方法三：位运算
//把s和t看成一个串 那就是找出现奇数次的字母 出现偶数次的字母异或后就是0  0异或出现奇数次的字母得到的还是那个数
//类似于136题

class Solution {
    public char findTheDifference(String s, String t) {
        int ret = 0;
        for (int i = 0; i < s.length(); ++i) {
            ret ^= s.charAt(i);
        }
        for (int i = 0; i < t.length(); ++i) {
            ret ^= t.charAt(i);
        }
        return (char) ret;
    }
}

//方法二： 哈希表 
//因为只有26个字母 所以用int[]cnt 存每个字母出现的次数

class Solution {
    public char findTheDifference(String s, String t) {
        int [] cnt  = new int[26];
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            cnt[c-'a']++;
        }

        for(int i = 0;i<t.length();i++){
            char c1 = t.charAt(i);
            cnt[c1-'a']--;
            if(cnt[c1-'a']<0){
                return c1;
            }
        }

        return t.charAt(0);
    }
}
//方法一：

//自己写的，把两个排序 然后再比较
class Solution {
    public char findTheDifference(String s, String t) {
        char[] c1= s.toCharArray();
        char[] c2 = t.toCharArray();
        Arrays.sort(c1);
        Arrays.sort(c2);
        int index = 0;
        while(index<c1.length){
            if(c1[index]!=c2[index]){
                return c2[index];
            }
            index++;
        }
        return c2[index];
    }
}
