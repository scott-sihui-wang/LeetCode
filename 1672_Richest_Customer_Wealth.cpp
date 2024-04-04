class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m=accounts.size();
        int n=accounts[0].size();
        int wealth[m];
        for(int i=0;i<m;i++){
            wealth[i]=0;
            for(int j=0;j<n;j++){
                wealth[i]+=accounts[i][j];
            }
        }
        int max_wealth=INT_MIN;
        for(int i=0;i<m;i++){
            if(wealth[i]>max_wealth){
                max_wealth=wealth[i];
            }
        }
        return max_wealth;
    }
};