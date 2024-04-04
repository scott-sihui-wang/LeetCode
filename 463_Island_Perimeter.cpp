class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        bool vis[row][col];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0){
                    vis[i][j]=true;
                }
                else if(grid[i][j]==1){
                    vis[i][j]=false;
                }
            }
        }
        int perimeter,contrib;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(vis[i][j]==false){
                    perimeter=0;
                    int pos_x[10000];
                    int pos_y[10000];
                    pos_x[0]=i;
                    pos_y[0]=j;
                    vis[i][j]=true;
                    int left=0;
                    int right=1;
                    int prev_left;
                    while(left<right){
                        prev_left=left;
                        left=right;
                        for(int k=prev_left;k<left;k++){
                            contrib=4;
                            if(pos_x[k]-1>=0 && grid[pos_x[k]-1][pos_y[k]]==1){
                                contrib--;
                                if(vis[pos_x[k]-1][pos_y[k]]==false){
                                    pos_x[right]=pos_x[k]-1;
                                    pos_y[right++]=pos_y[k];
                                    vis[pos_x[k]-1][pos_y[k]]=true;
                                }
                            }
                            if(pos_x[k]+1<row && grid[pos_x[k]+1][pos_y[k]]==1){
                                contrib--;
                                if(vis[pos_x[k]+1][pos_y[k]]==false){
                                    pos_x[right]=pos_x[k]+1;
                                    pos_y[right++]=pos_y[k];
                                    vis[pos_x[k]+1][pos_y[k]]=true;
                                }
                            }
                            if(pos_y[k]-1>=0 && grid[pos_x[k]][pos_y[k]-1]==1){
                                contrib--;
                                if(vis[pos_x[k]][pos_y[k]-1]==false){
                                    pos_x[right]=pos_x[k];
                                    pos_y[right++]=pos_y[k]-1;
                                    vis[pos_x[k]][pos_y[k]-1]=true;
                                }
                            }
                            if(pos_y[k]+1<col && grid[pos_x[k]][pos_y[k]+1]==1){
                                contrib--;
                                if(vis[pos_x[k]][pos_y[k]+1]==false){
                                    pos_x[right]=pos_x[k];
                                    pos_y[right++]=pos_y[k]+1;
                                    vis[pos_x[k]][pos_y[k]+1]=true;
                                }
                            }
                            perimeter+=contrib;
                        }
                    }
                }
            }
        }
        return perimeter;
    }
};