class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        bool vis[m][n];
        int dist[m][n];
        queue<int> pos_x;
        queue<int> pos_y;
        int left=0;
        int right=0;
        int prev_left;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    vis[i][j]=true;
                    dist[i][j]=0;
                    pos_x.push(i);
                    pos_y.push(j);
                }
                else{
                    vis[i][j]=false;
                }
            }
        }
        while(!pos_x.empty()){
            int x=pos_x.front();
            int y=pos_y.front();
            pos_x.pop();
            pos_y.pop();
            if(x-1>=0 && vis[x-1][y]==false){
                pos_x.push(x-1);
                pos_y.push(y);
                vis[x-1][y]=true;
                dist[x-1][y]=dist[x][y]+1;
            }
            if(x+1<m && vis[x+1][y]==false){
                pos_x.push(x+1);
                pos_y.push(y);
                vis[x+1][y]=true;
                dist[x+1][y]=dist[x][y]+1;
            }
            if(y-1>=0 && vis[x][y-1]==false){
                pos_x.push(x);
                pos_y.push(y-1);
                vis[x][y-1]=true;
                dist[x][y-1]=dist[x][y]+1;
            }
            if(y+1<n && vis[x][y+1]==false){
                pos_x.push(x);
                pos_y.push(y+1);
                vis[x][y+1]=true;
                dist[x][y+1]=dist[x][y]+1;
            }
        }
        vector<vector<int> >sol;
        for(int i=0;i<m;i++){
            vector<int> sub_sol;
            for(int j=0;j<n;j++){
                sub_sol.push_back(dist[i][j]);
            }
            sol.push_back(sub_sol);
        }
        return sol;
    }
};