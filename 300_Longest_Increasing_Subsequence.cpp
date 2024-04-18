class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size();
        int dp[len];
        int ans=1;
        for(int i=0;i<len;i++){
            dp[i]=1;
        }
        for(int i=len-2;i>=0;i--){
            for(int j=i+1;j<len;j++){
                if(nums[j]>nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};