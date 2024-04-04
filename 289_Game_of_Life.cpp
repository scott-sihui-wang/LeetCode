class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row=board.size();
        int col=board[0].size();
        int size=row*col;
        int pad[row+2][col+2];
        for(int i=0;i<row+2;i++){
            for(int j=0;j<col+2;j++){
                if(i==0 || j==0 || i==row+1 || j==col+1){
                    pad[i][j]=0;
                }
                else{
                    pad[i][j]=board[i-1][j-1];
                }
            }
        }
        int neighbor[row][col];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                neighbor[i][j]=pad[i][j]+pad[i][j+1]+pad[i][j+2]+pad[i+1][j]+pad[i+1][j+2]+pad[i+2][j]+pad[i+2][j+1]+pad[i+2][j+2];
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==1){
                    if(neighbor[i][j]<2 || neighbor[i][j]>3){
                        board[i][j]=0;
                    }
                }
                else{
                    if(neighbor[i][j]==3){
                        board[i][j]=1;
                    }
                }
            }
        }
    }
};