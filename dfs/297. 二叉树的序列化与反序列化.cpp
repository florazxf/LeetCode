/*
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

示例: 

你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"
提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。

*/

//前序遍历 dfs

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        string res;
        dfs_s(root,res);
        return res;
        
    }

    //前序遍历序列转化为字符串
    void dfs_s(TreeNode* root,string& res){
        if(!root){
            res+="null ";
            return ;
        }
        res+=to_string(root->val)+' ';
        dfs_s(root->left,res);
        dfs_s(root->right,res);
        
    }

        // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int u=0;
        return dfs_d(data,u); 
        
    }


    TreeNode* dfs_d(string data,int& u){//注意u要传&
        if(u==data.size()){
            return NULL;
        }
        if(data[u]=='n'){
            u=u+5;
            return NULL;
        }
        int val = 0; //root的值
        int sign=1;//负数的负号
        if(data[u]=='-'){
            sign=-1;
            u++;}
        string s;
        while(data[u]!=' '){ //得到val的值
            s = s+data[u];
            u++;
        }
        val = stoi(s);
        val = val*sign;
        u=u+1;
        auto root = new TreeNode(val);
        root->left = dfs_d(data,u);
        root->right = dfs_d(data,u);
        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
