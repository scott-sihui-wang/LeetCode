class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int len=nums.size();
        int max_diff=-1;
        int max_val=0;
        for(int i=len-2;i>=0;i--){
            max_val=max(max_val,nums[i+1]);
            if(nums[i]<max_val){
                max_diff=max(max_diff,max_val-nums[i]);
            }
        }
        return max_diff;
    }
};