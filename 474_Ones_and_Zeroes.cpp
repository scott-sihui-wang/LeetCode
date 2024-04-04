class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len=strs.size();
        int num_m[len];
        int num_n[len];
        memset(num_m,0,sizeof(num_m));
        memset(num_n,0,sizeof(num_n));
        for(int i=0;i<len;i++){
            for(int j=0;j<strs[i].length();j++){
                if(strs[i][j]=='0'){
                    num_m[i]++;
                }
                else if(strs[i][j]=='1'){
                    num_n[i]++;
                }
            }
        }
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<len;i++){
            for(int j=m;j>=num_m[i];j--){
                for(int k=n;k>=num_n[i];k--){
                    dp[j][k]=max(dp[j][k],1+dp[j-num_m[i]][k-num_n[i]]);
                }
            }
        }
        return dp[m][n];
    }
};