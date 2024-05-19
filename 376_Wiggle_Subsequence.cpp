class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int dp[n][2];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        dp[0][1]=1;
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i][1]=max(dp[j][0]+1,dp[i][1]);
                }
                if(nums[j]>nums[i]){
                    dp[i][0]=max(dp[j][1]+1,dp[i][0]);
                }
            }
            ans=max(ans,max(dp[i][0],dp[i][1]));
        }
        return ans;
    }
};