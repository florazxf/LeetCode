/*
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
*/


//方法一:自己的方法
/*
刚开始只用了一个list 想着 每次clear() 调了好久才发现 错误原因
java的是引用 

还有就是自己的代码写复杂了  不需要判断第一行
*/

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if(numRows==0){
            return res;
        }

        List<Integer> lst1 = new ArrayList<Integer>();
        lst1.add(1);
        res.add(lst1);


        for (int i = 1; i <numRows; i++) { //从第二行开始
            List<Integer> lst = new ArrayList<Integer>();
            for (int j = 0;j <= i;j++){
                if(j>0 && j<i){
                    int i1 = res.get(i - 1).get(j - 1) + res.get(i - 1).get(j);

                    lst.add(i1);
                }
                else{
                    lst.add(1);
                }
            }
            res.add(lst);

        }

        return res;


    }
}


//修改后的方法
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();

        for (int i = 0; i <numRows; i++) { //从第二行开始
            List<Integer> lst = new ArrayList<Integer>();
            for (int j = 0;j <= i;j++){
                if(j>0 && j<i){
                    int i1 = res.get(i - 1).get(j - 1) + res.get(i - 1).get(j);

                    lst.add(i1);
                }
                else{
                    lst.add(1);
                }
            }
            res.add(lst);

        }

        return res;


    }
}
