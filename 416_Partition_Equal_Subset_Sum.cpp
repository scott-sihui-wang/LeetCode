class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0)return false;
        bool dp[n+1][sum/2+1];
        dp[0][0]=true;
        for(int i=1;i<=sum/2;i++){
            dp[0][i]=false;
        }
        for(int i=1;i<=n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum/2;j++){
                dp[i][j]=(dp[i-1][j]||(j>=nums[i-1] && dp[i-1][j-nums[i-1]]));
            }
        }
        return dp[n][sum/2];
    }
};