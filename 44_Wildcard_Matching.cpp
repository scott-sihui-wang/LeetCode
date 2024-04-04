class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len=s.size(),p_len=p.size();
        bool dp[s_len+1][p_len+1];
        bool dp2[s_len+1][p_len+1];
        memset(dp,false,sizeof(dp));
        memset(dp2,false,sizeof(dp2));
        dp[0][0]=true;
        for(int i=0;i<=s_len;i++){
            dp2[i][0]=true;
        }
        for(int j=1;j<=p_len;j++){
            bool dp2_or=false;
            for(int i=0;i<=s_len;i++){
                if(p[j-1]=='*'){
                    dp[i][j]=dp2[i][j-1];
                }
                else if(p[j-1]=='?'){
                    dp[i][j]=(i>0 && dp[i-1][j-1]);
                }
                else{
                    dp[i][j]=(i>0 && s[i-1]==p[j-1] && dp[i-1][j-1]);
                }
                if(dp[i][j])dp2_or=true;
                dp2[i][j]=dp2_or;
            }
        }
        return dp[s_len][p_len];
    }
};