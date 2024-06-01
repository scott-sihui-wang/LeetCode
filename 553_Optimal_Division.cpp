class Solution {
public:
    struct info{
        double max_val,min_val;
        string max_expr,min_expr;
        info(){
            max_val=DBL_MIN;
            min_val=DBL_MAX;
            max_expr="";
            min_expr="";
        }
    };
    info DP(vector<int>& nums,vector<vector<info>>& dp, int idx1,int idx2){
        if(dp[idx1][idx2].max_expr!=""){
            return dp[idx1][idx2];
        }
        if(idx1==idx2){
            dp[idx1][idx2].max_val=nums[idx1];
            dp[idx1][idx2].min_val=nums[idx1];
            dp[idx1][idx2].max_expr=to_string(nums[idx1]);
            dp[idx1][idx2].min_expr=to_string(nums[idx1]);
            return dp[idx1][idx2];
        }
        else if(idx1<idx2){
            for(int i=idx1;i<idx2;i++){
                info info1=DP(nums,dp,idx1,i);
                info info2=DP(nums,dp,i+1,idx2);
                if(info1.max_val/info2.min_val>dp[idx1][idx2].max_val){
                    dp[idx1][idx2].max_val=info1.max_val/info2.min_val;
                    if(i+1==idx2){
                        dp[idx1][idx2].max_expr=info1.max_expr+"/"+info2.min_expr;
                    }
                    else{
                        dp[idx1][idx2].max_expr=info1.max_expr+"/("+info2.min_expr+")";
                    }
                }
                if(info1.min_val/info2.max_val<dp[idx1][idx2].min_val){
                    dp[idx1][idx2].min_val=info1.min_val/info2.max_val;
                    if(i+1==idx2){
                        dp[idx1][idx2].min_expr=info1.min_expr+"/"+info2.max_expr;
                    }
                    else{
                        dp[idx1][idx2].min_expr=info1.min_expr+"/("+info2.max_expr+")";
                    }
                }
            }
            return dp[idx1][idx2];
        }
        return dp[idx1][idx2];
    }
    string optimalDivision(vector<int>& nums) {
        int n=nums.size();
        vector<vector<info>>dp(n,vector<info>(n));
        info ans=DP(nums,dp,0,nums.size()-1);
        return ans.max_expr;
    }
};