class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len=triangle.size();
        int dp[len][len];
        dp[0][0]=triangle[0][0];
        for(int i=1;i<len;i++){
            dp[i][0]=dp[i-1][0]+triangle[i][0];
            dp[i][i]=dp[i-1][i-1]+triangle[i][i];
            for(int j=1;j<=i-1;j++){
                dp[i][j]=min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j];
            }
        }
        int min_path=INT_MAX;
        for(int i=0;i<len;i++){
            min_path=min(min_path,dp[len-1][i]);
        }
        return min_path;
    }
};