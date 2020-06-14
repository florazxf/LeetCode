/*

给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

 

示例 1:

给定 nums = [3,2,2,3], val = 3,

函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,1,2,2,3,0,4,2], val = 2,

函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

注意这五个元素可为任意顺序。

你不需要考虑数组中超出新长度后面的元素。
 

说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
int len = removeElement(nums, val);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/

//方法一： 双指针（左右指针）
/*
因为要用原地法，不能开辟额外空间， 所以就用右边的值来替换掉左边等于val的值

自己做的时候先用i+1进行替换，发现很麻烦，忽略了元素顺序可以更改这一属性。 看了tag是双指针后才反应过来
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0){return 0;}
        int left = 0;
        int right = nums.size()-1;
        int cnt=0;

        while(left<right){
            if(nums[left]==val){
                cnt++;
                while(nums[right]==val){ //右边要替换的值等于val则right--
                    cnt++;
                    right--;
                    if(left ==right){return nums.size()-cnt;}
                }
                nums[left]=nums[right];//用右边的值来替换掉左边等于val的值
                right--;
            }
            left++;
        }
        if(nums[left]==val) {cnt++;}
        return nums.size()-cnt;
    }
};
//方法二：左右指针 
/*
当我们遇到 nums[i] = valnums[i]=val 时，我们可以将当前元素与最后一个元素进行交换，并释放最后一个元素。这实际上使数组的大小减少了 1。

请注意，被交换的最后一个元素可能是您想要移除的值。但是不要担心，在下一次迭代中，我们仍然会检查这个元素。

和方法一即自己做的方法的区别是，替换时不判断nums[right]是否等于val， 等下一次迭代中再判断

*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        //if(nums.size()==0){return 0;}

        int left = 0;
        int right = nums.size();
        
        while(left<right){
            if(nums[left]==val){
                nums[left] = nums[right-1];
                right--;
            }
            else{ //直到nums[left]!=val才继续判断
                left++;
            }

        }
        return right;
    }

};
//方法三：快慢指针
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int i=0;//新数组的右边界

        for(int j=0;j<nums.size();j++){ //遍历旧数组 如果等于val就跳过
            if(nums[j]!=val){ //不等于val就赋值给当前i索引的位置
                nums[i] = nums[j];
                i++; 
            }
        }
        return i;
    }

};
