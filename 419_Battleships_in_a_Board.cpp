class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    ans++;
                    if(j+1<n && board[i][j+1]=='X'){
                        int k=j;
                        while(k<n && board[i][k]=='X'){
                            board[i][k]='.';
                            k++;
                        }
                    }
                    else if(i+1<m && board[i+1][j]=='X'){
                        int k=i;
                        while(k<m && board[k][j]=='X'){
                            board[k][j]='.';
                            k++;
                        }
                    }    
                }
            }
        }
        return ans;
    }
};