class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int board[3][3];
        memset(board,0,sizeof(board));
        for(int i=0;i<moves.size();i++){
            if(i%2==0){
                board[moves[i][0]][moves[i][1]]=1;
            }
            else{
                board[moves[i][0]][moves[i][1]]=-1;
            }
        }
        if((board[0][0]==1 && board[0][1]==1 && board[0][2]==1)||(board[1][0]==1 && board[1][1]==1 && board[1][2]==1)||(board[2][0]==1 && board[2][1]==1 && board[2][2]==1)||(board[0][0]==1 && board[1][0]==1 && board[2][0]==1)||(board[0][1]==1 && board[1][1]==1 && board[2][1]==1)||(board[0][2]==1 && board[1][2]==1 && board[2][2]==1)||(board[0][0]==1 && board[1][1]==1 && board[2][2]==1)||(board[0][2]==1 && board[1][1]==1 && board[2][0]==1)){
            return string("A");
        }
        else if((board[0][0]==-1 && board[0][1]==-1 && board[0][2]==-1)||(board[1][0]==-1 && board[1][1]==-1 && board[1][2]==-1)||(board[2][0]==-1 && board[2][1]==-1 && board[2][2]==-1)||(board[0][0]==-1 && board[1][0]==-1 && board[2][0]==-1)||(board[0][1]==-1 && board[1][1]==-1 && board[2][1]==-1)||(board[0][2]==-1 && board[1][2]==-1 && board[2][2]==-1)||(board[0][0]==-1 && board[1][1]==-1 && board[2][2]==-1)||(board[0][2]==-1 && board[1][1]==-1 && board[2][0]==-1)){
            return string("B");
        }
        else if(board[0][0]!=0 && board[0][1]!=0 && board[0][2]!=0 && board[1][0]!=0 && board[1][1]!=0 && board[1][2]!=0 && board[2][0]!=0 && board[2][1]!=0 && board[2][2]!=0){
            return string("Draw");
        }
        else{
            return string("Pending");
        }
    }
};