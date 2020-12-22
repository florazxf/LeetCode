/*
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]
*/
// 官方 双端队列
//用双端队列 代替 list 存当前层的元素
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        if(root==null){
            return ans;
        }
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        boolean fromR = false;
        queue.offer(root);
        while(!queue.isEmpty()){
            int len = queue.size();
            Deque<Integer> curLayer = new LinkedList<Integer>();
            for(int i=0;i<len;i++){
                TreeNode curNode = queue.poll(); //得到队首元素并出队
                //用双端队列存 当前层的结果
                if(fromR){ //从右往左 则从头插
                    curLayer.offerFirst(curNode.val);
                }
                else{ //从左往右 则从尾插
                    curLayer.offerLast(curNode.val);
                }
               

                
                if(curNode.left!=null){
                    queue.offer(curNode.left);
                }   
                if(curNode.right!=null){
                    queue.offer(curNode.right);
                }

            }

            ans.add(new ArrayList(curLayer));
            fromR=!fromR;

        }
        return ans;
    }
}

//12.22 每日一题
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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        if(root==null){
            return ans;
        }
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        boolean fromR = false;
        queue.offer(root);
        while(!queue.isEmpty()){
            int len = queue.size();
            List<Integer> curLayer = new ArrayList<>();
            for(int i=0;i<len;i++){
                TreeNode curNode = queue.poll(); //得到队首元素并出队
                curLayer.add(curNode.val);
                
                if(curNode.left!=null){
                    queue.offer(curNode.left);
                }   
                if(curNode.right!=null){
                     queue.offer(curNode.right);
                }
                

            }
            if(fromR){
                Collections.reverse(curLayer);
            }
            ans.add(curLayer);
            fromR=!fromR;

        }
        return ans;
    }
}
/*
层序遍历+一个step如果从又到左就reverse
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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
                List<List<Integer>> ret = new ArrayList<List<Integer>>();
        if (root == null) {
            return ret;
        }

        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.offer(root);
        int step = 0;
        while (!queue.isEmpty()) {
            List<Integer> level = new ArrayList<Integer>();
            int currentLevelSize = queue.size();
            for (int i = 1; i <= currentLevelSize; ++i) {
                TreeNode node = queue.poll();
                level.add(node.val);
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }

            if(step % 2 == 1){ //右到左
                Collections.reverse(level);
            }

            ret.add(level);
            step++;
        }
        
        return ret;


    }
}
