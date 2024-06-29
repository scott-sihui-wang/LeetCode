class Solution {
public:
    void DFS(vector<int> ancestors[], bool visited[], vector<vector<int>>& ans, int src, int idx){
        visited[idx]=true;
        for(int i=0;i<ancestors[idx].size();i++){
            if(visited[ancestors[idx][i]]==false){
                ans[src].push_back(ancestors[idx][i]);
                DFS(ancestors,visited,ans,src,ancestors[idx][i]);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        bool visited[n];
        vector<int>ancestors[n];
        for(int i=0;i<edges.size();i++){
            ancestors[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<int>>ans(n,vector<int>(0));
        for(int i=0;i<n;i++){
            memset(visited,false,sizeof(visited));
            DFS(ancestors,visited,ans,i,i);
            sort(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};