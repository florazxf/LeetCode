/*
给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。现在从这两个数组中选出 k (k <= m + n) 个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。

求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。

说明: 请尽可能地优化你算法的时间和空间复杂度。

示例 1:

输入:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
输出:
[9, 8, 6, 5, 3]
示例 2:

输入:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
输出:
[6, 7, 6, 0, 4]
示例 3:

输入:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
输出:
[9, 8, 9]

*/
class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int m = 0, n = 0;
        if(nums1 == null || (m = nums1.length) == 0)    return maxNumberK(nums2, k);
        if(nums2 == null || (n = nums2.length) == 0)    return maxNumberK(nums1, k);
        /*
            0 <= i <= m
            0 <= k-i <= n  ==> k-n <= i <= k
        ==> Math.max(0, k-n) <= i <= Math.min(m, k)
        */
        int[] res = null;
        for(int i = Math.max(0, k-n), limit = Math.min(m, k); i <= limit; i++){
            int[] a = maxNumberK(nums1, i);
            int[] b = maxNumberK(nums2, k-i);
            int[] c = merge(a, b);
            res = res == null || compare(res, 0, c, 0) < 0 ? c : res;
        }

        return res;

    }

    //合并
    public int[] merge(int[] num1,int[] num2){
        int n1 = num1.length, n2 = num2.length;
        if(n1==0){
            return num2;
        }
        if(n2==0){
            return num1;
        }
        int n = n1+n2;
        int[] ans = new int[n];
        int l1=0,l2=0;
        int i=0;
        while(l1<n1 &&l2<n2){
            ans[i++] = compare(num1,l1,num2,l2)>=0?num1[l1++]:num2[l2++];
        }
        while(l1<n1){
            ans[i++] = num1[l1++];
        }
        while(l2<n2){
            ans[i++] = num2[l2++];
        }

        return ans;

    }

    // 比较 nums1[i,m)  和 nums2[j, n)
    // nums1 != null && nums2 != null
    private int compare(int[] nums1, int i, int[] nums2, int j){
        int m = nums1.length;
        int n = nums2.length;

        for(int k=0, limit = Math.min(m-i, n-j); k < limit; k++){
            if(nums1[i + k] != nums2[j + k])
                return Integer.compare(nums1[i + k], nums2[j + k]);
        }

        return Integer.compare(m - i, n - j);
    }
    //从num中得到长度位k的 最大数
    public int[] maxNumberK(int []num,int k){
        //Stack<Integer> stack = new Stack<Integer>();
        int[] stack = new int[k];
        int top=-1;//栈顶元素的指针
        int remain = num.length-k; //去掉的元素
        for (int i = 0; i < num.length; i++) {

            while(top>=0 && stack[top]<num[i] && remain>0){
                top--; //出栈
                remain--;
            }
            if(top<k-1){ //还能加
                stack[++top] = num[i];
            }else {
                remain--;
            }

        }

        return stack;
    }
}
