class Solution {
public:
    int recursion(vector<int>& nums,int target,int* dp){
        if(dp[target]!=-1)return dp[target];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(target-nums[i]>=0){
                ans+=recursion(nums,target-nums[i],dp);
            }
        }
        dp[target]=ans;
        return ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        int dp[target+1];
        dp[0]=1;
        for(int i=1;i<=target;i++){
            dp[i]=-1;
        }
        return recursion(nums,target,dp);
    }
};