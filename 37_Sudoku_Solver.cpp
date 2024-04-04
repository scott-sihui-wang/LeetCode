class Solution {
public:
    void solve(vector<vector<char> >& board,bool& solved){
        if(solved)return;
        int i;
        int j;
        bool flag=true;
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                if(board[i][j]=='.'){
                    flag=false;
                    break;
                }
            }
            if(flag==false){
                break;
            }
        }
        if(flag==true){
            solved=true;
            return;
        }
        else{
            bool sol_list[9];
            for(int k=0;k<9;k++){
                sol_list[k]=true;
            }
            for(int k=0;k<9;k++){
                if(board[i][k]!='.'){
                    sol_list[board[i][k]-'1']=false;
                }
                if(board[k][j]!='.'){
                    sol_list[board[k][j]-'1']=false;
                }
            }
            for(int k=(i/3)*3;k<=(i/3)*3+2;k++){
                for(int l=(j/3)*3;l<=(j/3)*3+2;l++){
                    if(board[k][l]!='.'){
                        sol_list[board[k][l]-'1']=false;
                    }
                }
            }
            for(int k=0;k<9;k++){
                if(solved==false && sol_list[k]==true){
                    board[i][j]='1'+k;
                    solve(board,solved);
                    if(solved==false){
                        board[i][j]='.';
                    }
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool solved=false;
        solve(board,solved);
    }
};