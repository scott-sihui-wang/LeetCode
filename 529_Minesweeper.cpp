class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x=click[0],y=click[1];
        char ch=board[x][y];
        int m=board.size(),n=board[0].size();
        int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        queue<pair<int,int>>pos;
        bool visited[m][n];
        memset(visited,false,sizeof(visited));
        if(ch=='M'){
            board[x][y]='X';
        }
        else if(ch=='E'){
            pos.push({x,y});
            visited[x][y]=true;
            while(!pos.empty()){
                x=pos.front().first;
                y=pos.front().second;
                pos.pop();
                int cnt=0;
                for(int i=0;i<8;i++){
                    int x0=x+dir[i][0],y0=y+dir[i][1];
                    if(x0>=0 && x0<m && y0>=0 && y0<n){
                        if(board[x0][y0]=='M'){
                            cnt++;
                        }
                    }
                }
                if(cnt==0){
                    board[x][y]='B';
                    for(int i=0;i<8;i++){
                        int x0=x+dir[i][0],y0=y+dir[i][1];
                        if(x0>=0 && x0<m && y0>=0 && y0<n){
                            if(board[x0][y0]=='E' && visited[x0][y0]==false){
                                pos.push({x0,y0});
                                visited[x0][y0]=true;
                            }
                        }
                    }
                }
                else{
                    board[x][y]=cnt+'0';
                }
            }
        }
        return board;
    }
};