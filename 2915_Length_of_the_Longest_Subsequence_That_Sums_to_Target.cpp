class Solution {
public:
    int DP(vector<int>& nums, vector<vector<int>>& dp,int idx,int target){
        int n=nums.size();
        if(idx==n){
            if(target==0){
                return dp[idx][target]=0;
            }
            else if(target>0){
                return dp[idx][target]=INT_MIN;
            }
            else{
                return INT_MIN;
            }
        }
        if(target==0){
            return dp[idx][target]=0;
        }
        else if(target<0){
            return INT_MIN;
        }
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }
        int v1=1+DP(nums,dp,idx+1,target-nums[idx]);
        int v2=DP(nums,dp,idx+1,target);
        if(v1<0 && v2<0){
            return dp[idx][target]=INT_MIN;
        }
        else{
            return dp[idx][target]=max(v1,v2);
        }
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int v=DP(nums,dp,0,target);
        return v>0?v:-1;
    }
};