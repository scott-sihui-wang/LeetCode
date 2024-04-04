class Solution {
public:
    void dfs(int cur,bool vis[],vector<vector<int> >& adj,vector<int>& bound,vector<vector<int> >&intervals){
        for(int i=0;i<adj[cur].size();i++){
            if(vis[adj[cur][i]]==false){
                vis[adj[cur][i]]=true;
                bound[0]=min(bound[0],intervals[adj[cur][i]][0]);
                bound[1]=max(bound[1],intervals[adj[cur][i]][1]);
                dfs(adj[cur][i],vis,adj,bound,intervals);
            }
        }
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len=intervals.size();
        vector<vector<int> >adj(len,vector<int>(0));
        for(int i=0;i<len-1;i++){
            for(int j=i+1;j<len;j++){
                int l=max(intervals[i][0],intervals[j][0]);
                int r=min(intervals[i][1],intervals[j][1]);
                if(l<=r){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        bool vis[len];
        memset(vis,0,sizeof(vis));
        vector<vector<int> >sol;
        for(int i=0;i<len;i++){
            if(vis[i]==false){
                vector<int> bound;
                bound.push_back(intervals[i][0]);
                bound.push_back(intervals[i][1]);
                vis[i]=true;
                dfs(i,vis,adj,bound,intervals);
                sol.push_back(bound);
            }
        }
        return sol;
    }
};