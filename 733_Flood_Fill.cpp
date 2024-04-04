class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size();
        int n=image[0].size();
        bool vis[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vis[i][j]=false;
            }
        }
        int vis_x[2500];
        int vis_y[2500];
        int left=0;
        int right=1;
        int prev_left;
        vis_x[0]=sr;
        vis_y[0]=sc;
        int color=image[sr][sc];
        while(left<right){
            for(int i=left;i<right;i++){
                image[vis_x[i]][vis_y[i]]=newColor;
                vis[vis_x[i]][vis_y[i]]=true;
            }
            prev_left=left;
            left=right;
            for(int i=prev_left;i<left;i++){
                if(vis_x[i]-1>=0 && vis[vis_x[i]-1][vis_y[i]]==false && image[vis_x[i]-1][vis_y[i]]==color){
                    vis_x[right]=vis_x[i]-1;
                    vis_y[right++]=vis_y[i];
                }
                if(vis_x[i]+1<m && vis[vis_x[i]+1][vis_y[i]]==false && image[vis_x[i]+1][vis_y[i]]==color){
                    vis_x[right]=vis_x[i]+1;
                    vis_y[right++]=vis_y[i];
                }
                if(vis_y[i]-1>=0 && vis[vis_x[i]][vis_y[i]-1]==false && image[vis_x[i]][vis_y[i]-1]==color){
                    vis_x[right]=vis_x[i];
                    vis_y[right++]=vis_y[i]-1;
                }
                if(vis_y[i]+1<n && vis[vis_x[i]][vis_y[i]+1]==false && image[vis_x[i]][vis_y[i]+1]==color){
                    vis_x[right]=vis_x[i];
                    vis_y[right++]=vis_y[i]+1;
                }
            }
        }
        return image;
    }
};