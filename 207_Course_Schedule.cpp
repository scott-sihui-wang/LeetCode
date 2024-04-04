class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        int inDegree[numCourses];
        memset(inDegree,0,sizeof(inDegree));
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int v=q.front();
            q.pop();
            for(int i=0;i<adj[v].size();i++){
                inDegree[adj[v][i]]--;
                if(inDegree[adj[v][i]]==0){
                    q.push(adj[v][i]);
                }
            }
        }
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]!=0)return false;
        }
        return true;
    }
};