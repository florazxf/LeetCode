/*
给定两个数组，编写一个函数来计算它们的交集。

 

示例 1：

输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：

输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
 

说明：

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。

*/

//方法一： 放到set 

/*
首先用两个集合分别存储两个数组的元素，然后遍历较小的集合，判断其中的每个元素是否在另一个集合中
时间复杂度O(m+n)
*/

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<Integer>();
        Set<Integer> set2 = new HashSet<Integer>();
        for(int num:nums1){
            set1.add(num);
        }
        for(int num:nums2){
            set2.add(num);
        }
        return getIntersection(set1,set2);
    }

    public int[] getIntersection(Set<Integer> set1, Set<Integer> set2){
        if(set1.size()>set2.size()){
            return getIntersection(set2,set1);
        }
        Set<Integer> intersectionSet = new HashSet<Integer>();
        //如果set2的元素包含set1 就加入intersectionSet
        for(int num: set1){
            if(set2.contains(num)){
                intersectionSet.add(num);
            }
        }
        return intersectionSet.stream().mapToInt(Integer::valueOf).toArray();
    }

}

// 方法一：用stream 

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        //int[] 转List
        List<Integer> l1 = Arrays.stream(nums1).boxed().collect(Collectors.toList());
        //过滤 只保留并集元素
        List<Integer> l2 = Arrays.stream(nums2).filter(n->l1.contains(n)).distinct().boxed().collect(Collectors.toList());
        //List转 int[]
        return  l2.stream().mapToInt(Integer::valueOf).toArray();

    }
}

//方法二：双指针+排序

/*
先排好序，然后用双指针分别遍历两个数组 相等判断加入的上一个元素是否和当前元素相等
不相等 则对应的数字小的指针后移
时间复杂度O(mlogm+nlogn)
*/

class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        //先对nums1和nums2排序
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        int l1=0,l2=0;//两个指针
        int n1 = nums1.length,n2 = nums2.length;
        int[] intersection = new int[n1+n2];
        int index = 0;// 前一个放进去的指针
        while(l1<n1&&l2<n2){
            int num1 = nums1[l1];
            int num2 = nums2[l2];
            if(num1==num2){
                if(index==0 || intersection[index-1]!=num1){ //保证元素唯一性
                    intersection[index++] = num1;
                }
                l1++;
                l2++;
            }
            else if(num1<num2){ //两个数字不相等，就将较小数字右移一位
                l1++;
            } 
            else{
                l2++;
            }
        }

        return Arrays.copyOfRange(intersection,0,index);
    }



}
