/*
你有两个字符串，即pattern和value。 pattern字符串由字母"a"和"b"组成，用于描述字符串中的模式。例如，字符串"catcatgocatgo"匹配模式"aabab"（其中"cat"是"a"，"go"是"b"），该字符串也匹配像"a"、"ab"和"b"这样的模式。但需注意"a"和"b"不能同时表示相同的字符串。编写一个方法判断value字符串是否匹配pattern字符串。
示例 1：
输入： pattern = "abba", value = "dogcatcatdog"
输出： true

示例 2：
输入： pattern = "abba", value = "dogcatcatfish"
输出： false

示例 3：
输入： pattern = "aaaa", value = "dogcatcatdog"
输出： false

示例 4：
输入： pattern = "abba", value = "dogdogdogdog"
输出： true
解释： "a"="dogdog",b=""，反之也符合规则

提示：

0 <= len(pattern) <= 1000
0 <= len(value) <= 1000
你可以假设pattern只包含字母"a"和"b"，value仅包含小写字母。

*/

//自己做了2个多小时终于做出来了
/*
主要浪费时间的地方就是自己好多情况没考虑 就是得到a和b分别是什么的时候，先要考虑pattern是a打头还是b打头，而且要考虑打头的数量，这样才能知道后面的字符串从哪里开始

*/

class Solution {
public:
    bool patternMatching(string pattern, string value) {

        int n = value.size();
        if(n==0){
            if(pattern.size()<=1)
                return true;
            else 
                return false;
        }
        if(pattern.size()==0){
            return false;
        }


        //a和b的长度
        int lena;
        int lenb;
        //a和b的个数
        int numa=0;
        int numb=0;
        for(char ch:pattern){
            if(ch=='a'){
                numa++;
            }
            else{
                numb++;
            }
        }
        

        lena = 0;
        int maxa = numa==0?0:n/numa;
        
        
        string a,b;
        
        while(lena<=maxa){ //a和b所有可能的个数

            
            lenb = numb==0?0:(n-lena*numa)/numb;
            //除不尽的直接过滤掉
            if(numa!=0&& numb!=0 && ((n-lenb*numb)%numa!=0 || (n-lena*numa)%numb!=0)){
                lena++;
                continue;
            }
            int index = 0;
            int cnt=0;
            if(pattern[0]=='a'){//patter里是a打头
                a = value.substr(0,lena); //从第0位开始长度为lena的字符串
                while(pattern[index]=='a'){
                    cnt++;//计算开头a的数量，这样才能知道b的起始位置
                    index++;
                }
                b = value.substr(lena*cnt,lenb);
            }
            else{//pattern是b打头（刚开始没有考虑这种情况）
                b = value.substr(0,lenb); //从第0位开始长度为lena的字符串
                while(pattern[index]=='b'){
                    cnt++;
                    index++;
                }
                a = value.substr(lenb*cnt,lena);
            }

            //根据pattern把a和b组成res，看和value是否相等
            string res="";
            for(char ch:pattern){
                if(ch=='a'){
                    res+=a;
                }
                else{
                    res+=b;
                }
            }
            if(res==value){
                return true;
            }
            lena++;
        }
    
        return false;

    }
};
