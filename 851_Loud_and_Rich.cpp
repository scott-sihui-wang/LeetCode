class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<int>ans(n,0);
        int inDeg[n];
        memset(inDeg,0,sizeof(inDeg));
        pair<int,int>loud[n];
        vector<int>adj[n];
        bool visited[n];
        memset(visited,false,sizeof(visited));
        int to_be_visited=n;
        for(int i=0;i<n;i++){
            loud[i]={i,quiet[i]};
        }
        for(int i=0;i<richer.size();i++){
            adj[richer[i][0]].push_back(richer[i][1]);
            inDeg[richer[i][1]]++;
        }
        while(to_be_visited>0){
            for(int i=0;i<n;i++){
                if(visited[i]==false && inDeg[i]==0){
                    visited[i]=true;
                    to_be_visited--;
                    ans[i]=loud[i].first;
                    for(int j=0;j<adj[i].size();j++){
                        inDeg[adj[i][j]]--;
                        if(loud[adj[i][j]].second>loud[i].second){
                            loud[adj[i][j]]=loud[i];
                        }
                    }
                }
            }
        }
        return ans;        
    }
};