class Solution {
public:
    void DFS(vector<vector<int>>&grid, vector<vector<bool>>& visited, int pos_x, int pos_y, int culmul, int& ans){
        visited[pos_x][pos_y]=true;
        bool isEnd=true;
        if(pos_x-1>=0 && grid[pos_x-1][pos_y]!=0 && visited[pos_x-1][pos_y]==false){
            DFS(grid,visited,pos_x-1,pos_y,culmul+grid[pos_x][pos_y],ans);
            visited[pos_x-1][pos_y]=false;
            isEnd=false;
        }
        if(pos_x+1<grid.size() && grid[pos_x+1][pos_y]!=0 && visited[pos_x+1][pos_y]==false){
            DFS(grid,visited,pos_x+1,pos_y,culmul+grid[pos_x][pos_y],ans);
            visited[pos_x+1][pos_y]=false;
            isEnd=false;
        }
        if(pos_y-1>=0 && grid[pos_x][pos_y-1]!=0 && visited[pos_x][pos_y-1]==false){
            DFS(grid,visited,pos_x,pos_y-1,culmul+grid[pos_x][pos_y],ans);
            visited[pos_x][pos_y-1]=false;
            isEnd=false;
        }
        if(pos_y+1<grid[0].size() && grid[pos_x][pos_y+1]!=0 && visited[pos_x][pos_y+1]==false){
            DFS(grid,visited,pos_x,pos_y+1,culmul+grid[pos_x][pos_y],ans);
            visited[pos_x][pos_y+1]=false;
            isEnd=false;
        }
        if(isEnd){
            ans=max(ans,culmul+grid[pos_x][pos_y]);
        }
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    for(int k=0;k<m;k++){
                        for(int l=0;l<n;l++){
                            visited[k][l]=false;
                        }
                    }
                    DFS(grid,visited,i,j,0,ans);
                }
            }
        }
        return ans;
    }
};
