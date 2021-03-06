/*
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

*/

//12.22 java写的
/*
没想到用当前queue的size 来作为这一层元素的标志
*/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        if(root==null){
            return ans;
        }
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        
        
        queue.offer(root);
        while(!queue.isEmpty()){
            List<Integer> curLayer = new LinkedList<Integer>();
            int len = queue.size();
            for(int i=0;i<len;i++){
                 TreeNode currNode = queue.poll(); //出队
                 curLayer.add(currNode.val);
                 if(currNode.left!=null){
                    queue.offer(currNode.left);
                 }            
                 if(currNode.right!=null){
                    queue.offer(currNode.right);
                 }
            
            }
            ans.add(curLayer);
        }
        return ans;
    }
}


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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        
        q.push(root);
        while(!q.empty()){
            vector<int>layer;
            int len = q.size();// 
            for(int i=0;i<len;i++){//一定是写成len,不能直接写q.size()
                TreeNode* r = q.front();
                q.pop();
                layer.push_back(r->val);
                if(r->left!=NULL) q.push(r->left);
                if(r->right!=NULL) q.push(r->right);
            }
            ans.push_back(layer);

        }
        return ans;
    }

};
