/*
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

 

示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
*/

//方法一：字符串遍历 递归

//没有剪枝 
class Solution {
public:
    int translateNum(int num) {

        string s = to_string(num);
        
        for(int i=0;i<s.size()-1;i++){
            
            if(s[i]=='1'){ 
                if(s.size()==2) return translateNum(stoi(s.substr(1)))+1;
                return translateNum(stoi(s.substr(1)))+translateNum(stoi(s.substr(2)));
            }
            else if(s[i]=='2' && s[i+1]>='0' &&s[i+1]<='5'){
                if(s.size()==2) return translateNum(stoi(s.substr(1)))+1;
                return translateNum(stoi(s.substr(1)))+translateNum(stoi(s.substr(2)));
                
            }
            else{
                return translateNum(stoi(s.substr(1)));
            }
        }
        
        return 1;//只有单个字母
    }
};

//方法二 数字求余递归
class Solution {
public:
    int translateNum(int num) {

        if(num<10) return 1;
        return (num%100<10||num%100>25)?translateNum(num/10):translateNum(num/10)+translateNum(num/100);
    }
};
