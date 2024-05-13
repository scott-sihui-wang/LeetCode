class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long dp[nums.size()];
        long long ans=1;
        dp[0]=1;
        for(int i=1;i<nums.size();i++){
            dp[i]=1+(nums[i]!=nums[i-1]?dp[i-1]:0);
            ans+=dp[i];
        }
        return ans;
    }
};