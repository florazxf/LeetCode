/*
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
*/


解析:https://mp.weixin.qq.com/s?__biz=MzU0ODMyNDk0Mw==&mid=2247487459&idx=1&sn=f45fc8231198edb3de2acc69e17986ea&chksm=fb419cc3cc3615d5d31d55072d5c2f58e4002aa8c1b637e89f1ef577e253943c04efc39c1b1d&scene=21#wechat_redirect

class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<List<String>>();
        List<char[]> board = new ArrayList<char[]>();
        for (int i = 0; i < n; i++) {
            char[] chars = new char[n];
            Arrays.fill(chars,'.');
            board.add(chars);
        }
        backtracking(n,0,board,res);
        return res;
    }

    public void backtracking(int n,int row,List<char[]> board,List<List<String>> res){
        //终止条件
        if(n==row){
            List<String> path = new ArrayList<String>();
            for(char[] chars:board){
                path.add(new String(chars));
            }
            res.add(path);
            return ;
        }
        for (int col = 0; col < n; col++) {
            if(valid(row,col,n,board)){//左上角 右上角和 上面都没有皇后 则添加
                board.get(row)[col] = 'Q';
                backtracking(n,row+1,board,res); // 看下一行
                board.get(row)[col] = '.';
            }
        }
    }

    public boolean valid(int row,int col,int n,List<char[]> board){
        //判断当前列有没有皇后， 因为是从上往下走 所以只用检查走过的行数
        for(int i=0;i<row;i++){
            if(board.get(i)[col]=='Q'){
                return false;
            }
        }
        //判断当前坐标的左上角有没有皇后
        for(int i = row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(board.get(i)[j]=='Q'){
                return false;
            }
        }
        //判断当前坐标的右上角有没有皇后
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(board.get(i)[j]=='Q'){
                return false;
            }
        }
        return true;
    }
    
}
