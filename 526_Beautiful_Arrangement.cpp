class Solution {
public:
    void DFS(bool visited[], int idx, int n, int& ans){
        if(idx==n){
            ans++;
            return;
        }
        for(int i=0;i<n;i++){
            if(visited[i]==false && ((i+1)%(idx+1)==0 || (idx+1)%(i+1)==0)){
                visited[i]=true;
                DFS(visited,idx+1,n,ans);
                visited[i]=false;
            }
        }
    }
    int countArrangement(int n) {
        bool visited[n];
        memset(visited,false,sizeof(visited));
        int ans=0;
        DFS(visited,0,n,ans);
        return ans;
    }
};