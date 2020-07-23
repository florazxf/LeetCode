/*

给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11

*/

//方法二： 前缀和 单次遍历
/*
前缀和：达到当前元素的路径上，所有元素的和
本文要求任意两个结点之间的元素和为sum，那么我们可以转换成， 如果curSum-sum=preSum，那么也就是找到了从节点A到结点B的路径和是sum， 这个curSum就是结点B的前缀和，preSum就是结点A的前缀和  
因此我们只用遍历的时候把每个节点的前缀和存在哈希表中， 在哈希表中找是否存在curSum-sum 即可。
因为不同路径的前缀和可能一样，所以我们哈新表中要存的是前缀和出现的次数unordered_map<int,int>prefixSumCount;//用哈希表存前缀和及出现次数 key:前缀和 value：出现次数
最后记得左右子树遍历结束，重回到本次后把本层的前缀和从哈希表中减去，避免回溯后影响上一层 因为本层的并不属于上一层的前缀和
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //4:17
class Solution {
public:
    int ans=0;//最后结果
    unordered_map<int,int>prefixSumCount;//用哈希表存前缀和及出现次数 key:前缀和 value：出现次数
    //curSum = prefixSum+sum; 
    int pathSum(TreeNode* root, int sum) {
        prefixSumCount[0] = 1;//前缀和为0的一条路径
        dfs(root,0,sum,prefixSumCount);
        return ans;
    }
    void dfs(TreeNode* root, int curSum, int sum, unordered_map<int,int>& prefixSumCount){
        //1. 递归终止条件
        if(root==NULL){
            return;
        }
        //2. 本层要做的事： 对于当前结点来说，找有没有curSum-sum 存在在哈希表中
        curSum+=root->val;
        if(prefixSumCount.find(curSum-sum)!=prefixSumCount.end()){//存在
            ans+=prefixSumCount[curSum-sum];//可能前面有好几条路径的和的前缀和都是curSum-sum
        }
        prefixSumCount[curSum]++;//更新当前结点的前缀和
        //3. 进入下一层
        dfs(root->left,curSum,sum,prefixSumCount);
        dfs(root->right,curSum,sum,prefixSumCount);
        //4. 回到本层，恢复状态
        prefixSumCount[curSum]--;
    
    }
};

//方法一：双重dfs

/*
因为题目说的是不是从根节点开始，那我们可以把每个节点当成根节点进行dfs，得到以该结点为根节点的满足条件的值
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //4:17
class Solution {
public:
    int ans=0;
    int pathSum(TreeNode* root, int sum) {
        
        if(root==NULL){
            return ans;
        }
        dfs(root,sum); //以每个节点作为起始结点 DFS寻找满足条件的路径和

        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return ans;
    }
    void dfs(TreeNode* root, int sum){
        if(root==NULL){
            return;
        }
        sum-=root->val;
        if(sum==0){
            ans++;
        }
        dfs(root->left,sum);
        dfs(root->right,sum);
    
    }
};


