class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int V=colors.size();
        int inDegree[V];
        memset(inDegree,0,sizeof(inDegree));
        vector<vector<int>>adj(V,vector<int>());
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            inDegree[edges[i][1]]++;
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int> V_sorted;
        while(!q.empty()){
            int v=q.front();
            V_sorted.push_back(v);
            q.pop();
            for(int i=0;i<adj[v].size();i++){
                inDegree[adj[v][i]]--;
                if(inDegree[adj[v][i]]==0){
                    q.push(adj[v][i]);
                }
            }
        }
        if(V_sorted.size()<V)return -1;
        reverse(V_sorted.begin(),V_sorted.end());
        int cnt[V][26];
        int ans=0;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<V_sorted.size();i++){
            for(int j=0;j<adj[V_sorted[i]].size();j++){
                for(int k=0;k<26;k++){
                    cnt[V_sorted[i]][k]=max(cnt[V_sorted[i]][k],cnt[adj[V_sorted[i]][j]][k]);
                }
            }
            cnt[V_sorted[i]][colors[V_sorted[i]]-'a']++;
            for(int k=0;k<26;k++){
                ans=max(ans,cnt[V_sorted[i]][k]);
            }
        }
        return ans;
    }
};