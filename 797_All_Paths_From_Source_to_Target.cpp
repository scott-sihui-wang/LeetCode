class Solution {
public:
    void solve(vector<vector<int> >&graph,int cur,int idx,int path[],vector<vector<int> >&sol){
        if(cur==graph.size()-1){
            path[idx]=cur;
            vector<int> sub_sol;
            for(int i=0;i<=idx;i++){
                sub_sol.push_back(path[i]);
            }
            sol.push_back(sub_sol);
        }
        else{
            path[idx]=cur;
            for(int i=0;i<graph[cur].size();i++){
                solve(graph,graph[cur][i],idx+1,path,sol);
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int len=graph.size();
        int path[len];
        vector<vector<int> >sol;
        solve(graph,0,0,path,sol);
        return sol;
    }
};