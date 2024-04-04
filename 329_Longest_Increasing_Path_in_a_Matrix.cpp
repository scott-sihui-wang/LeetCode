class Solution {
public:
    void solve(int pos_x,int pos_y,int m,int n,vector<vector<int> >&matrix,int& max_len,int** prev_sol){
        int cnt=0;
        if(pos_x-1>=0 && matrix[pos_x-1][pos_y]>matrix[pos_x][pos_y]){
            if(prev_sol[pos_x-1][pos_y]==0){
                solve(pos_x-1,pos_y,m,n,matrix,max_len,prev_sol);
            }
            prev_sol[pos_x][pos_y]=max(prev_sol[pos_x][pos_y],prev_sol[pos_x-1][pos_y]+1);
            max_len=max(max_len,prev_sol[pos_x][pos_y]);
            cnt++;
        }
        if(pos_x+1<m && matrix[pos_x+1][pos_y]>matrix[pos_x][pos_y]){
            if(prev_sol[pos_x+1][pos_y]==0){
                solve(pos_x+1,pos_y,m,n,matrix,max_len,prev_sol);    
            }
            prev_sol[pos_x][pos_y]=max(prev_sol[pos_x][pos_y],prev_sol[pos_x+1][pos_y]+1);
            max_len=max(max_len,prev_sol[pos_x][pos_y]);
            cnt++;
        }
        if(pos_y-1>=0 && matrix[pos_x][pos_y-1]>matrix[pos_x][pos_y]){
            if(prev_sol[pos_x][pos_y-1]==0){
                solve(pos_x,pos_y-1,m,n,matrix,max_len,prev_sol);
            }
            prev_sol[pos_x][pos_y]=max(prev_sol[pos_x][pos_y],prev_sol[pos_x][pos_y-1]+1);
            max_len=max(max_len,prev_sol[pos_x][pos_y]);
            cnt++;
        }
        if(pos_y+1<n && matrix[pos_x][pos_y+1]>matrix[pos_x][pos_y]){
            if(prev_sol[pos_x][pos_y+1]==0){
                solve(pos_x,pos_y+1,m,n,matrix,max_len,prev_sol);
            }
            prev_sol[pos_x][pos_y]=max(prev_sol[pos_x][pos_y],prev_sol[pos_x][pos_y+1]+1);
            max_len=max(max_len,prev_sol[pos_x][pos_y]);
            cnt++;
        }
        if(cnt==0){
            prev_sol[pos_x][pos_y]=1;
            max_len=max(max_len,1);
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int max_len=0;
        int** prev_sol;
        prev_sol=new int*[m];
        for(int i=0;i<m;i++){
            prev_sol[i]=new int[n];
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                prev_sol[i][j]=0;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                solve(i,j,m,n,matrix,max_len,prev_sol);
            }
        }
        return max_len;
    }
};