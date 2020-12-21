/*
给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
示例 1：

输入：s = "bcabc"
输出："abc"
示例 2：

输入：s = "cbacdcbc"
输出："acdb"
*/
//找到最小字母序 就是把栈里比当前字母大的都出栈 并且后面还有这个栈顶元素 
//因为要去重 对于已经在栈里的证明和自己相同的字母已经被选到了 那自己就不需要入栈 
class Solution {
    public String removeDuplicateLetters(String s) {
        int[] cnt = new int[26]; //没被遍历的字母的次数
        int[] match = new int[26]; //当前元素在栈里则位1
        char[] chars = s.toCharArray();
        Stack<Character> stack = new Stack<Character>(); //用单调栈保存最后的结果
        //把每个字母出现的次数记录下来
        for (int i = 0; i < s.length(); i++) {
            int index  = s.charAt(i)-'a';
            cnt[index]++;
        }

        for(Character c : chars){
            if(match[c-'a']==0){//不在栈里 则操作
                //栈顶元素比当前元素大 且后面还有这个元素
                while(!stack.empty() && stack.peek()>c && cnt[stack.peek()-'a']>0){
                    match[stack.peek()-'a']--;
                    stack.pop();

                }
                stack.push(c);
                match[c-'a']++;
            }


            cnt[c-'a']--; //被遍历

        }

        //转成字符串
        StringBuilder sb = new StringBuilder();
        while(!stack.empty()){
            sb.append(stack.pop());
        }
        return sb.reverse().toString();

    }
}
