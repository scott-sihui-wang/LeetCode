class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int available[9];
        bool flag=true;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                available[j]=1;
            }
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    available[board[i][j]-'1']--;
                    if(available[board[i][j]-'1']<0){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag==false)break;
            for(int j=0;j<9;j++){
                available[j]=1;
            }
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    available[board[j][i]-'1']--;
                    if(available[board[j][i]-'1']<0){
                        flag=false;
                        break;
                    }
                }
            }
            if(flag==false)break;
            for(int j=0;j<9;j++){
                available[j]=1;
            }
            for(int j=(i/3)*3;j<=(i/3)*3+2;j++){
                for(int k=(i%3)*3;k<=(i%3)*3+2;k++){
                    if(board[j][k]!='.'){
                        available[board[j][k]-'1']--;
                        if(available[board[j][k]-'1']<0){
                            flag=false;
                            break;
                        }
                    }
                }
                if(flag==false)break;
            }
            if(flag==false)break;
        }
        return flag;
    }
};