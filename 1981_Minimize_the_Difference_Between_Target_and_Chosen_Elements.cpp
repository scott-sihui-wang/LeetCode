class Solution {
public:
    int DP[70][4901];
    int dp(vector<vector<int>>& mat,int row,int sum,int target){
        if(row==mat.size()){
            return abs(target-sum);
        }
        if(DP[row][sum]!=-1){
            return DP[row][sum];
        }
        int ans=INT_MAX;
        for(int i=0;i<mat[row].size();i++){
            ans=min(ans,dp(mat,row+1,sum+mat[row][i],target));
        }
        return DP[row][sum]=ans;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        memset(DP,-1,sizeof(DP));
        return dp(mat,0,0,target);
    }
};