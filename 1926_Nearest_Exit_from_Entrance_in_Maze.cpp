class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();
        bool vis[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(maze[i][j]=='+'){
                    vis[i][j]=true;
                }
                else{
                    vis[i][j]=false;
                }
            }
        }
        int pos_x[10000];
        int pos_y[10000];
        pos_x[0]=entrance[0];
        pos_y[0]=entrance[1];
        vis[pos_x[0]][pos_y[0]]=true;
        int left=0;
        int right=1;
        int prev_left;
        bool canExist=false;
        int sol=0;
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
                }
                else{
                    if(sol>0){
                        canExist=true;
                        break;
                    }
                }
                if(pos_x[i]+1<m){
                    if(vis[pos_x[i]+1][pos_y[i]]==false){
                        pos_x[right]=pos_x[i]+1;
                        pos_y[right++]=pos_y[i];
                        vis[pos_x[i]+1][pos_y[i]]=true;
                    }
                }
                else{
                    if(sol>0){
                        canExist=true;
                        break;
                    }
                }
                if(pos_y[i]-1>=0){
                    if(vis[pos_x[i]][pos_y[i]-1]==false){
                        pos_x[right]=pos_x[i];
                        pos_y[right++]=pos_y[i]-1;
                        vis[pos_x[i]][pos_y[i]-1]=true;
                    }
                }
                else{
                    if(sol>0){
                        canExist=true;
                        break;
                    }
                }
                if(pos_y[i]+1<n){
                    if(vis[pos_x[i]][pos_y[i]+1]==false){
                        pos_x[right]=pos_x[i];
                        pos_y[right++]=pos_y[i]+1;
                        vis[pos_x[i]][pos_y[i]+1]=true;
                    }
                }
                else{
                    if(sol>0){
                        canExist=true;
                        break;
                    }
                }
            }
            if(canExist)break;
            sol++;
        }
        if(canExist){
            return sol;
        }
        else{
            return -1;
        }
    }
};