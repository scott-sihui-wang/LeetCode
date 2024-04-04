class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        bool vis[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    vis[i][j]=true;
                }
                else if(grid[i][j]==1){
                    vis[i][j]=false;
                }
            }
        }
        int maxArea=0;
        int curArea;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==false){
                    curArea=1;
                    int pos_x[2500];
                    int pos_y[2500];
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
                            if(pos_x[k]-1>=0 && vis[pos_x[k]-1][pos_y[k]]==false){
                                pos_x[right]=pos_x[k]-1;
                                pos_y[right++]=pos_y[k];
                                vis[pos_x[k]-1][pos_y[k]]=true;
                                curArea++;
                            }
                            if(pos_x[k]+1<m && vis[pos_x[k]+1][pos_y[k]]==false){
                                pos_x[right]=pos_x[k]+1;
                                pos_y[right++]=pos_y[k];
                                vis[pos_x[k]+1][pos_y[k]]=true;
                                curArea++;
                            }
                            if(pos_y[k]-1>=0 && vis[pos_x[k]][pos_y[k]-1]==false){
                                pos_x[right]=pos_x[k];
                                pos_y[right++]=pos_y[k]-1;
                                vis[pos_x[k]][pos_y[k]-1]=true;
                                curArea++;
                            }
                            if(pos_y[k]+1<n && vis[pos_x[k]][pos_y[k]+1]==false){
                                pos_x[right]=pos_x[k];
                                pos_y[right++]=pos_y[k]+1;
                                vis[pos_x[k]][pos_y[k]+1]=true;
                                curArea++;
                            }
                        }
                    }
                    if(curArea>maxArea){
                        maxArea=curArea;
                    }
                }
            }
        }
        return maxArea;
    }
};