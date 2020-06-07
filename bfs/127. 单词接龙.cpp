/*
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: 0

解释: endWord "cog" 不在字典中，所以无法进行转换。

*/

//方法一：
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {



        
        int n = wordList.size();
        vector<int> usedword(n); //此单词已经进过队列
        
        int front=0;
        int rear=0;
        string q[5000];
        
        
        int ans=0;

        //判断endWord是否在wordList中

        int i=0;
        for(int i=0;i<n;i++){
            if(endWord==wordList[i]){ //endWord在wordList中
                break;
            }
        }
        if(i==n){return 0;}


        //广度优先搜索
        q[rear++] = beginWord;
        ans+=1;
        while(front!=rear){ //队列不为空

            
            int level = rear-front; //本层队列的元素个数
        
            for(int i=0;i<level;i++){//遍历本层队列元素

                string x = q[front++];//取队首元素
                if(x==endWord){ //找到 返回
                    return ans;
                }
                
                //将wordList中和队首元素差一个字母的都找到 放入队列
                for(int j=0;j<n;j++){
                    int cnt=0;
                    for(int z=0;z<x.size();z++){ //找到和x只差一个字母的单词
                        if(cnt==2) break;
                        if(x[z]!=wordList[j][z]){
                            cnt++;
                        }
                    }
                    

                    if(cnt<2 && usedword[j]==0){

                        usedword[j] = 1;
                        q[rear++] = wordList[j];
                        
                    }
                }

            }
            ans++;
        
        }
        return 0;
    }
};
