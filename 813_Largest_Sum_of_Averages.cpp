class Solution {
public:
    double dp(vector<int>& nums,vector<vector<double>>& DP,int idx,int k){
        if(k==1){
            double sum=0.0;
            for(int i=0;i<=idx;i++){
                sum+=nums[i];
            }
            return DP[idx][k-1]=sum/(idx+1);
        }
        if(DP[idx][k-1]>=0.0)return DP[idx][k-1];
        double ans=DBL_MIN;
        double sum=0.0;
        double cnt=0.0;
        for(int i=idx;i>=k-1;i--){
            sum+=nums[i];
            cnt+=1.0;
            ans=max(ans,sum/cnt+dp(nums,DP,i-1,k-1));
        }
        return DP[idx][k-1]=ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<double>>DP(n,vector<double>(k,-1));
        return dp(nums,DP,nums.size()-1,k);
    }
};