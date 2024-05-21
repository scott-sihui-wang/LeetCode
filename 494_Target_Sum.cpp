class Solution {
public:
    int solve(vector<vector<int>>& dp,vector<int>& nums,int i,int target){
        if(target<-1000 || target>1000)return 0;
        if(dp[i][target+1000]!=-1)return dp[i][target+1000];
        return dp[i][target+1000]=solve(dp,nums,i-1,target-nums[i-1])+solve(dp,nums,i-1,target+nums[i-1]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(2001,-1));
        for(int i=0;i<2001;i++){
            dp[0][i]=0;
        }
        dp[0][1000]=1;
        return solve(dp,nums,n,target);
    }
};