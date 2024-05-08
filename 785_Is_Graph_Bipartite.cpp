class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int num_v=graph.size();
        int groups[num_v];
        memset(groups,-1,sizeof(groups));
        for(int i=0;i<num_v;i++){
            if(groups[i]==-1){
                queue<int> q;
                q.push(i);
                groups[i]=0;
                while(!q.empty()){
                    int pa=q.front();
                    q.pop();
                    for(int j=0;j<graph[pa].size();j++){
                        if(groups[graph[pa][j]]==-1){
                            groups[graph[pa][j]]=(groups[pa]==0?1:0);
                            q.push(graph[pa][j]);
                        }
                        else if(groups[graph[pa][j]]==groups[pa])return false;
                    }
                }
            }
        }
        return true;
    }
};