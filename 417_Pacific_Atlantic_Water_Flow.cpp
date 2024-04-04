class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        bool vis_p[m][n];
        bool vis_a[m][n];
        int pos_x_p[40000];
        int pos_y_p[40000];
        int pos_x_a[40000];
        int pos_y_a[40000];
        int left_p=0;
        int right_p=0;
        int left_a=0;
        int right_a=0;
        int prev_left_p;
        int prev_left_a;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vis_p[i][j]=false;
                vis_a[i][j]=false;
            }
        }
        for(int i=0;i<m;i++){
            vis_p[i][0]=true;
            pos_x_p[right_p]=i;
            pos_y_p[right_p++]=0;
            vis_a[i][n-1]=true;
            pos_x_a[right_a]=i;
            pos_y_a[right_a++]=n-1;
        }
        for(int i=0;i<n;i++){
            vis_p[0][i]=true;
            pos_x_p[right_p]=0;
            pos_y_p[right_p++]=i;
            vis_a[m-1][i]=true;
            pos_x_a[right_a]=m-1;
            pos_y_a[right_a++]=i;
        }
        while(left_p<right_p){
            prev_left_p=left_p;
            left_p=right_p;
            for(int i=prev_left_p;i<left_p;i++){
                if(pos_x_p[i]-1>=0 && heights[pos_x_p[i]-1][pos_y_p[i]]>=heights[pos_x_p[i]][pos_y_p[i]] && vis_p[pos_x_p[i]-1][pos_y_p[i]]==false){
                    vis_p[pos_x_p[i]-1][pos_y_p[i]]=true;
                    pos_x_p[right_p]=pos_x_p[i]-1;
                    pos_y_p[right_p++]=pos_y_p[i];
                }
                if(pos_x_p[i]+1<m && heights[pos_x_p[i]+1][pos_y_p[i]]>=heights[pos_x_p[i]][pos_y_p[i]] && vis_p[pos_x_p[i]+1][pos_y_p[i]]==false){
                    vis_p[pos_x_p[i]+1][pos_y_p[i]]=true;
                    pos_x_p[right_p]=pos_x_p[i]+1;
                    pos_y_p[right_p++]=pos_y_p[i];
                }
                if(pos_y_p[i]-1>=0 && heights[pos_x_p[i]][pos_y_p[i]-1]>=heights[pos_x_p[i]][pos_y_p[i]] && vis_p[pos_x_p[i]][pos_y_p[i]-1]==false){
                    vis_p[pos_x_p[i]][pos_y_p[i]-1]=true;
                    pos_x_p[right_p]=pos_x_p[i];
                    pos_y_p[right_p++]=pos_y_p[i]-1;
                }
                if(pos_y_p[i]+1<n && heights[pos_x_p[i]][pos_y_p[i]+1]>=heights[pos_x_p[i]][pos_y_p[i]] && vis_p[pos_x_p[i]][pos_y_p[i]+1]==false){
                    vis_p[pos_x_p[i]][pos_y_p[i]+1]=true;
                    pos_x_p[right_p]=pos_x_p[i];
                    pos_y_p[right_p++]=pos_y_p[i]+1;
                }
            }
        }
        while(left_a<right_a){
            prev_left_a=left_a;
            left_a=right_a;
            for(int i=prev_left_a;i<left_a;i++){
                if(pos_x_a[i]-1>=0 && heights[pos_x_a[i]-1][pos_y_a[i]]>=heights[pos_x_a[i]][pos_y_a[i]] && vis_a[pos_x_a[i]-1][pos_y_a[i]]==false){
                    vis_a[pos_x_a[i]-1][pos_y_a[i]]=true;
                    pos_x_a[right_a]=pos_x_a[i]-1;
                    pos_y_a[right_a++]=pos_y_a[i];
                }
                if(pos_x_a[i]+1<m && heights[pos_x_a[i]+1][pos_y_a[i]]>=heights[pos_x_a[i]][pos_y_a[i]] && vis_a[pos_x_a[i]+1][pos_y_a[i]]==false){
                    vis_a[pos_x_a[i]+1][pos_y_a[i]]=true;
                    pos_x_a[right_a]=pos_x_a[i]+1;
                    pos_y_a[right_a++]=pos_y_a[i];
                }
                if(pos_y_a[i]-1>=0 && heights[pos_x_a[i]][pos_y_a[i]-1]>=heights[pos_x_a[i]][pos_y_a[i]] && vis_a[pos_x_a[i]][pos_y_a[i]-1]==false){
                    vis_a[pos_x_a[i]][pos_y_a[i]-1]=true;
                    pos_x_a[right_a]=pos_x_a[i];
                    pos_y_a[right_a++]=pos_y_a[i]-1;
                }
                if(pos_y_a[i]+1<n && heights[pos_x_a[i]][pos_y_a[i]+1]>=heights[pos_x_a[i]][pos_y_a[i]] && vis_a[pos_x_a[i]][pos_y_a[i]+1]==false){
                    vis_a[pos_x_a[i]][pos_y_a[i]+1]=true;
                    pos_x_a[right_a]=pos_x_a[i];
                    pos_y_a[right_a++]=pos_y_a[i]+1;
                }
            }
        }
        vector<vector<int> >sol;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis_p[i][j]==true && vis_a[i][j]==true){
                    vector<int> result;
                    result.push_back(i);
                    result.push_back(j);
                    sol.push_back(result);
                }
            }
        }
        return sol;
    }
};