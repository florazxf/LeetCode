/*
给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意:

num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。
示例 1 :

输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
示例 2 :

输入: num = "10200", k = 1
输出: "200"
解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
示例 3 :

输入: num = "10", k = 2
输出: "0"
解释: 从原数字移除所有的数字，剩余为空就是0。

*/

/*
对于两个相同长度的数字序列，最左边不同的数字决定了这两个数字的大小.我们可以知道，若要使得剩下的数字最小，需要保证靠前的数字尽可能小

因此，对于每个数字，如果该数字小于栈顶元素，我们就不断地弹出栈顶元素
*/
//用单调栈
class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Character> stack = new Stack<Character>();
        char[] s = num.toCharArray();

        for (Character c : s) {
            //栈顶元素比当前元素大 且k是大于0的 则出栈
            while (!stack.empty() && stack.peek() > c && k > 0) {
                stack.pop();
                k--;
            }
            //栈为空，且当前位是0，则不需要入栈
            if(stack.empty() && c=='0'){
                continue;
            }
            stack.push(c);

        }

        //k还是大于0的 那就把后k位出栈
        while(!stack.empty() && k>0){
            stack.pop();
            k--;
        }

        //最后栈为空 返回0
        if(stack.empty()){
            return "0";
        }

        //反转
        StringBuilder sb = new StringBuilder();
        while(!stack.empty()){
            sb.append(stack.pop());
        }
        return sb.reverse().toString();

    }
}


//用双端队列
class Solution {
    public String removeKdigits(String num, int k) {
        Deque<Character> deque = new LinkedList<Character>();
        int length = num.length();
        for (int i = 0; i < length; ++i) {
            char digit = num.charAt(i);
            while (!deque.isEmpty() && k > 0 && deque.peekLast() > digit) {
                deque.pollLast();
                k--;
            }
            deque.offerLast(digit);
        }
        
        for (int i = 0; i < k; ++i) {
            deque.pollLast();
        }
        
        StringBuilder ret = new StringBuilder();
        boolean leadingZero = true;
        while (!deque.isEmpty()) {
            char digit = deque.pollFirst();
            if (leadingZero && digit == '0') {
                continue;
            }
            leadingZero = false;
            ret.append(digit);
        }
        return ret.length() == 0 ? "0" : ret.toString();
    }
}

