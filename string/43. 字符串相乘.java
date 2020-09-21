/**
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"

示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"

说明：


	num1 和 num2 的长度小于110。
	num1 和 num2 只包含数字 0-9。
	num1 和 num2 均不以零开头，除非是数字 0 本身。
	不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

*/

//方法一：自己做的效率很低
/**
就是题解的做加法
按照竖式的那样做

时间复杂度O(mn+n^2)
其中 m 和 n 分别是 num1 和 num2的长度。需要从右往左遍历 num2，对于 num2的每一位，都需要和 num1 的每一位计算乘积，因此计算乘积的总次数是 mn。
字符串相加操作共有 n 次，相加的字符串长度最长为 m+n，因此字符串相加的时间复杂度是 O(mn+n2)。总时间复杂度是 O(mn+n2)

空间复杂度O(m+n)
空间复杂度取决于存储中间状态的字符串，由于乘积的最大长度为 
m+n，因此存储中间状态的字符串的长度不会超过m+n
*/
class Solution {

    public String multiply(String num1, String num2) {
        if(num1.equals("0")||num2.equals("0")){
            return "0";
        }
        String ans1 = "";
        String ans2 = "";
        int cnt=0;//加的时候后面补几个0
        int c = 0;
        //num2的长度小
        if(num2.length()>num1.length()){
            String t = num1;
            num1 = num2;
            num2 = t;
        }
    
        for(int i = num2.length()-1;i>=0;i--){
            for(int j = num1.length()-1;j>=0;j--){
                int d1 = num2.charAt(i)-'0';
                int d2 = num1.charAt(j)-'0';
                ans1 = ans1+(d1*d2+c)%10;
                c = (d1*d2+c)/10;
            }
            
            if(c!=0){
                ans1+=c;
            }
            ans1 = new StringBuffer(ans1).reverse().toString();//倒过来
            int tmp=cnt;
            while(tmp>0){
                ans1+=0;//和ans2对齐
                tmp--;
            }
            ans2 = add(ans1,ans2);
            ans1 = "";
            c=0;
            cnt++;
        }
        return ans2;

    }
    public String add(String num1,String num2){
        int i=num1.length()-1;
        int j=num2.length()-1;
        int c= 0;
        String ans = "";
        while(i>=0 || j>=0){
            int d1 = i>=0?(num1.charAt(i)-'0'):0;
            int d2 = j>=0?(num2.charAt(j)-'0'):0;
            ans = ans+(d1+d2+c)%10;
            c = (d1+d2+c)/10;
            i--;
            j--;
        }
        if(c!=0){
            ans+=c;
        }

        return new StringBuffer(ans).reverse().toString();

    }

}

//方法二：做乘法
/**
用数组代替字符串存储相乘的结果
算法要想变得简便就是需要将高级的算法不断地转化为低级的过程，由两个字符串相乘->一个字符串与一个字符相乘->一个字符与一个字符相乘，然后找出相乘的结果在结果字符串中添加的位置
时间复杂度： O(mn)
空间复杂度：O(m+n)
*/
class Solution {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }
        
        int m = num1.length(), n = num2.length();
        int[] ansArr = new int[m+n];
        //把乘的结果放在数组中保存起来
        for (int i = m - 1; i >= 0; i--){
            int x = num1.charAt(i)-'0';
            for (int j = n - 1; j >=0; j--){
                int y = num2.charAt(j)-'0';
                ansArr[i+j+1] += x*y;
            }
        }
        //处理进位
        for(int i=m+n-1;i>0;i--){
            ansArr[i-1]+=ansArr[i]/10; //加上后一个的进位
            ansArr[i] = ansArr[i]%10;
        }
        int index= ansArr[0]==0?1:0;
        StringBuffer ans = new StringBuffer();
        while(index<m+n){
            ans.append(ansArr[index]);
            index++;
        }
        return ans.toString();
    }

}

