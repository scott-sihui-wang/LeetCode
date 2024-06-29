class Solution {
public:
    int DP(vector<vector<int>>&dp, vector<int>& arr, map<int,int>& dict, int idx1, int idx2, int n){
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        if(idx2==n){
            return dp[idx1][idx2]=2;
        }
        int num=arr[idx1]+arr[idx2];
        if(dict.find(num)==dict.end()){
            return dp[idx1][idx2]=2;
        }
        else{
            return 1+DP(dp,arr,dict,idx2,dict[num],n);
        }
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        map<int,int>dict;
        for(int i=0;i<n;i++){
            dict[arr[i]]=i;
        }
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=2;
        for(int i=n-1;i>=1;i--){
            for(int j=i-1;j>=0;j--){
                ans=max(ans,DP(dp,arr,dict,j,i,n-1));
            }
        }
        if(ans<3){
            return 0;
        }
        else{
            return ans;
        }
    }
};