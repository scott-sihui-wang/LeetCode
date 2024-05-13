class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp, int idx1, int idx2){
        if(idx1>=nums1.size() || idx2>=nums2.size()){
            return 0;
        }
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        int i=idx2;
        while(i<nums2.size() && nums2[i]!=nums1[idx1]){
            i++;
        }
        if(i<nums2.size()){
            dp[idx1][idx2]=max(1+solve(nums1,nums2,dp,idx1+1,i+1),solve(nums1,nums2,dp,idx1+1,idx2));
            return dp[idx1][idx2];
        }
        else{
            dp[idx1][idx2]=solve(nums1,nums2,dp,idx1+1,idx2);
            return dp[idx1][idx2];
        }
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size()));
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                dp[i][j]=-1;
            }
        }
        return solve(nums1,nums2,dp,0,0);
    }
};