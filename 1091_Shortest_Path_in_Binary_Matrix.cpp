class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0){
            return -1;
        }
        bool vis[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    vis[i][j]=true;
                }
                else{
                    vis[i][j]=false;
                }
            }
        }
        int pos_x[10000];
        int pos_y[10000];
        pos_x[0]=0;
        pos_y[0]=0;
        int left=0;
        int right=1;
        int prev_left;
        int dist=1;
        bool reachable=false;
        while(left<right){
            for(int i=left;i<right;i++){
                if(pos_x[i]==n-1 && pos_y[i]==n-1){
                    reachable=true;
                    break;
                }
            }
            if(reachable)break;
            dist++;
            prev_left=left;
            left=right;
            for(int i=prev_left;i<left;i++){
                bool x_down,x_up,y_down,y_up;
                x_down=(pos_x[i]-1>=0);
                x_up=(pos_x[i]+1<n);
                y_down=(pos_y[i]-1>=0);
                y_up=(pos_y[i]+1<n);
                if(x_down && y_down && vis[pos_x[i]-1][pos_y[i]-1]==false){
                    pos_x[right]=pos_x[i]-1;
                    pos_y[right++]=pos_y[i]-1;
                    vis[pos_x[i]-1][pos_y[i]-1]=true;
                }
                if(x_down && vis[pos_x[i]-1][pos_y[i]]==false){
                    pos_x[right]=pos_x[i]-1;
                    pos_y[right++]=pos_y[i];
                    vis[pos_x[i]-1][pos_y[i]]=true;
                }
                if(x_down && y_up && vis[pos_x[i]-1][pos_y[i]+1]==false){
                    pos_x[right]=pos_x[i]-1;
                    pos_y[right++]=pos_y[i]+1;
                    vis[pos_x[i]-1][pos_y[i]+1]=true;
                }
                if(y_down && vis[pos_x[i]][pos_y[i]-1]==false){
                    pos_x[right]=pos_x[i];
                    pos_y[right++]=pos_y[i]-1;
                    vis[pos_x[i]][pos_y[i]-1]=true;
                }
                if(y_up && vis[pos_x[i]][pos_y[i]+1]==false){
                    pos_x[right]=pos_x[i];
                    pos_y[right++]=pos_y[i]+1;
                    vis[pos_x[i]][pos_y[i]+1]=true;
                }
                if(x_up && y_down && vis[pos_x[i]+1][pos_y[i]-1]==false){
                    pos_x[right]=pos_x[i]+1;
                    pos_y[right++]=pos_y[i]-1;
                    vis[pos_x[i]+1][pos_y[i]-1]=true;
                }
                if(x_up && vis[pos_x[i]+1][pos_y[i]]==false){
                    pos_x[right]=pos_x[i]+1;
                    pos_y[right++]=pos_y[i];
                    vis[pos_x[i]+1][pos_y[i]]=true;
                }
                if(x_up && y_up && vis[pos_x[i]+1][pos_y[i]+1]==false){
                    pos_x[right]=pos_x[i]+1;
                    pos_y[right++]=pos_y[i]+1;
                    vis[pos_x[i]+1][pos_y[i]+1]=true;
                }
            }
        }
        if(reachable){
            return dist;
        }
        else{
            return -1;
        }
    }
};