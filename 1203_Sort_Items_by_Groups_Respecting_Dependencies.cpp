class Solution {
public:
    bool topologicalSort(vector<vector<int>>&adj,int inDegree[],int n,vector<int>& ans){
        queue<int>q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int v=q.front();
            q.pop();
            ans.push_back(v);
            for(int i=0;i<adj[v].size();i++){
                inDegree[adj[v][i]]--;
                if(inDegree[adj[v][i]]==0){
                    q.push(adj[v][i]);
                }
            }
        }
        return n==ans.size();
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int g_num=m,g_id[n];
        for(int i=0;i<n;i++){
            if(group[i]!=-1){
                g_id[i]=group[i];
            }
            else{
                g_id[i]=g_num;
                g_num++;
            }
        }
        vector<vector<int>>V_adj(n,vector<int>());
        int V_inDegree[n];
        memset(V_inDegree,0,sizeof(V_inDegree));
        vector<vector<int>>G_adj(g_num,vector<int>());
        int G_inDegree[g_num];
        memset(G_inDegree,0,sizeof(G_inDegree));
        for(int i=0;i<n;i++){
            for(int j=0;j<beforeItems[i].size();j++){     
                if(g_id[i]!=g_id[beforeItems[i][j]]){
                    G_adj[g_id[beforeItems[i][j]]].push_back(g_id[i]);
                    G_inDegree[g_id[i]]++;
                }
                V_adj[beforeItems[i][j]].push_back(i);
                V_inDegree[i]++;
            }
        }
        vector<int> V_sorted;
        vector<int> G_sorted;
        if (!topologicalSort(V_adj,V_inDegree,n,V_sorted)) return {};
        if (!topologicalSort(G_adj,G_inDegree,g_num,G_sorted)) return {};
        vector<vector<int>> g_sorted_v(g_num,vector<int>());
        for(int i=0;i<V_sorted.size();i++){
            g_sorted_v[g_id[V_sorted[i]]].push_back(V_sorted[i]);
        }
        vector<int>ans;
        for(int i=0;i<G_sorted.size();i++){
            for(int j=0;j<g_sorted_v[G_sorted[i]].size();j++){
                ans.push_back(g_sorted_v[G_sorted[i]][j]);
            }
        }
        return ans;
    }
};