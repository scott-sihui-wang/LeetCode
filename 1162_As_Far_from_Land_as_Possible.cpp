class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int dist[n][n];
        bool vis[n][n];
        int pos_x[10000];
        int pos_y[10000];
        int left=0;
        int right=0;
        int prev_left;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    vis[i][j]=true;
                    pos_x[right]=i;
                    pos_y[right++]=j;
                }
                else{
                    dist[i][j]=INT_MAX;
                    vis[i][j]=false;
                }
            }
        }
        int cur=0;
        while(left<right){
            cur++;
            prev_left=left;
            left=right;
            for(int i=prev_left;i<left;i++){
                if(pos_x[i]-1>=0 && vis[pos_x[i]-1][pos_y[i]]==false){
                    dist[pos_x[i]-1][pos_y[i]]=cur;
                    vis[pos_x[i]-1][pos_y[i]]=true;
                    pos_x[right]=pos_x[i]-1;
                    pos_y[right++]=pos_y[i];
                }
                if(pos_x[i]+1<n && vis[pos_x[i]+1][pos_y[i]]==false){
                    dist[pos_x[i]+1][pos_y[i]]=cur;
                    vis[pos_x[i]+1][pos_y[i]]=true;
                    pos_x[right]=pos_x[i]+1;
                    pos_y[right++]=pos_y[i];
                }
                if(pos_y[i]-1>=0 && vis[pos_x[i]][pos_y[i]-1]==false){
                    dist[pos_x[i]][pos_y[i]-1]=cur;
                    vis[pos_x[i]][pos_y[i]-1]=true;
                    pos_x[right]=pos_x[i];
                    pos_y[right++]=pos_y[i]-1;
                }
                if(pos_y[i]+1<n && vis[pos_x[i]][pos_y[i]+1]==false){
                    dist[pos_x[i]][pos_y[i]+1]=cur;
                    vis[pos_x[i]][pos_y[i]+1]=true;
                    pos_x[right]=pos_x[i];
                    pos_y[right++]=pos_y[i]+1;
                }
            }
        }
        if(cur<2){
            return -1;
        }
        else{
            return cur-1;
        }
    }
};
