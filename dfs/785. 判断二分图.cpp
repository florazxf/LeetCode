/*
给定一个无向图graph，当这个图为二分图时返回true。

如果我们能将一个图的节点集合分割成两个独立的子集A和B，并使图中的每一条边的两个节点一个来自A集合，一个来自B集合，我们就将这个图称为二分图。

graph将会以邻接表方式给出，graph[i]表示图中与节点i相连的所有节点。每个节点都是一个在0到graph.length-1之间的整数。这图中没有自环和平行边： graph[i] 中不存在i，并且graph[i]中没有重复的值。


示例 1:
输入: [[1,3], [0,2], [1,3], [0,2]]
输出: true
解释: 
无向图如下:
0----1
|    |
|    |
3----2
我们可以将节点分成两组: {0, 2} 和 {1, 3}。

示例 2:
输入: [[1,2,3], [0,2], [0,1,3], [0,2]]
输出: false
解释: 
无向图如下:
0----1
| \  |
|  \ |
3----2
我们不能将节点分割成两个独立的子集。

*/


/*
如果给定的无向图连通，那么我们就可以任选一个节点开始，给它染成红色。随后我们对整个图进行遍历，将该节点直接相连的所有节点染成绿色，表示这些节点不能与起始节点属于同一个集合。
我们再将这些绿色节点直接相连的所有节点染成红色，以此类推，直到无向图中的每个节点均被染色。

遍历图上的结点我们就应该想到用dfs或bfs遍历
*/

//方法一：dfs 给相邻节点染成不同的颜色


class Solution {
public:
    vector<int>color;
    bool valid;
    void dfs(int node,int c,vector<vector<int>>& graph){
        color[node] = c;//给当前节点染成
        int cNei = (c==1?2:1);//给相邻节点染成不同的颜色
        for(int neighbor: graph[node]){//把和node相邻的节点染成不同的颜色
            if(color[neighbor]==0){//未染色
                dfs(neighbor,cNei,graph);
                if(!valid){
                    return;
                }
            }
            else if(color[neighbor]!=cNei){//如果相邻节点颜色和他相同则不符合要求
                valid = false;
                return;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        valid = true;
        color.assign(graph.size(),0);//每个节点都初始化为未染色

        for(int i=0;i<graph.size()&&valid;i++){
            if(color[i]==0){//当前结点没染色就把他和他相邻的节点分别染成不同的颜色
                dfs(i,1,graph);
            }
        }
        return valid;
    }
};

//方法二: bfs 队列
