class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if(m>n){
            return findMedianSortedArrays(nums2,nums1);
        }
        int left=0,right=m;
        while(left<=right){
            int mid_m=(left+right)/2;
            int mid_n=(m+n+1)/2-mid_m;
            int left_max_m=(mid_m<=0?INT_MIN:nums1[mid_m-1]);
            int left_max_n=(mid_n<=0?INT_MIN:nums2[mid_n-1]);
            int right_min_m=(mid_m>=m?INT_MAX:nums1[mid_m]);
            int right_min_n=(mid_n>=n?INT_MAX:nums2[mid_n]);
            if(left_max_m<=right_min_n && left_max_n<=right_min_m){
                if((m+n)%2==0){
                    return (max(left_max_m,left_max_n)+min(right_min_m,right_min_n))/2.0;
                }
                else{
                    return max(left_max_m,left_max_n);
                }
            }
            else if(left_max_m>right_min_n){
                right=mid_m-1;
            }
            else{
                left=mid_m+1;
            }
        }
        return 0;
    }
};