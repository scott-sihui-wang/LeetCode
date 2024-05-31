class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int cnt_O=0,cnt_X=0;
        int line_O=0,line_X=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]=='O'){
                    cnt_O++;
                }
                else if(board[i][j]=='X'){
                    cnt_X++;
                }
            }
        }
        if(!(cnt_X==cnt_O+1 || cnt_X==cnt_O))return false;
        if(board[0][0]=='X' && board[0][1]=='X' && board[0][2]=='X')line_X++;
        if(board[1][0]=='X' && board[1][1]=='X' && board[1][2]=='X')line_X++;
        if(board[2][0]=='X' && board[2][1]=='X' && board[2][2]=='X')line_X++;
        if(board[0][0]=='X' && board[1][0]=='X' && board[2][0]=='X')line_X++;
        if(board[0][1]=='X' && board[1][1]=='X' && board[2][1]=='X')line_X++;
        if(board[0][2]=='X' && board[1][2]=='X' && board[2][2]=='X')line_X++;
        if(board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='X')line_X++;
        if(board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='X')line_X++;
        if(board[0][0]=='O' && board[0][1]=='O' && board[0][2]=='O')line_O++;
        if(board[1][0]=='O' && board[1][1]=='O' && board[1][2]=='O')line_O++;
        if(board[2][0]=='O' && board[2][1]=='O' && board[2][2]=='O')line_O++;
        if(board[0][0]=='O' && board[1][0]=='O' && board[2][0]=='O')line_O++;
        if(board[0][1]=='O' && board[1][1]=='O' && board[2][1]=='O')line_O++;
        if(board[0][2]=='O' && board[1][2]=='O' && board[2][2]=='O')line_O++;
        if(board[0][0]=='O' && board[1][1]=='O' && board[2][2]=='O')line_O++;
        if(board[0][2]=='O' && board[1][1]=='O' && board[2][0]=='O')line_O++;
        if((line_O==1 && line_X==0)||((line_X==1 || line_X==2) && line_O==0) || (line_X==0 && line_O==0)){
            if(line_O==1 && line_X==0 && cnt_O<cnt_X)return false;
            if(line_X>0 && line_O==0 && cnt_O==cnt_X)return false;
            return true;
        }
        else{
            return false;
        }
    }
};