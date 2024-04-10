class Solution {
public:
    int minCut(string s) {
        int len=s.size();
        if(len==1)return 0;
        int dp[len+1];
        for(int i=0;i<=len;i++){
            dp[i]=i-1;
        }
        for(int i=0;i<len;i++){
            for(int j=0;i-j>=0 && i+j<len && s[i-j]==s[i+j];j++){
                dp[i+j+1]=min(dp[i+j+1],dp[i-j]+1);
            }
            for(int j=0;i-j>=0 && i+j<len && s[i-j]==s[i+j+1];j++){
                dp[i+j+2]=min(dp[i+j+2],dp[i-j]+1);
            }
        }
        return dp[len];
    }
};