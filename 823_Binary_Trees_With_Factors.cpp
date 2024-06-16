class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int MOD=1000000007;
        sort(arr.begin(),arr.end());
        unordered_map<int,int>vals;
        int n=arr.size();
        for(int i=0;i<n;i++){
            vals[arr[i]]=i;
        }
        long long dp[n];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        long long ans=1;
        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0 && vals.find(arr[i]/arr[j])!=vals.end()){
                    dp[i]+=(dp[j]*dp[vals[arr[i]/arr[j]]])%MOD;
                    dp[i]=dp[i]%MOD;
                }
            }
            ans+=dp[i];
            ans=ans%MOD;
        }
        return ans;
    }
};