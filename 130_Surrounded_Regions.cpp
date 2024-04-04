class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        bool vis[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    vis[i][j]=true;
                }
                else{
                    vis[i][j]=false;
                }
            }
        }
        bool surrounded;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==false){
                    surrounded=true;
                    int pos_x[40000];
                    int pos_y[40000];
                    pos_x[0]=i;
                    pos_y[0]=j;
                    int left=0;
                    int right=1;
                    int prev_left;
                    vis[i][j]=true;
                    while(left<right){
                        prev_left=left;
                        left=right;
                        for(int k=prev_left;k<left;k++){
                            if(pos_x[k]-1>=0){
                                if(vis[pos_x[k]-1][pos_y[k]]==false){
                                    pos_x[right]=pos_x[k]-1;
                                    pos_y[right++]=pos_y[k];
                                    vis[pos_x[k]-1][pos_y[k]]=true;
                                }
                            }
                            else{
                                surrounded=false;
                            }
                            if(pos_x[k]+1<m){
                                if(vis[pos_x[k]+1][pos_y[k]]==false){
                                    pos_x[right]=pos_x[k]+1;
                                    pos_y[right++]=pos_y[k];
                                    vis[pos_x[k]+1][pos_y[k]]=true;
                                }
                            }
                            else{
                                surrounded=false;
                            }
                            if(pos_y[k]-1>=0){
                                if(vis[pos_x[k]][pos_y[k]-1]==false){
                                    pos_x[right]=pos_x[k];
                                    pos_y[right++]=pos_y[k]-1;
                                    vis[pos_x[k]][pos_y[k]-1]=true;
                                }
                            }
                            else{
                                surrounded=false;
                            }
                            if(pos_y[k]+1<n){
                                if(vis[pos_x[k]][pos_y[k]+1]==false){
                                    pos_x[right]=pos_x[k];
                                    pos_y[right++]=pos_y[k]+1;
                                    vis[pos_x[k]][pos_y[k]+1]=true;
                                }
                            }
                            else{
                                surrounded=false;
                            }
                        }
                    }
                    if(surrounded){
                        for(int k=0;k<right;k++){
                            board[pos_x[k]][pos_y[k]]='X';
                        }
                    }
                }
            }
        }
    }
};