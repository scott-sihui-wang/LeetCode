class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n=nums.size();
        long long dp[n][2];
        dp[n-1][0]=nums[n-1];
        dp[n-1][1]=nums[n-1]^k;
        for(int i=n-2;i>=0;i--){
            dp[i][0]=max(nums[i]+dp[i+1][0],(nums[i]^k)+dp[i+1][1]);
            dp[i][1]=max(nums[i]+dp[i+1][1],(nums[i]^k)+dp[i+1][0]);
        }
        return dp[0][0];
    }
};