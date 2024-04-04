class Solution {
public:
    void dfs(int px,int py,int m,int n,bool** vis,vector<vector<char> >& board,string& word,int cur,int len,bool& solved){
        if(solved==true)return;
        if(px-1>=0 && vis[px-1][py]==false && solved==false && board[px-1][py]==word[cur]){
            if(cur==len-1){
                solved=true;
            }
            else{
                vis[px-1][py]=true;
                dfs(px-1,py,m,n,vis,board,word,cur+1,len,solved);
                vis[px-1][py]=false;
            }
        }
        if(px+1<m && vis[px+1][py]==false && solved==false && board[px+1][py]==word[cur]){
            if(cur==len-1){
                solved=true;
            }
            else{
                vis[px+1][py]=true;
                dfs(px+1,py,m,n,vis,board,word,cur+1,len,solved);
                vis[px+1][py]=false;
            }
        }
        if(py-1>=0 && vis[px][py-1]==false && solved==false && board[px][py-1]==word[cur]){
            if(cur==len-1){
                solved=true;
            }
            else{
                vis[px][py-1]=true;
                dfs(px,py-1,m,n,vis,board,word,cur+1,len,solved);
                vis[px][py-1]=false;
            }
        }
        if(py+1<n && vis[px][py+1]==false && solved==false && board[px][py+1]==word[cur]){
            if(cur==len-1){
                solved=true;
            }
            else{
                vis[px][py+1]=true;
                dfs(px,py+1,m,n,vis,board,word,cur+1,len,solved);
                vis[px][py+1]=false;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int len=word.length();
        int m=board.size();
        int n=board[0].size();
        bool** vis;
        vis=new bool*[m];
        for(int i=0;i<m;i++){
            vis[i]=new bool[n];
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vis[i][j]=false;
            }
        }
        int start_pos_x[36];
        int start_pos_y[36];
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    start_pos_x[cnt]=i;
                    start_pos_y[cnt++]=j;
                }
            }
        }
        if(cnt==0){
            return false;
        }
        else if(len==1){
            return true;
        }
        bool solved=false;
        for(int i=0;i<cnt;i++){
            vis[start_pos_x[i]][start_pos_y[i]]=true;
            dfs(start_pos_x[i],start_pos_y[i],m,n,vis,board,word,1,len,solved);
            if(solved==true)return solved;
            vis[start_pos_x[i]][start_pos_y[i]]=false;
        }
        return solved;
    }
};