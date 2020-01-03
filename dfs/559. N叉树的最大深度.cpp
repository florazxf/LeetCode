/*
给定一个 N 叉树，找到其最大深度。

最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
//方法一：自己方法

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root){
            return 0;
        }

        if(root->children.size()==0){//叶节点
            return 1;
        }
        int md=0;
        for(int i=0;i<root->children.size();i++){//访问当前结点所有孩子结点
            int depth = maxDepth(root->children[i])+1;
            if(depth>md){ //得到当前结点孩子结点中的最大深度
                md = depth;
            }
        }
        
        return md;
    }
};

//方法二：题解 和方法一区别不大
class Solution {
public:
    int maxDepth(Node* root) {
        if(!root){
            return 0;
        }
        int depth=0;
        for(int i=0;i<root->children.size();i++){//访问当前结点所有孩子结点
            depth = max(depth,maxDepth(root->children[i]));//得到当前结点孩子结点中的最大深度
        }
        
        return depth+1;
    }
};
