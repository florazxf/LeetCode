// 请实现一个函数，把字符串 `s` 中的每个空格替换成"%20"。
// **示例 1：**
// ```
// 输入：s = "We are happy."
// 输出："We%20are%20happy."
// ```
// **限制：**
// ```
// 0 <= s 的长度 <= 10000
// ```

class Solution {
    public String replaceSpace(String s) {
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < s.length(); i++) {
            
            if (s.charAt(i)==' '){
                sb.append("%20");    
            }
            else{
                sb.append(s.charAt(i));
            }
        }
        return sb.toString();
    }
}
