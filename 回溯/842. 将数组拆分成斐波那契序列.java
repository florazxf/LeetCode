/*
给定一个数字字符串 S，比如 S = "123456579"，我们可以将它分成斐波那契式的序列 [123, 456, 579]。

形式上，斐波那契式序列是一个非负整数列表 F，且满足：

0 <= F[i] <= 2^31 - 1，（也就是说，每个整数都符合 32 位有符号整数类型）；
F.length >= 3；
对于所有的0 <= i < F.length - 2，都有 F[i] + F[i+1] = F[i+2] 成立。
另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。

返回从 S 拆分出来的任意一组斐波那契式的序列块，如果不能拆分则返回 []。
*/

//方法一:
/*
zxm想的,对于斐波那契来说,前两个数固定了,后面的就都固定了, 因此我们只用遍历第一个数的所有可能性和第二个数的所有可能性
*/

class Solution {
    public List<Integer> splitIntoFibonacci(String S) {
        
            List<Integer> ret = new ArrayList<Integer>();

        for(int i=0;i<S.length();i++){ //第一个数

            long a = Long.parseLong(S.substring(0, i + 1));
            if(a>Integer.MAX_VALUE|| a<0) break;
            ret.add((int)a);

            for(int j=i+1;j<S.length();j++){ //第二个数

                long b = Long.parseLong(S.substring(i+1,j+1));
                if(b>Integer.MAX_VALUE|| b<0) break;

                ret.add((int)b);
                long c = a + b;
                if(c>Integer.MAX_VALUE || c<0) break;
                Long temp=0L;
                int k = j;
                while(k<S.length()-1 && S.substring(k+1).startsWith(String.valueOf(c))){ //第三个数等于前两个数之和

                    k += String.valueOf(c).length();
                    ret.add((int)c);
                    temp = b;
                    b = c;
                    c = temp+c;
                    if(c>Integer.MAX_VALUE || c<0) break;
                }

                if(k==S.length()-1 && c == (temp+b) &&ret.size()>2){
                    return ret;
                }
                else{
                    ret.clear();
                    ret.add((int)a);
                }
                if(S.substring(i+1, j + 1).startsWith("0")) break;
            }
            ret.clear();
            if(S.substring(0, i + 1).startsWith("0")) break;
        }
        ret.clear();
        return ret;
    }
}

//方法二: 回溯
/*
就是把每个字母遍历,回溯算法其实就是不断尝试的过程，一旦尝试成功了，就算成功了，如果尝试失败了还会回到上一步，注意回到上一步的时候还要把状态还原到上一步的状态。

画出输 每backtrack一次就是下一层， 当前层的for是字母的个数 ，index是当前层起始元素，i是从index起第几个元素

*/

class Solution {
    public List<Integer> splitIntoFibonacci(String S) {
        List<Integer> list = new ArrayList<Integer>();
        backtrack(list, S, 0);
        return list;
    }

    public boolean backtrack(List<Integer> res, String S, int index){
        //遍历完S，且res长度大于3，表示找到
        if(S.length()==index && res.size()>=3){
            return true;
        }
        //从index开始截取第三个数
        long num=0L;
        for (int i = index; i < S.length(); i++) {
            //两位数以上 不能以0开头
            if(i>index && S.charAt(index)=='0'){
                break;
            }
            //拆分出的数必须符合 3232 位有符号整数类型
            num = num*10+S.charAt(i)-'0';
            if(num>Integer.MAX_VALUE){
                break;
            }
            //当前数 大于前两个数之和
            int size = res.size();
            if(size>=2){
                if((int)num<res.get(size-1)+res.get(size-2)){
                    continue;
                }
                if((int)num>res.get(size-1)+res.get(size-2))
                    break;
            }
            res.add((int)num);
         
            //找到了返回
            if(backtrack(res,S,i+1)){
                return true;
            }else{
                //没找到，回溯，把上一步添加到集合res中的数字给移除掉
                res.remove(res.size()-1);
            }
    
        }
        
        return false;
    }
}
