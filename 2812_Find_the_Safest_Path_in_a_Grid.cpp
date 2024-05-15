class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> score(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    score[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x+1<n && score[x+1][y]>score[x][y]+1){
                score[x+1][y]=score[x][y]+1;
                q.push({x+1,y});
            }
            if(x-1>=0 && score[x-1][y]>score[x][y]+1){
                score[x-1][y]=score[x][y]+1;
                q.push({x-1,y});
            }
            if(y+1<n && score[x][y+1]>score[x][y]+1){
                score[x][y+1]=score[x][y]+1;
                q.push({x,y+1});
            }
            if(y-1>=0 && score[x][y-1]>score[x][y]+1){
                score[x][y-1]=score[x][y]+1;
                q.push({x,y-1});
            }
        }
        priority_queue<pair<int,pair<int,int>>>pq;
        bool visited[n][n];
        memset(visited,false,sizeof(visited));
        pq.push({score[0][0],{0,0}});
        visited[0][0]=true;
        while(!pq.empty()){
            int s=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            if(x==n-1 && y==n-1)return s;
            pq.pop();
            if(x+1<n && visited[x+1][y]==false){
                visited[x+1][y]=true;
                pq.push({min(score[x+1][y],s),{x+1,y}});
            }
            if(x-1>=0 && visited[x-1][y]==false){
                visited[x-1][y]=true;
                pq.push({min(score[x-1][y],s),{x-1,y}});
            }
            if(y+1<n && visited[x][y+1]==false){
                visited[x][y+1]=true;
                pq.push({min(score[x][y+1],s),{x,y+1}});
            }
            if(y-1>=0 && visited[x][y-1]==false){
                visited[x][y-1]=true;
                pq.push({min(score[x][y-1],s),{x,y-1}});
            }
        }
        return -1;
    }
};