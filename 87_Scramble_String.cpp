class Solution {
public:
    bool scramble(int dp[30][30][30],string& s1, string& s2,int idx1,int idx2,int len){
        if(len==1){
            dp[idx1][idx2][len-1]=(s1[idx1]==s2[idx2]);
            return dp[idx1][idx2][len-1];
        }
        else{
            if(dp[idx1][idx2][len-1]!=-1){
                return dp[idx1][idx2][len-1];
            }
            for(int i=1;i<len;i++){
                if(scramble(dp,s1,s2,idx1,idx2,i) && scramble(dp,s1,s2,idx1+i,idx2+i,len-i)){
                    dp[idx1][idx2][len-1]=true;
                    return true;
                }
                if(scramble(dp,s1,s2,idx1,idx2+i,len-i) && scramble(dp,s1,s2,idx1+len-i,idx2,i)){
                    dp[idx1][idx2][len-1]=true;
                    return true;
                }
            }
            dp[idx1][idx2][len-1]=false;
            return false;
        }
    }
    bool isScramble(string s1, string s2) {
        int dp[30][30][30];
        memset(dp,-1,sizeof(dp));
        return scramble(dp,s1,s2,0,0,s1.size());
    }
};