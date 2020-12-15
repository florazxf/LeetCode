/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

*/

//2020/12/15  java

/*
把所有单词排序后放map中
主要学到 String 如何排序
还有Map.getOrDefault 当Map集合中有这个key时，就使用这个key值；如果没有就使用默认值defaultValue
*/
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<String, List<String>>();
        for (String str : strs) {
            char[] array = str.toCharArray();
            Arrays.sort(array);
            String key = new String(array);
            //Map.getOrDefault 当Map集合中有这个key时，就使用这个key值；如果没有就使用默认值defaultValue
            List<String> list = map.getOrDefault(key, new ArrayList<String>());
            list.add(str);
            map.put(key, list);
        }
        return new ArrayList<List<String>>(map.values());
    }
}


//之前c++写的

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> res;
        vector<string> a;
        a.push_back(strs[0]);
        res.push_back(a);
        int flag=0;
        string cnt;
        string c;
        string b;
        for(int i=1;i<strs.size();i++){
            c = strs[i];
            
            for(int j=0;j<res.size();j++){

                flag=0;
                b = res[j][0];
                if(strs[i].size()==res[j][0].size()){ //res[j]是每一个向量
                    cnt="";

                    for(int z=0;z<strs[i].size();z++){

                        int pos = b.find(c[z]);
                        
                        if(pos==-1){ //不匹配
                            flag=1;
                            break;
                        }
                        else{ 
                            b.erase(pos,1); //匹配就删掉
                        }

                    }
                }
                else{
                    flag=1;
                }

                if(flag==0){ //每个字母都和res[j]匹配
                    res[j].push_back(strs[i]);
                    break;
            }

            }

                if(flag==1){
                    a.clear();
                    a.push_back(strs[i]);
                    res.push_back(a);

                }

        }
        return res;
        
    }
};
