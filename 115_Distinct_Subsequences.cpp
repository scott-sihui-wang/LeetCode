class Solution {
public:
    int numDistinct(string s, string t) {
        int len_src=s.size(),len_tar=t.size();
        unsigned int dp[len_src+1][len_tar+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<len_src+1;i++){
            dp[i][len_tar]=1;
        }
        for(int i=0;i<len_tar;i++){
            dp[len_src][i]=0;
        }
        for(int i=len_tar-1;i>=0;i--){
            for(int j=len_src-1;j>=0;j--){
                if(s[j]==t[i]){
                    dp[j][i]=dp[j+1][i]+dp[j+1][i+1];
                }
                else{
                    dp[j][i]=dp[j+1][i];
                }
            }
        }
        return dp[0][0];
    }
};