class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long val=1;
        int idx=0,ans=0;
        while(val<=n){
            if(idx<nums.size() && val>=nums[idx]){
                val+=nums[idx];
                idx++;
            }
            else{
                ans++;
                val=val<<1;
            }
        }
        return ans;
    }
};