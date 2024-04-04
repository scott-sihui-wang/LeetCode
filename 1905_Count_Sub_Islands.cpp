class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid2.size();
        int n=grid2[0].size();
        bool vis[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==0){
                    vis[i][j]=true;
                }
                else{
                    vis[i][j]=false;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==false){
                    bool sub=true;
                    int pos_x[250000];
                    int pos_y[250000];
                    pos_x[0]=i;
                    pos_y[0]=j;
                    vis[i][j]=true;
                    if(grid1[i][j]!=1){
                        sub=false;
                    }
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
                                if(grid1[pos_x[k]-1][pos_y[k]]!=1){
                                    sub=false;
                                }
                            }
                            if(pos_x[k]+1<m && vis[pos_x[k]+1][pos_y[k]]==false){
                                pos_x[right]=pos_x[k]+1;
                                pos_y[right++]=pos_y[k];
                                vis[pos_x[k]+1][pos_y[k]]=true;
                                if(grid1[pos_x[k]+1][pos_y[k]]!=1){
                                    sub=false;
                                }
                            }
                            if(pos_y[k]-1>=0 && vis[pos_x[k]][pos_y[k]-1]==false){
                                pos_x[right]=pos_x[k];
                                pos_y[right++]=pos_y[k]-1;
                                vis[pos_x[k]][pos_y[k]-1]=true;
                                if(grid1[pos_x[k]][pos_y[k]-1]!=1){
                                    sub=false;
                                }
                            }
                            if(pos_y[k]+1<n && vis[pos_x[k]][pos_y[k]+1]==false){
                                pos_x[right]=pos_x[k];
                                pos_y[right++]=pos_y[k]+1;
                                vis[pos_x[k]][pos_y[k]+1]=true;
                                if(grid1[pos_x[k]][pos_y[k]+1]!=1){
                                    sub=false;
                                }
                            }
                        }
                    }
                    if(sub){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};