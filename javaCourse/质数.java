/*
输出100以内的质数
*/


//自己的方法：
import java.util.Scanner;
public class AriExer {
    public static void main(String[] args){
        for(int i=2;i<=100;i++){
            int j = 2;
            for( j = 2;j<=i;j++){
                if(i%j==0){//不符合条件
                    break;
                }
            }
            if(j==i)
                System.out.println(i);
        }
    }
}


//老师的方法：
/*
做的改进是内循环的跳出条件可以是j<=Math.sqrt(i)
因为 c = a*b 我们已经看除a是否能除尽了，就不用判断b了 所以就开根号就可以了

*/


import java.util.Scanner;

public class AriExer {
    public static void main(String[] args){
        for(int i=2;i<=100;i++){

            boolean isFlag = true;
            for(int j = 2;j<=Math.sqrt(i);j++){
                if(i%j==0){//不符合条件
                    isFlag = false;
                    break;
                }
            }
            if(isFlag){
                System.out.println(i);
            }

        }
    }
}

//方法三： 用带标签的continue
import java.util.Scanner;
public class AriExer {
    public static void main(String[] args){
        label:for(int i=2;i<=100;i++){

            boolean isFlag = true;
            for(int j = 2;j<=Math.sqrt(i);j++){
                if(i%j==0){//不符合条
                    continue label;
                }
            }
            System.out.println(i);
        }
    }
}
