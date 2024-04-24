class Solution {
public:
    void dfs(int start,int end,vector<vector<int>>& adj,vector<vector<double>>& weights,double w,bool* visited, vector<double>& ans){
        if(ans.size()>0)return;
        for(int i=0;i<adj[start].size();i++){
            if(adj[start][i]==end){
                ans.push_back(w*weights[start][i]);
            }
            else if(visited[adj[start][i]]==false){
                visited[adj[start][i]]=true;
                dfs(adj[start][i],end,adj,weights,w*weights[start][i],visited,ans);
                visited[adj[start][i]]=false;
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> dict;
        int idx=-1;
        for(int i=0;i<equations.size();i++){
            if(dict.find(equations[i][0])==dict.end()){
                dict[equations[i][0]]=(++idx);
            }
            if(dict.find(equations[i][1])==dict.end()){
                dict[equations[i][1]]=(++idx);
            }
        }
        vector<vector<int>>adj(idx+1,vector<int>());
        vector<vector<double>>weights(idx+1,vector<double>());
        bool visited[idx+1];
        memset(visited,false,sizeof(visited));
        for(int i=0;i<equations.size();i++){
            adj[dict[equations[i][0]]].push_back(dict[equations[i][1]]);
            adj[dict[equations[i][1]]].push_back(dict[equations[i][0]]);
            weights[dict[equations[i][0]]].push_back(values[i]);
            weights[dict[equations[i][1]]].push_back(1.0/values[i]);
        }
        vector<double>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            if(dict.find(queries[i][0])==dict.end()||dict.find(queries[i][1])==dict.end()){
                ans[i]=-1.0;
            }
            else{
                vector<double>sol;
                dfs(dict[queries[i][0]],dict[queries[i][1]],adj,weights,1.0,visited,sol);
                if(sol.size()>0){
                    ans[i]=sol[0];
                }
                else{
                    ans[i]=-1.0;;
                }
            }
        }
        return ans;
    }
};
