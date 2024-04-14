class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        int graph[numCourses][numCourses];
        int inDegree[numCourses];
        bool visited[numCourses];
        memset(graph,0,sizeof(graph));
        memset(inDegree,0,sizeof(inDegree));
        memset(visited,false,sizeof(visited));
        for(int i=0;i<prerequisites.size();i++){
            inDegree[prerequisites[i][0]]++;
            graph[prerequisites[i][1]][prerequisites[i][0]]=1;
        }
        int cnt;
        do{
            cnt=0;
            for(int i=0;i<numCourses;i++){
                if(inDegree[i]==0 && visited[i]==false){
                    cnt++;
                    ans.push_back(i);
                    visited[i]=true;
                }
            }
            for(int i=ans.size()-cnt;i<ans.size();i++){
                for(int j=0;j<numCourses;j++){
                    if(graph[ans[i]][j]!=0){
                        graph[ans[i]][j]=0;
                        inDegree[j]--;
                    }
                }
            }
        }while(cnt>0);
        if(ans.size()!=numCourses){
            ans.clear();
        }
        return ans;
    }
};