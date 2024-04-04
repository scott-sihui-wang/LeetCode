class Solution {
public:
    void solve(bool** vis,vector<vector<int> >& grid,int m,int n,int start_x,int start_y,int& cnt){
        if(start_x-1>=0 && vis[start_x-1][start_y]==false){
            vis[start_x-1][start_y]=true;
            solve(vis,grid,m,n,start_x-1,start_y,cnt);
            vis[start_x-1][start_y]=false;
        }
        if(start_x+1<m && vis[start_x+1][start_y]==false){
            vis[start_x+1][start_y]=true;
            solve(vis,grid,m,n,start_x+1,start_y,cnt);
            vis[start_x+1][start_y]=false;
        }
        if(start_y-1>=0 && vis[start_x][start_y-1]==false){
            vis[start_x][start_y-1]=true;
            solve(vis,grid,m,n,start_x,start_y-1,cnt);
            vis[start_x][start_y-1]=false;
        }
        if(start_y+1<n && vis[start_x][start_y+1]==false){
            vis[start_x][start_y+1]=true;
            solve(vis,grid,m,n,start_x,start_y+1,cnt);
            vis[start_x][start_y+1]=false;
        }
        if(grid[start_x][start_y]==2){
            bool flag=true;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    flag=vis[i][j];
                    if(!flag)break;
                }
                if(!flag)break;
            }
            if(flag)++cnt;
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        bool** vis=new bool*[m];
        for(int i=0;i<m;i++){
            vis[i]=new bool[n];
        }
        int start_x,start_y;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==-1){
                    vis[i][j]=true;
                }
                else if(grid[i][j]==1){
                    vis[i][j]=true;
                    start_x=i;
                    start_y=j;
                }
                else{
                    vis[i][j]=false;
                }
            }
        }
        int cnt=0;
        solve(vis,grid,m,n,start_x,start_y,cnt);
        return cnt;
    }
};