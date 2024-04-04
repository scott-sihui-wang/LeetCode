class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int adj[n][n];
        memset(adj,0,sizeof(adj));
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]][roads[i][1]]=1;
            adj[roads[i][1]][roads[i][0]]=1;
        }
        int max_val=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int sum=-adj[i][j];
                for(int k=0;k<n;k++){
                    sum+=adj[i][k];
                    sum+=adj[j][k];
                }
                max_val=max(max_val,sum);
            }
        }
        return max_val;
    }
};