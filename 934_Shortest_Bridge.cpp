class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        bool vis[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    vis[i][j]=true;
                }
                else{
                    vis[i][j]=false;
                }
            }
        }
        int idx=0;
        while(grid[idx/n][idx%n]==0){
            idx++;
        }
        int pos_x[10000];
        int pos_y[10000];
        int bound_x[10000];
        int bound_y[10000];
        int top=0;
        pos_x[0]=idx/n;
        pos_y[0]=idx%n;
        int left=0;
        int right=1;
        int prev_left;
        vis[pos_x[0]][pos_y[0]]=true;
        while(left<right){
            prev_left=left;
            left=right;
            for(int i=prev_left;i<left;i++){
                if(pos_x[i]-1>=0){
                    if(vis[pos_x[i]-1][pos_y[i]]==false){
                        pos_x[right]=pos_x[i]-1;
                        pos_y[right++]=pos_y[i];
                        vis[pos_x[i]-1][pos_y[i]]=true;
                    }
                    else if(grid[pos_x[i]-1][pos_y[i]]==0){
                        bound_x[top]=pos_x[i]-1;
                        bound_y[top++]=pos_y[i];
                    }
                }
                if(pos_x[i]+1<n){
                    if(vis[pos_x[i]+1][pos_y[i]]==false){
                        pos_x[right]=pos_x[i]+1;
                        pos_y[right++]=pos_y[i];
                        vis[pos_x[i]+1][pos_y[i]]=true;
                    }
                    else if(grid[pos_x[i]+1][pos_y[i]]==0){
                        bound_x[top]=pos_x[i]+1;
                        bound_y[top++]=pos_y[i];
                    }
                }
                if(pos_y[i]-1>=0){
                    if(vis[pos_x[i]][pos_y[i]-1]==false){
                        pos_x[right]=pos_x[i];
                        pos_y[right++]=pos_y[i]-1;
                        vis[pos_x[i]][pos_y[i]-1]=true;
                    }
                    else if(grid[pos_x[i]][pos_y[i]-1]==0){
                        bound_x[top]=pos_x[i];
                        bound_y[top++]=pos_y[i]-1;
                    }
                }
                if(pos_y[i]+1<n){
                    if(vis[pos_x[i]][pos_y[i]+1]==false){
                        pos_x[right]=pos_x[i];
                        pos_y[right++]=pos_y[i]+1;
                        vis[pos_x[i]][pos_y[i]+1]=true;
                    }
                    else if(grid[pos_x[i]][pos_y[i]+1]==0){
                        bound_x[top]=pos_x[i];
                        bound_y[top++]=pos_y[i]+1;
                    }
                }
            }
        }
        bool vis2[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                vis2[i][j]=false;
            }
        }
        for(int i=0;i<right;i++){
            vis2[pos_x[i]][pos_y[i]]=true;
        }
        for(int i=0;i<top;i++){
            vis2[bound_x[i]][bound_y[i]]=true;
        }
        int bottom=0;
        int prev_bottom;
        int dist=1;
        bool connected=false;
        while(bottom<top){
            prev_bottom=bottom;
            bottom=top;
            for(int i=prev_bottom;i<bottom;i++){
                if(bound_x[i]-1>=0 && vis2[bound_x[i]-1][bound_y[i]]==false){
                    if(grid[bound_x[i]-1][bound_y[i]]==0){
                        vis2[bound_x[i]-1][bound_y[i]]=true;
                        bound_x[top]=bound_x[i]-1;
                        bound_y[top++]=bound_y[i];
                    }
                    else{
                        connected=true;
                        break;
                    }
                }
                if(bound_x[i]+1<n && vis2[bound_x[i]+1][bound_y[i]]==false){
                    if(grid[bound_x[i]+1][bound_y[i]]==0){
                        vis2[bound_x[i]+1][bound_y[i]]=true;
                        bound_x[top]=bound_x[i]+1;
                        bound_y[top++]=bound_y[i];
                    }
                    else{
                        connected=true;
                        break;
                    }
                }
                if(bound_y[i]-1>=0 && vis2[bound_x[i]][bound_y[i]-1]==false){
                    if(grid[bound_x[i]][bound_y[i]-1]==0){
                        vis2[bound_x[i]][bound_y[i]-1]=true;
                        bound_x[top]=bound_x[i];
                        bound_y[top++]=bound_y[i]-1;
                    }
                    else{
                        connected=true;
                        break;
                    }
                }
                if(bound_y[i]+1<n && vis2[bound_x[i]][bound_y[i]+1]==false){
                    if(grid[bound_x[i]][bound_y[i]+1]==0){
                        vis2[bound_x[i]][bound_y[i]+1]=true;
                        bound_x[top]=bound_x[i];
                        bound_y[top++]=bound_y[i]+1;
                    }
                    else{
                        connected=true;
                        break;
                    }
                }
            }
            if(connected)break;
            dist++;
        }
        return dist;
    }
};