class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int sz=nums.size();
        if(sz==1)return 0;
        int dp1[sz],dp2[sz];
        int longest;
        if(nums[sz-1]==1){
            dp1[sz-1]=1;
            dp2[sz-1]=1;
        }
        else{
            dp1[sz-1]=0;
            dp2[sz-1]=1;
        }
        longest=0;
        for(int i=sz-2;i>=0;i--){
            if(nums[i]==0){
                dp1[i]=0;
                dp2[i]=dp1[i+1]+1;
            }
            else{
                dp1[i]=dp1[i+1]+1;
                dp2[i]=dp2[i+1]+1;
            }
            longest=max(longest,dp2[i]-1);
        }
        return longest;
    }
};