class Solution {
public:
    int solve(int dp[],int n,int idx,vector<int>& arr,int difference,unordered_map<int,vector<int>>& p){
        if(dp[idx]!=-1)return dp[idx];
        int ans=0;
        if(p.find(arr[idx]-difference)!=p.end()){
            for(int i=0;i<p[arr[idx]-difference].size();i++){
                if(p[arr[idx]-difference][i]>=idx)break;
                ans=max(ans,solve(dp,n,p[arr[idx]-difference][i],arr,difference,p));
            }
        }
        dp[idx]=ans+1;
        return dp[idx];
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,vector<int>>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(mp.find(arr[i])==mp.end()){
                mp[arr[i]]={i};
            }
            else{
                mp[arr[i]].push_back(i);
            }
        }
        int dp[n];
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,solve(dp,n,i,arr,difference,mp));
        }
        return ans;
    }
};