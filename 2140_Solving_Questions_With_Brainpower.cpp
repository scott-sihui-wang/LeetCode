class Solution {
public:
    long long solve(vector<vector<int>>&questions,vector<vector<long long>>& dp,int idx,int skip){
        if(idx>=dp.size())return 0;
        if(dp[idx][skip]!=-1)return dp[idx][skip];
        if(skip==0){
            return dp[idx][skip]=questions[idx][0]+max(solve(questions,dp,idx+questions[idx][1]+1,0),solve(questions,dp,idx+questions[idx][1]+1,1));
        }
        else{
            return dp[idx][skip]=max(solve(questions,dp,idx+1,0),solve(questions,dp,idx+1,1));
        }
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return max(solve(questions,dp,0,0),solve(questions,dp,0,1));
    }
};