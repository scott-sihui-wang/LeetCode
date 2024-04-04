class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        bool vis[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    vis[i][j]=true;
                }
                else{
                    vis[i][j]=false;
                }
            }
        }
        int sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==false){
                    int cnt=1;
                    bool valid=false;
                    int pos_x[250000];
                    int pos_y[250000];
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
                            if(pos_x[k]-1>=0){
                                if(vis[pos_x[k]-1][pos_y[k]]==false){
                                    pos_x[right]=pos_x[k]-1;
                                    pos_y[right++]=pos_y[k];
                                    vis[pos_x[k]-1][pos_y[k]]=true;
                                    cnt++;
                                }
                            }
                            else{
                                valid=true;
                            }
                            if(pos_x[k]+1<m){
                                if(vis[pos_x[k]+1][pos_y[k]]==false){
                                    pos_x[right]=pos_x[k]+1;
                                    pos_y[right++]=pos_y[k];
                                    vis[pos_x[k]+1][pos_y[k]]=true;
                                    cnt++;
                                }
                            }
                            else{
                                valid=true;
                            }
                            if(pos_y[k]-1>=0){
                                if(vis[pos_x[k]][pos_y[k]-1]==false){
                                    pos_x[right]=pos_x[k];
                                    pos_y[right++]=pos_y[k]-1;
                                    vis[pos_x[k]][pos_y[k]-1]=true;
                                    cnt++;
                                }
                            }
                            else{
                                valid=true;
                            }
                            if(pos_y[k]+1<n){
                                if(vis[pos_x[k]][pos_y[k]+1]==false){
                                    pos_x[right]=pos_x[k];
                                    pos_y[right++]=pos_y[k]+1;
                                    vis[pos_x[k]][pos_y[k]+1]=true;
                                    cnt++;
                                }
                            }
                            else{
                                valid=true;
                            }
                        }
                    }
                    if(!valid){
                        sum+=cnt;
                    }
                }
            }
        }
        return sum;
    }
};