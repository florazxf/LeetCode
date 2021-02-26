/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
*/


// 用栈

当前元素比栈顶小就入栈， 比栈顶大就出栈，这时出栈的是坑里的高度， 新的栈顶就是左边的边界
这个时候找到两边低的那边 减去坑里的高度 就是这里能接到的雨水

class Solution {
    public int trap(int[] height) {
        int n = height.length;
        Stack<Integer> stack = new Stack<Integer>();//存索引
        int ans = 0;
        for(int i =0;i<n;i++){
            //当前元素比栈顶元素大 就弹出
            while(!stack.empty()&&height[i]>height[stack.peek()]){
                //出栈的是坑里的元素
                int top = stack.pop(); //出栈的栈顶元素的索引
               
                if(stack.empty()){
                    break;
                }
                //找到两边边界的距离
                int distance = i-stack.peek()-1;
                //找到两边低的那个减去里面的
                int bounded_height = Math.min(height[i], height[stack.peek()])-height[top];
               
                ans += distance*bounded_height;
            }

            //入栈
            stack.push(i);
        }

        
        return ans;

    }



}









//方法一： 栈

/*
我们在遍历数组时维护一个栈。如果当前的条形块小于或等于栈顶的条形块，我们将条形块的索引入栈，意思是当前的条形块被栈中的前一个条形块界定。如果我们发现一个条形块长于栈顶，我们可以确定栈顶的条形块被当前条形块和栈的前一个条形块界定，因此我们可以弹出栈顶元素并且累加答案到 \text{ans}ans 。
算法

使用栈来存储条形块的索引下标。
遍历数组：
当栈非空且 \text{height}[current]>\text{height}[st.top()]height[current]>height[st.top()]
意味着栈中元素可以被弹出。弹出栈顶元素 \text{top}top。
计算当前元素和栈顶元素的距离，准备进行填充操作
\text{distance} = \text{current} - \text{st.top}() - 1distance=current−st.top()−1
找出界定高度
\text{bounded\_height} = \min(\text{height[current]}, \text{height[st.top()]}) - \text{height[top]}bounded_height=min(height[current],height[st.top()])−height[top]
往答案中累加积水量\text{ans} \mathrel{+}= \text{distance} \times \text{bounded\_height}ans+=distance×bounded_height
将当前索引下标入栈
将 \text{current}current 移动到下个位置

*/

class Solution {
public:
    int trap(vector<int>& height) {
        
        int ans = 0;
        stack<int>tmp;
        int top;
        for(int i=0;i<height.size();i++){
                
                while(!tmp.empty() && height[i]>height[tmp.top()]) //当前元素比栈顶元素大，即找到一个坑
                {
                    int top = tmp.top();
                    tmp.pop(); 
                    if(tmp.empty())
                        break;
                    int distance = i - tmp.top() - 1; //找到坑两个边界的距离
                    int bounded_height = min(height[i],height[tmp.top()])-height[top]; //把两个边界低的那个作为基准，减去坑底
                    ans += distance * bounded_height;
                    
                }

            
            tmp.push(i); //比前一个元素小就入栈
                
            }
        
        return ans;
            
        }
    
    
};
