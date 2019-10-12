/*
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:
初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //思想就是把nums2的元素全都放到nums1里，然后用sort对nums1排序。
        //需要注意的问题是nums1的空间大于m+n时，要先把多余的零删掉，等最后排完序再补回来
        int b,c;
        c=0;
        //如果空间大小大于m+n,则nums1里有多余的0，先把这些零删掉，等排完序后再补回来
        if(nums1.size()>m+n){
            b = nums1.size()-m-n;
            c=b;
            while(b){
                nums1.pop_back();
                b--;
            }
        }
        int j=0;
        for(int i=m;i<m+n;i++){
            nums1[i] = nums2[j];
            j++;
        }
        sort(nums1.begin(),nums1.end());//对nums1进行排序
        //空间大小大于m+n的情况，把之前删掉的零补回来
        while(c){
            nums1.push_back(0);
            c--;
        }
            
    }
};
