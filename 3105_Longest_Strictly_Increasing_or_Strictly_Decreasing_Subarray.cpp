class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1,dec=1;
        int inc_begin=0,inc_end=0,dec_begin=0,dec_end=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                inc_end=i;
            }
            else{
                inc=max(inc,inc_end-inc_begin+1);
                inc_begin=i;
                inc_end=i;
            }
            if(nums[i]<nums[i-1]){
                dec_end=i;
            }
            else{
                dec=max(dec,dec_end-dec_begin+1);
                dec_begin=i;
                dec_end=i;
            }
        }
        inc=max(inc,inc_end-inc_begin+1);
        dec=max(dec,dec_end-dec_begin+1);
        return max(inc,dec);
    }
};