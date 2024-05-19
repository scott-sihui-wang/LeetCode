class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int MOD=1337;
        a=a%1337;
        int n=b.size();
        int sol[n];
        sol[n-1]=a;
        for(int i=n-2;i>=0;i--){
            long long a_pow=sol[i+1];
            long long a_pow_2=((a_pow%MOD)*(a_pow%MOD))%MOD;
            long long a_pow_4=((a_pow_2%MOD)*(a_pow_2%MOD))%MOD;
            long long a_pow_8=((a_pow_4%MOD)*(a_pow_4%MOD))%MOD;
            sol[i]=((a_pow_8%MOD)*(a_pow_2%MOD))%MOD;
        }
        long long ans=1;
        for(int i=0;i<n;i++){
            long long mul=1;
            if(b[i]!=0){
                for(int j=0;j<b[i];j++){
                    mul=((mul%MOD)*(sol[i]%MOD))%MOD;
                }
            }
            ans=((ans%MOD)*(mul%MOD))%MOD;
        }
        return ans;
    }
};