class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int dp[s.size()][s.size()];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<s.size();i++){
            dp[i][i]=1;
        }
        for(int i=0;i<s.size()-1;i++){
            dp[i][i+1]=(s[i]==s[i+1]?2:1);
        }
        for(int len=3;len<=s.size();len++){
            for(int i=0;i<s.size()-len+1;i++){
                if(s[i]==s[i+len-1]){
                    dp[i][i+len-1]=dp[i+1][i+len-2]+2;
                }
                else{
                    dp[i][i+len-1]=max(dp[i][i+len-2],dp[i+1][i+len-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};