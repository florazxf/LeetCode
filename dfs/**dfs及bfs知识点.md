# 使用dfs和bfs的情况
## 二叉树

## 图  
  遍历图的时候我们应该要想到用dfs或bfs  
例题  
[785. 判断二分图](https://github.com/florazxf/LeetCode/blob/master/dfs/785.%20%E5%88%A4%E6%96%AD%E4%BA%8C%E5%88%86%E5%9B%BE.cpp)  

1. 需要前面节点的信息 dfs函数中用a来保存 因为肯定是子节点的dfs先return 所以自然就是先保存了子节点的信息   
 dfs(..,vector<int>&a){ //加&相当于每次更新a的值都会被传回去    
    vector<int> tmp;//初始化一个空的数组，保存**当前遍历的结点**所有子结点的信息  
    dfs(..,tmp);//返回的tmp就为刚刚遍历的结点的信息  
    用tmp对a更新，由于a加了&，所以更新后就会被传回去 得到当前遍历过所有节点的信息  
 }  

例题：  
[5465. 子树中标签相同的节点数](https://github.com/florazxf/LeetCode/blob/master/dfs/5465.%20%E5%AD%90%E6%A0%91%E4%B8%AD%E6%A0%87%E7%AD%BE%E7%9B%B8%E5%90%8C%E7%9A%84%E8%8A%82%E7%82%B9%E6%95%B0.cpp)  
