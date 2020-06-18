/*
我们从二叉树的根节点 root 开始进行深度优先搜索。

在遍历中的每个节点处，我们输出 D 条短划线（其中 D 是该节点的深度），然后输出该节点的值。（如果节点的深度为 D，则其直接子节点的深度为 D + 1。根节点的深度为 0）。

如果节点只有一个子节点，那么保证该子节点为左子节点。

给出遍历输出 S，还原树并返回其根节点 root。

*/

//方法一：用栈维护从根节点到当前节点上所有的节点
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        
    int pos=0;
    
    stack<TreeNode*> path;
    while(pos<S.size()){
        int level = 0;
        while(S[pos]=='-'){
            pos++;
            level++; //当前节点的深度信息
        }
        string val="";
        while(pos<S.size()&&S[pos]!='-'){
            val+=S[pos];
            pos++;
        }


        TreeNode* node = new TreeNode(stoi(val));

        if(path.size()==level){//当前节点是上一个节点的左子节点
            if(!path.empty()){
                path.top()->left = node;
            }

        }
        else{//当前节点是根节点到上一节点（不包括上一节点）的右子节点
            while(level!=path.size()){
                path.pop();
            }
            path.top()->right = node;
        }
        path.push(node);
    }
    while(path.size()>1){
        path.pop();
    }

    return path.top();
    }
};
//方法二：自己的方法
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        
        string val="";
        int i=0;
        while(S[i]!='-'){
                val=val+S[i];
                i++;
                if(i==S.size()){break;}
        }


        auto root = new TreeNode(stoi(val)); //根节点的值
        TreeNode* r = root;
        TreeNode* prer = root;
        int precnt = 0;

        for(i;i<S.size();i++){
            int cnt=0;
            while(S[i]=='-'){
                cnt++;
                i++;
            }
            //得到当前节点的值
            string val="";
            while(S[i]!='-'){
                val=val+S[i];
                i++;
                if(i==S.size()){break;}
            }
            i--;


            if(cnt>precnt){//左节点
                precnt = cnt; //前一个-的个数
                r->left = new TreeNode(stoi(val));
                prer = r;
                r = r->left;
                //cout<<i;
            }
            else if(cnt==precnt){ //和前一个-d相等说明父结点一样
                prer->right = new TreeNode(stoi(val));
                r = prer->right;
            }
            else{
                r = root;
                precnt = cnt; //前一个-的个数
                while(cnt>1){
                    if(r->right){r = r->right;}
                    else{
                        r = r->left;
                    }
                    
                    cnt--;
                }
                r->right = new TreeNode(stoi(val));
                r = r->right;
            }
            
           
        }

        return root;


    }
};
