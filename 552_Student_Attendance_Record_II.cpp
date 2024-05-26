class Solution {
public:
    int checkRecord(int n) {
        if(n==1){
            return 3;
        }
        else if(n==2){
            return 8;
        }
        else if(n==3){
            return 19;
        }
        long long MOD=1000000007;
        long long dp_LP[n+1];
        memset(dp_LP,0,sizeof(dp_LP));
        dp_LP[0]=1;
        dp_LP[1]=2;
        dp_LP[2]=4;
        dp_LP[3]=7;
        for(int i=4;i<=n;i++){
            dp_LP[i]=((dp_LP[i-1]%MOD)+(dp_LP[i-2]%MOD)+(dp_LP[i-3]%MOD))%MOD;
        }
        int ans=0;
        ans+=(dp_LP[n])%MOD;
        ans=ans%MOD;
        for(int i=1;i<=n;i++){
            ans+=((dp_LP[i-1]%MOD)*(dp_LP[n-i]%MOD))%MOD;
            ans=ans%MOD;
        }
        return ans;
    }
};