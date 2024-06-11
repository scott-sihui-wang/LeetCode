class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        set<int>arr;
        for(int i=0;i<rewardValues.size();i++){
            arr.insert(rewardValues[i]);
        }
        vector<int>val(arr.size());
        int idx=0;
        for(auto iter=arr.begin();iter!=arr.end();iter++){
            val[idx++]=*iter;
        }
        bool dp[val.size()+1][2*val[val.size()-1]];
        memset(dp,false,sizeof(dp));
        dp[0][0]=true;
        for(int i=1;i<=val.size();i++){
            for(int j=0;j<=2*val[i-1]-1;j++){
                if(dp[i-1][j]==true || (j>=val[i-1] && dp[i-1][j-val[i-1]]==true && j-val[i-1]<val[i-1])){
                    dp[i][j]=true;
                }
            }
        }
        int ans=2*val[val.size()-1]-1;
        while(dp[val.size()][ans]==false){
            ans--;
        }
        return ans;
    }
};