class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int inOrder[graph.size()];
        unordered_map<int,unordered_set<int>> rev_adj;
        memset(inOrder,0,sizeof(inOrder));
        for(int i=0;i<graph.size();i++){
            inOrder[i]=graph[i].size();
            for(int j=0;j<graph[i].size();j++){
                rev_adj[graph[i][j]].insert(i);
            }
        }
        bool visited[graph.size()];
        memset(visited,false,sizeof(visited));
        vector<int> ans;
        bool next=true;
        while(next==true){
            next=false;
            for(int i=0;i<graph.size();i++){
                if(visited[i]==false && inOrder[i]==0){
                    ans.push_back(i);
                    visited[i]=true;
                    next=true;
                    unordered_set<int>::iterator iter;
                    for(iter=rev_adj[i].begin();iter!=rev_adj[i].end();iter++){
                        inOrder[*iter]--;
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};