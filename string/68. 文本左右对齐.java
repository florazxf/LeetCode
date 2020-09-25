/*
给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。
要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
文本的最后一行应为左对齐，且单词之间不插入额外的空格。

说明:
	单词是指由非空格字符组成的字符序列。
	每个单词的长度大于 0，小于等于 maxWidth。
	输入单词数组 words 至少包含一个单词。


示例:
输入:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
输出:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]


示例 2:
输入:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
输出:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
     因为最后一行应为左对齐，而不是左右两端对齐。       
     第二行同样为左对齐，这是因为这行只包含一个单词。


示例 3:
输入:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
输出:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
*/


//方法一：自己做的
/*
空格个数的计算方式：向上取整的，然后加空格的时候还要再调整。虽然最后a了，但是这样不科学。
*/
class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        int n = words.length;
        List<String> ans = new ArrayList();
        for(int i=0;i<n;i++){
            //满足小于maxWidth的最多数量的单词
            int length = 0;//一行单词字符的长度
            int cnt = 0;//一行单词的个数
            int j=i;
            while(j<n && length<maxWidth){
                length=length+words[j].length()+1;
                cnt++;
                if(length>=maxWidth){
                    break;
                }
                j++;
                
            }
            length--;
            if(length>maxWidth){
                length-=words[j--].length();
                length--;
                cnt--;
            }
            StringBuilder ans_h = new StringBuilder();
            int cnt_kg;
            if(cnt>1){
                cnt_kg =(int)Math.ceil((float)(maxWidth-length)/(cnt-1));
            }
            else{
                cnt_kg = maxWidth-length;
            }
            System.out.println(cnt_kg);
            int real_cnt_kg=0; //已经添加的空格数
            if(j==n){//最后一行左对齐
                while(cnt>0){
                    ans_h.append(words[i]);
                    if(cnt>1){
                        ans_h.append(' '); //单词后面的空格
                    }
                    else{
                        while(length<maxWidth){
                            ans_h.append(' ');
                            length++;
                        }
                    }
                    i++;
                    cnt--;
                }
            }
            else{
                while(cnt>0){//本行单词个数
                    ans_h.append(words[i]);
                    if(cnt>1){
                        ans_h.append(' '); //单词后面的空格
                    }
                    int tmp_cnt_kg = cnt_kg;
                    while(real_cnt_kg<(maxWidth-length)&&tmp_cnt_kg>0){
                        ans_h.append(' ');
                        real_cnt_kg++;
                        tmp_cnt_kg--;
                    }
                    
                    i++;
                    cnt--;
                    cnt_kg =(int)Math.ceil((float)(maxWidth-length-real_cnt_kg)/(cnt-1));
                }
            }


            ans.add(ans_h.toString());
            i--;

        }
        return ans;
    }
}

//方法二：
/*
修改的部分：
额外空格的平均值spaceAvg cnt_kg = (maxWidth-length)/(cnt-1); //平均空格数量
cnt_mod = (maxWidth-length)%(cnt-1); //剩下的空格数量
*/

class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        int n = words.length;
        List<String> ans = new ArrayList();
        for(int i=0;i<n;i++){
            //满足小于maxWidth的最多数量的单词
            int length = 0;//一行单词字符的长度
            int cnt = 0;//一行单词的个数
            int j=i;
            while(j<n && length<maxWidth){
                length=length+words[j].length()+1;
                cnt++;
                if(length>=maxWidth){
                    break;
                }
                j++;
                
            }
            length--;
            if(length>maxWidth){
                length-=words[j--].length();
                length--;
                cnt--;
            }
            StringBuilder ans_h = new StringBuilder();
            int cnt_kg;
            int cnt_mod = 0;
            if(cnt>1){
                //cnt_kg =(int)Math.ceil((float)(maxWidth-length)/(cnt-1));
                cnt_kg = (maxWidth-length)/(cnt-1); //平均空格数量
                cnt_mod = (maxWidth-length)%(cnt-1); //剩下的空格数量
            }
            else{
                cnt_kg = maxWidth-length;
            }
             
            int real_cnt_kg=0; //已经添加的空格数
            if(j==n){//最后一行左对齐
                while(cnt>0){
                    ans_h.append(words[i]);
                    if(cnt>1){
                        ans_h.append(' '); //单词后面的空格
                    }
                    else{
                        while(length<maxWidth){
                            ans_h.append(' ');
                            length++;
                        }
                    }
                    i++;
                    cnt--;
                }
            }
            else{
                while(cnt>0){//本行单词个数
                    ans_h.append(words[i]);
                    if(cnt==1){ //最后一个单词
                        int k = maxWidth-ans_h.length();
                        if(k>0){
                            ans_h.append(" ".repeat(k));
                        }
                        i++;
                        break;
                    }
                    
                    ans_h.append(' '); //单词后面的空格
                    ans_h.append(" ".repeat(cnt_kg)); //平均每个单词后跟的空格数
                    
                    
                    if(cnt_mod>0){
                        //System.out.println("sss");
                        ans_h.append(' ');
                        cnt_mod--;
                    }
                    i++;
                    cnt--;
                   
                }

            }

            System.out.println(ans_h.length());
            ans.add(ans_h.toString());
            i--;

        }
        return ans;



    }
}
