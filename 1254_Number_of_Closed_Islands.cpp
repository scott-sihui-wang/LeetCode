class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        bool vis[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    vis[i][j]=true;
                }
                else{
                    vis[i][j]=false;
                }
            }
        }
        int cnt=0;
        bool isClosed;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==false){
                    isClosed=true;
                    int pos_x[10000];
                    int pos_y[10000];
                    int left=0;
                    int right=1;
                    int prev_left;
                    pos_x[0]=i;
                    pos_y[0]=j;
                    vis[i][j]=true;
                    while(left<right){
                        prev_left=left;
                        left=right;
                        for(int k=prev_left;k<left;k++){
                            if(pos_x[k]-1>=0){
                                if(vis[pos_x[k]-1][pos_y[k]]==false){
                                    pos_x[right]=pos_x[k]-1;
                                    pos_y[right++]=pos_y[k];
                                    vis[pos_x[k]-1][pos_y[k]]=true;
                                }
                            }
                            else{
                                isClosed=false;
                            }
                            if(pos_x[k]+1<m){
                                if(vis[pos_x[k]+1][pos_y[k]]==false){
                                    pos_x[right]=pos_x[k]+1;
                                    pos_y[right++]=pos_y[k];
                                    vis[pos_x[k]+1][pos_y[k]]=true;
                                }
                            }
                            else{
                                isClosed=false;
                            }
                            if(pos_y[k]-1>=0){
                                if(vis[pos_x[k]][pos_y[k]-1]==false){
                                    pos_x[right]=pos_x[k];
                                    pos_y[right++]=pos_y[k]-1;
                                    vis[pos_x[k]][pos_y[k]-1]=true;
                                }
                            }
                            else{
                                isClosed=false;
                            }
                            if(pos_y[k]+1<n){
                                if(vis[pos_x[k]][pos_y[k]+1]==false){
                                    pos_x[right]=pos_x[k];
                                    pos_y[right++]=pos_y[k]+1;
                                    vis[pos_x[k]][pos_y[k]+1]=true;
                                }
                            }
                            else{
                                isClosed=false;
                            }
                        }
                    }
                    if(isClosed){
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }
};