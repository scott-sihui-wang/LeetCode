class Solution {
public:
    void DFS(vector<string>& ans,unordered_map<string,multiset<string>>&adj,string src){
        while(adj[src].size()!=0){
            string next=*adj[src].begin();
            adj[src].erase(adj[src].begin());
            DFS(ans,adj,next);
        }
        ans.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>>adj;
        for(int i=0;i<tickets.size();i++){
            adj[tickets[i][0]].insert(tickets[i][1]);
        }
        vector<string>ans;
        DFS(ans,adj,string("JFK"));
        reverse(ans.begin(),ans.end());
        return ans;
    }
};