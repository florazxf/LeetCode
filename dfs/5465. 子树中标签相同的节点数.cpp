/*
给你一棵树（即，一个连通的无环无向图），这棵树由编号从 0  到 n - 1 的 n 个节点组成，且恰好有 n - 1 条 edges 。树的根节点为节点 0 ，树上的每一个节点都有一个标签，也就是字符串 labels 中的一个小写字符（编号为 i 的 节点的标签就是 labels[i] ）
边数组 edges 以 edges[i] = [ai, bi] 的形式给出，该格式表示节点 ai 和 bi 之间存在一条边。
返回一个大小为 n 的数组，其中 ans[i] 表示第 i 个节点的子树中与节点 i 标签相同的节点数。
树 T 中的子树是由 T 中的某个节点及其所有后代节点组成的树。
*/

//方法一：题解
/*
自己写的虽然可以得到正确答案，但是有几个测试用例超时，看了题解主要有两部分：
①应该先遍历edges，得到每个节点的所有子节点 用二维数组tree保存 tree[i]表示i的所有节点。要注意的是 这是无向图x是y的子节点，y也是x的子节点
②由于要判断子节点和当前结点的label是否相同，我自己是用pres数组存之前的结点。但是题解就用了a数组来作为26个字母出现的次数，时间就快很多
应该学到的是这种需要保存前面节点信息，可以每次都传dfs(vector<int>&a) 因为传的是引用，a就保存了访问过的结点的值
*/
class Solution {
    vector<vector<int>> tree;//tree[i]表示i的所有子节点
    vector<int>ans;
    vector<bool>vis;//这个节点是否被访问过
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        tree.resize(labels.size());
        ans.resize(labels.size());
        vis.resize(labels.size(),false);

        //得到每个节点的子节点
        for(auto& e : edges){
            tree[e[0]].emplace_back(e[1]);
            tree[e[1]].emplace_back(e[0]);//因为是无向图 e[0]也是e[1]的子节点
        }
        vector<int>tmp(26);
        dfs(0,tmp,labels);
        return ans;
    }
    void dfs(int x,vector<int>& a,string& labels){ //labels必须加引用 否则还是会超时
        //cout<<x;
        if(vis[x]){
            return;
        }
        vis[x]=true;
        vector<int> tmp(26);//tmp存的是x所有子节点的label的信息
        for(auto& y:tree[x]){
            dfs(y,tmp,labels); //return后的tmp已经更新了y的字节点的label 因为a是&传的是地址
        }
        ans[x] = ++tmp[labels[x]-'a'];//x本身的label+1 然后再把tmp中x的label出现的次数加上 
        for (int i = 0; i < 26; ++i){//a是到目前为止访问的所有节点的label的次数
            a[i] += tmp[i];
        }
    }
};
